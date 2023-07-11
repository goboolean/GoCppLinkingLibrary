# 프로젝트 Worker의 실행파일 목록
<img src="./main.png">
#### *Read this in other languages: [to English](README.eng.md)

## Architecture
<img src="./architecture.png">

## PPO
#### ● 방향키 조절에 대한 알고리즘은 해당 게임이 Grid World 라는 것을 감안하여 레벨업, 상자 획득과 기본 시간 생존을 양수 값으로 설정하였고, 죽는 화면 근처 행동값에 대한 보상에 음수 값을 추가 하였다.
#### ● Grid World를 탐색하는 알고리즘 중에 2017년도에 공개된  PPO(Proximal Policy Optimization)는 이전 행동과 현재 행동을 비교하여 loss값을 구성하는 알고리즘으로 Grid World 학습에 낮은 Episode를 적용해도 뛰어난 학습 성능을 보여줬다.
#### ● 위 게임의 특성상 training 1 episode에 시작할때 2 ~ 3분정도가 최저치이고 20 ~ 30분 정도가 최대치이다. 
#### ● 그렇기에 최소한의 episode로 높은 효율을 내는 알고리즘이 필요했고 model based 중 비교적 덜 최신이긴 하지만 뛰어난 성능을 갖춘 PPO를 도입했다.
#### 또, LSTM을 추가하여 동기식 A2C 모델로 구성해 더 나은 시간적 데이터에 대한 반응을 갖게 설계했다.
