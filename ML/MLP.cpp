#include <torch/torch.h>


torch::Tensor MLP(torch::Tensor Data ){
          torch::nn::Sequential MLP(
         torch::nn::Linear(5,20),
         torch::nn::GELU(),
         torch::nn::BatchNorm1d(20),
         torch::nn::Linear(20,80),
         torch::nn::GELU(),
         torch::nn::BatchNorm1d(80),
         torch::nn::GELU(),
         torch::nn::Linear(80,10),
         torch::nn::Linear(10,1),
         torch::nn::Sigmoid()
          );
          torch::load(MLP,"./bestMLP.pt");
          return torch::softmax(MLP->forward(Data),1);
     }

void TrainingLogisitcRegression  (torch::Tensor testing_data){
              torch::nn::Sequential MLP(
         torch::nn::Linear(5,20),
         torch::nn::GELU(),
         torch::nn::BatchNorm1d(20),
         torch::nn::Linear(20,80),
         torch::nn::GELU(),
         torch::nn::BatchNorm1d(80),
         torch::nn::GELU(),
         torch::nn::Linear(80,10),
         torch::nn::Linear(10,1),
         torch::nn::Sigmoid()
          );
             auto optim =  torch::optim::Adam(MLP->parameters(), torch::optim::AdamOptions(2e-4).betas(std::make_tuple (0.5, 0.5)));
             for(int i=0;i<5;i++){
              for(int iter=0;iter<testing_data.sizes()[0]-1;iter++){
                  torch::Tensor result = MLP->forward(testing_data[i]);
                  auto output = torch::smooth_l1_loss(result, testing_data[i+1]);
                  output.backward();
                  optim.step();
              } 
             }
             torch::save(MLP,"./bestMLP.pt");

          }

