#include "../TechnicalIndicator/TechnicalIndicator.hpp"
#include <torch/torch.h>

using namespace std;

int main(){
     torch::Tensor input = torch::randn({50});
     torch::Tensor output =  TechnicalIndicator::MovingAverage(input,5);
     cout<<output;
}