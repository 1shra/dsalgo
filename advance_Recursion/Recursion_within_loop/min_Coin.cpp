#include<iostream>
#include<vector>
using namespace std;
int min_coin(vector<int>& coin,int n,int sum){
  int temp=1;
  int res = 922337203;
  if(sum==0){
    return 0;
  }
  for(int i=0;i<n;i++){
    if(coin[i]<=sum){
      temp = min_coin(coin,n,sum-coin[i]);
      if(temp+1<res){
        res=temp+1;
      }
    }
  }
  return res;
}
int main(){
  vector<int> vec={1,2,3};
  int n=3;
  int sum=4;
  cout<<min_coin(vec,n,sum);
}