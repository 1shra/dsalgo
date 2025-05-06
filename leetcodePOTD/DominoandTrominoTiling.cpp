/*
790. Domino and Tromino Tiling
https://leetcode.com/problems/domino-and-tromino-tiling/description/?envType=daily-question&envId=2025-05-05
*/
#include<iostream>
#include<vector>
using namespace std;
int numTilings(int n) {
  if(n==2||n==1){
      return n;
  }
  vector<int> vec(n+1);
  vec[1]=1;
  vec[0]=1;
  vec[2]=2;
  for(int i=3;i<=n;i++){
      int a =vec[i-1]*2 %1000000007;
      vec[i]=((a)+vec[i-3])%1000000007;
  }
  return vec[n];
}

int main(){
  int n;
  cin>>n;
  cout<<numTilings(n);
  return 0;
}