/* 5개의 상승파, 3개의 하락파
   1. 상승시장에서 상승하는 파도는 Impulse Wave 라고 일컫으며, 교정하는 파동은 Corrective Wave라고 부른다.
   2. 하강시장에서 하강하는 파동은 충격파, 상승하는 파동은 교정파라 부른다.
   3. 여러 차트들에는 사이클이 존재한다. 이를 표현한 것을 Fractal이라고 부른다.
   4. 충격파에선 연장파가 발생한다.

*/
#include <torch/torch.h>

torch::Tensor ElliotWavePatterning(torch::Tensor CloseData,int Terms[5]){
    for(int iter=0;iter<int(CloseData.sizes()[0]/2);iter++)
   

  return PatternizedData;
}