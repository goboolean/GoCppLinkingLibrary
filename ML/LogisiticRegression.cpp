#include <torch/torch.h>

torch::Tensor LogisiticRegression  (torch::Tensor Data ){
          torch::nn::Sequential LogisiticModel(
         torch::nn::Linear(5,1),
         torch::nn::Sigmoid()
          );
          torch::load(LogisiticModel,"./bestlogistic.pt");
          return torch::softmax(LogisiticModel->forward(Data),1);
     }

void TrainingLogisitcRegression  (torch::Tensor testing_data){
          torch::nn::Sequential LogisiticModel(
         torch::nn::Linear(5,1),
         torch::nn::Sigmoid()
          );
          
          auto optim =  torch::optim::Adam(LogisiticModel->parameters(), torch::optim::AdamOptions(2e-4).betas(std::make_tuple (0.5, 0.5)));
             for(int i=0;i<5;i++){
              for(int iter=0;iter<testing_data.sizes()[0]-1;iter++){
                  torch::Tensor result = LogisiticModel->forward(testing_data[i]);
                  auto output = torch::smooth_l1_loss(result, testing_data[i+1]);
                  output.backward();
                  optim.step();
              } 
             }
          torch::save(LogisiticModel,"./bestlogistic.pt");

}

