#include <torch/torch.h>
#include <torch/script.h>


namespace TechnicalIndicator{
     namespace{
 torch::Tensor MovingAverage(torch::Tensor ClosePrice, int TimeInterval );
 torch::Tensor RSI(torch::Tensor ClosePrice, int PeriodalInterval );
 torch::Tensor BollingerBand(torch::Tensor ClosePrice, int TimeInterval);
 torch::Tensor KDJ(torch::Tensor ClosePrice,torch::Tensor HighPrice,torch::Tensor LowPrice,int TimeInterval,int Span );
 torch::Tensor MACD(torch::Tensor ClosePrice, int SlowInterval, int FastInterval);
 torch::Tensor LinearRegression(torch::Tensor ClosePrice,const char * weight[],const char * bias[]);
     }
}