#include<iostream>
#include<vector>
using namespace std;
int min_coin(vector<int>& coin,int n,int sum){
  if(sum==0){
    return 1;
  }
  if(sum<0){
    return 0;
  }
  if(n<=0){
    return 0;
  }
  return min_coin(coin,n-1,sum)+min_coin(coin,n,sum-coin[n-1]);
}
int main(){
  vector<int> vec={1,2,5,10,12,20,50};
  int n=7;
  int sum=65;
  cout<<min_coin(vec,n,sum);
}