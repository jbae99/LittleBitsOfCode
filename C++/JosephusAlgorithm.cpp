#include <iostream>
#include <queue>

int* strikeout(int n, int k, int s);

int main() {
  const int REM_SURV = 2;
  //strikeout(7,1,2);
  //strikeout(7, 4, 3);
  //strikeout(24, 13, 5);
  //classic Josephus Problem
  int* survivors = strikeout(41, 1, 2);
  for(int i = 0;i < REM_SURV; i++){
    std::cout << survivors[i] << " Survived!" << std::endl;
  }
  
}

int* strikeout(int n, int k, int s){
  std::queue<int> survivors;
  const int REM_SURV = 2;

  for(int i = 1; i <= n; i++){
    survivors.push(i);
  }

  for(int i = 0; i < k + s - 1; i++){
    survivors.push(survivors.front());
    survivors.pop();
  }
  
  int iter = 0;
  while(survivors.size() > REM_SURV){
    if(iter % (s+1) == 0){
      survivors.pop();
    }
    else{
      survivors.push(survivors.front());
      survivors.pop();
    }
    iter++;
  }

  int* survivorArray = new int[REM_SURV];
  int i = 0;
  while(!survivors.empty()){
    survivorArray[i] = survivors.front();
    survivors.pop();
    i++;
  }

  return survivorArray;
}