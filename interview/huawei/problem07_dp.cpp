//
// Created by lp on 2023/5/12.
//
/**
 * http://codefun2000.com/p/P1003
 */

#include "iostream"
#include "vector"

int main() {
  int N;
  std::cin >> N;
  std::vector<int> weights(N);
  for (auto &weight : weights) {
    std::cin >> weight;
  }

  int candy_of_kozi = weights[0], total_candy=weights[0];
  int weight = weights[0];
  for (int i = 1; i < N; ++i) {
    weight ^= weights[i];
    total_candy+=weights[i];
    candy_of_kozi= std::min(candy_of_kozi,weights[i]);
  }

  if(weight==0){
    std::cout<<total_candy-candy_of_kozi<<std::endl;
  }
  else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}