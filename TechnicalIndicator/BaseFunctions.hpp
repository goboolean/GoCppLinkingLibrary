#ifndef __BaseFunction__
#include <torch/torch.h>

namespace BaseFunction{
        torch::Tensor ExponentialWeightMovingAverage(torch::Tensor Chart, float PeriodalInterval );
    torch::Tensor RollingTensor(torch::Tensor Chart, int PeriodalInterval);
     torch::Tensor TensorDifference(torch::Tensor Price);             
}

#endif