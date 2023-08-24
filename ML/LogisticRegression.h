#define __BaseFunction__
#include <torch/torch.h>

torch::Tensor LogisiticRegression  (torch::Tensor Data,  std::string load_link );
void TrainingLogisitcRegression  (torch::Tensor testing_data, std::string load_link);