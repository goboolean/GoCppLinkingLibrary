#include <fstream>
#include "../ML/LogisticRegression.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <torch/torch.h>
#include<array>
using namespace std;
vector<float> linearize(const vector<vector<float>>& vec_vec) {
    vector<float> vec;
    for (const auto& v : vec_vec) {
        for (auto d : v) {
            vec.push_back(d);
        }
    }
    return vec;
}
vector<string> StringSplit(string str, char Delimiter) {
    istringstream iss(str);             // istringstream에 str을 담는다.
    string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼
 
    vector<string> result;
 
    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    }
 
    return result;
}

int main(){
 
     FILE *pFile = NULL;
     vector<vector<float>> chunker;
     pFile = fopen("/home/jepetolee/GoCppLinkingLibrary/test/BTCUSDT_1D.csv","r");
       
     char str_tmp[1024];
     int Index=0;
     while( !feof( pFile )) {
     fgets( str_tmp, 1024, pFile );  //23456
     string chunk(str_tmp);

     vector<string> chunks =  StringSplit(chunk,',');
      chunker.push_back(vector<float>());
      for(int index=2;index<7;index++)
       chunker[Index].push_back(stof(chunks[index])) ;
     Index++;
     }
     chunker.erase(chunker.begin());
     int ArrSize = chunker.size();
     float ArrSave[ArrSize][5];
     for (int i=0;i<ArrSize;i++)
        for (int j=0;j<5;j++)
           ArrSave[i][j] = chunker[i][j];
     torch::Tensor Data = torch::from_blob(ArrSave,{ArrSize,5},torch::kF32);
     string link = "LogisticRegression.pt";
     TrainingLogisitcRegression (Data, link);
  
     cout<<LogisiticRegression(Data[100].reshape({-1,5}),link)[0];
    return 0;
}
