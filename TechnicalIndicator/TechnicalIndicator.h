#define __TechIndicator__
#include <torch/torch.h>
#include <torch/script.h>
#include "BaseFunctions.h"


namespace TechnicalIndicator{
 torch::Tensor MovingAverage(torch::Tensor ClosePrice, int TimeInterval );
 torch::Tensor RSI(torch::Tensor ClosePrice, int PeriodalInterval );
 std::vector<torch::Tensor> BollingerBand(torch::Tensor ClosePrice, int TimeInterval);
 std::vector<torch::Tensor> KDJ(torch::Tensor ClosePrice,torch::Tensor HighPrice,torch::Tensor LowPrice,int TimeInterval,int Span );
 torch::Tensor MACD(torch::Tensor ClosePrice, int SlowInterval, int FastInterval);
}
