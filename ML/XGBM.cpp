#include <xgboost/c_api.h>

const float * XGBR  (float Data[5] ){
          BoosterHandle XGBsave ;          
          const char* BoostPath = "./BestXGBoost";
          XGBoosterCreate(NULL,0,&XGBsave);
          XGBoosterLoadModel(XGBsave,BoostPath);
          const float *f;
          DMatrixHandle predict;
          XGDMatrixCreateFromMat((float *) Data, 1,5, -1, &predict);
          bst_ulong out_len;
          const float *out;
          XGBoosterPredict(XGBsave,predict,0,0,0,&out_len,&out);
          return out;
     }



void TrainingXGBR(float (* trainvalues)[5] , float* train_labels,int iters){
          BoosterHandle XGBsave ;
          
          DMatrixHandle Data[1];

          XGDMatrixCreateFromMat((float *) trainvalues,sizeof(trainvalues), 5, -1, &Data[0]);
          bst_ulong bst_result;
          XGDMatrixSetFloatInfo(Data[0], "label" , train_labels,sizeof(trainvalues) );
          const char* BoostPath = "./BestXGBoost";
          XGBoosterCreate(Data, 1, &XGBsave);
          XGBoosterSetParam(XGBsave, "booster", "gblinear");
          XGBoosterSetParam(XGBsave, "learning_rate", "0.05");
          XGBoosterSetParam(XGBsave, "objective", "reg:linear");
          XGBoosterSetParam(XGBsave, "max_depth", "512");
          XGBoosterSetParam(XGBsave, "eta", "0.1");
          XGBoosterSetParam(XGBsave, "min_child_weight", "1");
          XGBoosterSetParam(XGBsave, "subsample", "0.65");
          XGBoosterSetParam(XGBsave, "colsample_bytree", "1");
          XGBoosterSetParam(XGBsave, "num_parallel_tree", "1");
          for (int iter=0; iter<iters; iter++)
              XGBoosterUpdateOneIter(XGBsave, iter, Data[0]);
          XGBoosterSaveModel(XGBsave,BoostPath);
          return ;
} 