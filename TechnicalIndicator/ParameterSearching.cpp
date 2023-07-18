#include <torch/torch.h>
#include <torch/script.h>
#include <iostream>
#include <GoCppLinkingLibrary/TechnicalIndicator/TechnicalIndicator.hpp>


namespace ParametricSearch{
     namespace{
          int FindBestRSIValue(torch::Tensor ClosePrice){
               const int MomentCoefficient= 5;
               int BestBuy=30 , BestSell =70, Bestinterval =14 ,BestResult =0;
               for(int t= 2; t<=50; t++){
               torch::Tensor result = TechnicalIndicator::RSI(ClosePrice,t)
               for (int BuyMoment = 1;BuyMoment <= 9;BuyMoment++){
                 for (int SellMoment = 11;SellMoment <= 19;SellMoment++){
                     int TradingProfit =0,TradeCount =0,BuyingPrice;
                     bool TradeCondition =false;

                    for(int Times=t-1; Times <= result.size(0)-t;Times++){
                         if(result[Times].item() <= BuyMoment*MomentCoefficient && TradeCondition == false){
                              TradeCondition = true;
                              BuyingPrice = int(ClosePrice[Times].item());
                              TradeCount++;
                         }
                         else if(result[Times] >= SellMoment*MomentCoefficient && TradeCondition == true){
                              TradeCondition = false;
                              TradingProfit += int(ClosePrice[Times].item()) - BuyingPrice;
                         }
                    }
                    TradingProfit/=TradeCount;
                    if (TradingProfit >= BestResult){
                         BestResult = TradingProfit;
                         BestBuy = BuyMoment * MomentCoefficient;
                         BestSell = SellMoment * MomentCoefficient;
                         Bestinterval = t;
                    }
                    }
               }
               }
           return BestBuy,BestSell,Bestinterval,BestResult;
          }
          int FindBestBollingerBandValue(torch::Tensor ClosePrice){
               const int MomentCoefficient= 5;
               int BestInterval,BestTickDown,BestBuy,BestSell,BestResult=0;
          
               for(int t= 2; t<=50; t++){
                    torch::Tensor BollingerUp,MA, BollingerDown = TechnicalIndicator::BollingerBand(ClosePrice,t);
                    for (int TickDown =10; TickDown>=1;TickDown--){
                    for (int BuyMoment = 0;BuyMoment <= 8;BuyMoment++){
                       for (int SellMoment = 0;SellMoment <= 8;SellMoment++){
                         bool TradeCondition =false;
                         int TradingProfit =0,TradeCount =0,BuyingPrice;

                     for(int iter =t-1; iter<= ClosePrice.size(0)-t; iter++ ){
                       if (TradeCondition == false && BollingerDown[iter].item()*(80+MomentCoefficient*BuyMoment)/100>= ClosePrice[iter].item()){
                          TradeCondition =true;
                          TradeCount++;
                          BuyingPrice = ClosePrice[iter].item();
                          
                       }
                        else if(BollingerBand[iter].item()*(80+MomentCoefficient*SellMoment) >= ClosePrice[iter].item() && TradeCondition == true ){
                              TickDown--;
                        }
                        else if(MA[iter].item() && TradeCondition == true && TickDown ==0){
                              TradeCondition = false;
                              TradingProfit += int(ClosePrice[iter].item()) - BuyingPrice;
                         }
                    }
                    }  
                    }
               }
               TradingProfit/=TradeCount;
               if (TradingProfit>=BestResult){
                    BestResult= TradingProfit;
                    BestInterval = t;
                    BestTickDown = TickDown;
                    BestBuy = 80+BuyMoment*MomentCoefficient;
                    BestSell = 80+SellMoment*MomentCoefficient;
               }
               }
            return BestBuy,BestSell,BestTickDown,BestResult,BestInterval;
          }
          int FindBestGoldenDeadCross(torch::Tensor ClosePrice){
               int BestMove, BestSupport,BestResult =0;
               for(int move=2;move<=10;move++){
                    int TradingProfit =0,TradeCount =0,BuyingPrice;
                  for(int support=20;support<=40;support++){
                    bool TradeCondition =false;

                    torch::Tensor MovingLine = TechnicalIndicator::MovingAverage(ClosePrice,move);
                    torch::Tensor SupportLine = TechnicalIndicator::MovingAverage(ClosePrice,support);
                    for(int iter = support-1;iter<=ClosePrice.size(0)-support;iter++){
                        if(MovingLine[iter].item()>=SupportLine[iter].item() && TradeCondition ==false){
                          TradeCondition =true;
                          TradeCount++;
                          BuyingPrice = ClosePrice[iter].item();
                        }
                        else if(MovingLine[iter].item()>=SupportLine[iter].item() && TradeCondition ==true){
                          TradeCondition =false;
                          TradingProfit += int(ClosePrice[iter].item()) - BuyingPrice;
                        }
                    }
                   }
                   TradingProfit/=TradeCount;
               if (TradingProfit>=BestResult){
                    BestResult= TradingProfit;
                    BestSupport = support;
                    BestMove = move;
               }
               }
            return BestResult, BestSupport, BestMove;
            int FindBestKDJ(torch::Tensor ClosePrice,torch::Tensor HighPrice,torch::Tensor LowPrice){
               int BestMove, BestInterval,BestSpan =0;
               for(int Span = 2; Span<=20;Span++){
                    int TradingProfit =0,TradeCount =0,BuyingPrice;
                    for(int interval = 4; interval<=30;interval++){     
                     torch::Tensor PercentK,PercentD,PercentJ = TechnicalIndicator::KDJ(ClosePrice,HighPrice,LowPrice,interval,Span);
                    }
                    if(PercentJ[] >= 0)

               }
            }
          }


     }
}