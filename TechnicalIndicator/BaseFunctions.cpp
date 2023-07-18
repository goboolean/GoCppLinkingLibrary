#include <torch/torch.h>

namespace BaseFunction{
     namespace{
     torch::Tensor ExponentialWeightMovingAverage(torch::Tensor Chart, float PeriodalInterval ){
        float alpha = 1/ PeriodalInterval;
        torch::Tensor EWM =  torch::zeros({Chart.size(0)-PeriodalInterval,Chart.size(1)});
        for(int iter= 0; iter<Chart.size(0)-PeriodalInterval;iter++)
           EWM[iter] = Chart[iter-1]*(1-alpha) + alpha * Chart[iter];
     return EWM;
     }
    torch::Tensor RollingTensor(torch::Tensor Chart, int PeriodalInterval){ 
          torch::Tensor Rolling =  torch::ones({Chart.size(0),PeriodalInterval});
          for(int iter= 0; iter<Chart.size(0)-PeriodalInterval;iter++)
            Rolling[iter+PeriodalInterval-1] =  Price.index({Slice(0+iter,PeriodalInterval+iter)});
          
      return Rolling;
     }
     torch::Tensor TensorDifference(torch::Tensor Price){
          return Price.index({Slice(1,Price.size(0))}) - Price.index({Slice(0,Price.size(0)-1)});
     }
     }
}
