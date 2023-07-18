/*
  Rules That Tensor Inputs.
  example:
     tensor =  [
                {1,1,1},
                {1,1,1},
                {1,1,1}
               ]
     tensor.size(0) = times 
     tensor.size(1) = 5 (open,close,max,min,volume)  ===> (0,1,2,3,4)

*/
#include <torch/torch.h>
#include <torch/script.h>


#include <GoCppLinkingLibrary/TechnicalIndicator/TechnicalIndicator.hpp>
#include <GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.hpp>


using torch::indexing::Slice;
using torch::indexing::None;
using torch::indexing::Ellipsis;


namespace TechnicalIndicator{
     namespace{
          torch::Tensor MovingAverage(torch::Tensor ClosePrice, int TimeInterval ){
             torch::Tensor  movingAverage =  torch::ones({ClosePrice.size(0),ClosePrice.size(1)});
             for(int iter =0; iter<= ClosePrice.size(0)-TimeInterval; iter++ )
                movingAverage[iter+TimeInterval-1][0] = ClosePrice.index({Slice(0+iter,TimeInterval+iter)}).sum/TimeInterval;

              return movingAverage;
          }
          

          torch::Tensor RSI(torch::Tensor ClosePrice, int PeriodalInterval ){

             torch::Tensor Passing14 =   ClosePrice.index({Slice(PeriodalInterval,ClosePrice.size(0))})
             torch::Tensor Difference = BaseFunction::TensorDifference(Passing14);
             torch::Tensor Zeros =  torch::zeros({ClosePrice.size(0)-PeriodalInterval,ClosePrice.size(1)});

             torch::Tensor UpperDifference=  torch::where(Difference>0,Difference,Zeros);
             torch::Tensor LowerDifference=  torch::where(Difference<0,Difference,Zeros).abs();
            
             torch::Tensor UpperEWM = BaseFunction::ExponentialWeightMovingAverage( UpperDifference,  float(PeriodalInterval) ).mean() ;
             torch::Tensor LowerEWM = BaseFunction::ExponentialWeightMovingAverage( LowerDifference,  float(PeriodalInterval) ).mean() ;
             torch:: Tensor RS =  UpperEWM/LowerEWM;

             tensor::Tensor RSI = 100 - (100/1+RS);
             
             return RSI;
          }
          torch::Tensor BollingerBand(torch::Tensor ClosePrice, int TimeInterval){
             torch::Tensor movingAverage = MovingAverage(ClosePrice,TimeInterval );
             torch::Tensor standardDeviation = BaseFunction::RollingTensor(ClosePrice, TimeInterval).std(1);

             torch::Tensor BollingerBandUpper = movingAverage + 2*standardDeviation;
             torch::Tensor BollingerBandLower = movingAverage -2*standardDeviation;

             return BollingerBandUpper,movingAverage,BollingerBandLower;
          }
          torch::Tensor KDJ(torch::Tensor ClosePrice,torch::Tensor HighPrice,torch::Tensor LowPrice,int TimeInterval,int Span ){
              torch::Tensor HighInDays =BaseFunction::RollingTensor(HighPrice, TimeInterval).max(1);
              torch::Tensor LowInDays =BaseFunction::RollingTensor(LowPrice, TimeInterval).max(1);
              torch::Tensor PeriodRSV = 100 * (ClosePrice - LowPrice) / (HighInDays - LowInDays);
              torch::Tensor  PercentK = BaseFunction::ExponentialWeightMovingAverage(UpperDifference,  float ((Span+1)/2)).mean(0);
              torch::Tensor PercentD = BaseFunction::ExponentialWeightMovingAverage(PercentK,  float ((Span+1)/2)).mean(0);
              torch::Tensor PercentJ = 3 * PercentK - 2 * PercentD;
              return PercentK,PercentD,PercentJ;
          }
          torch::Tensor MACD(torch::Tensor ClosePrice, int SlowInterval, int FastInterval){
            torch::Tensor  Exp1 = BaseFunction::ExponentialWeightMovingAverage(ClosePrice,  float (FastInterval).mean(0);
            torch::Tensor  Exp2 = BaseFunction::ExponentialWeightMovingAverage(ClosePrice,  float (SlowInterval).mean(0);
            torch::Tensor MACD =  Exp1- Exp2;
            return MACD;
          }
          torch::Tensor LinearRegression(torch::Tensor ClosePrice,const char * weight[],const char * bias[]){
            try{
               torch::Tensor  Weight = torch::jit::load(weight[1]);
            }
            catch (const c10::Error& e) {
               std::cerr << "error loading the wieght, there's no acceptable PT file on "<<weight[1]<<"\n";
               return -1;
            }
            
            try{
               torch::Tensor  Bias = torch::jit::load(bias[1]);
            }
            catch (const c10::Error& e) {
               std::cerr << "error loading the bias, there's no acceptable PT file on "<<bias[1]<<"\n";
               return -1;
            }

            return Weight * ClosePrice + Bias;
          }

     }
}