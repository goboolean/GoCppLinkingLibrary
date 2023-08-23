#include "../TechnicalIndicator/TechnicalIndicator.h"
#include <torch/torch.h>

using namespace std;

int main(){
     torch::Tensor input = torch::randn({50,1});
     torch::Tensor output =  TechnicalIndicator::MovingAverage(input,5);
     cout<<output;
}