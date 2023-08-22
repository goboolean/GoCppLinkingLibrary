#include <torch/torch.h>
#include "BaseFunctions.hpp"
namespace BaseFunction{
     torch::Tensor ExponentialWeightMovingAverage(torch::Tensor Chart, long PeriodalInterval ){
        float alpha = 1/ PeriodalInterval;
        torch::Tensor EWM =  torch::zeros({Chart.size(0)-PeriodalInterval,Chart.size(1)});
        for(int iter= 0; iter<Chart.size(0)-PeriodalInterval;iter++)
           EWM[iter] = Chart[iter-1]*(1-alpha) + alpha * Chart[iter];
     return EWM;
     }
    torch::Tensor RollingTensor(torch::Tensor Chart, int PeriodalInterval){ 
          torch::Tensor Rolling =  torch::ones({Chart.size(0),PeriodalInterval});
          for(int iter= 0; iter<Chart.size(0)-PeriodalInterval;iter++)
            Rolling[iter+PeriodalInterval-1] =  Chart.slice(0+iter,PeriodalInterval+iter);
          
      return Rolling;
     }
     torch::Tensor TensorDifference(torch::Tensor Price){
          return Price.slice(1,Price.size(0)) - Price.slice(0,Price.size(0)-1);
     }
}
