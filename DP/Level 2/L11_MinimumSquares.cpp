#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
//LIS
int minimumSquare(int n){
  vector<int>dp(n+1,1);
  dp[0]=0;
  dp[1]=1;
  for(int i=2;i<=n;i++){
    int min =INT_MAX;
    for(int j=1;j*j<=i;j++){
      int rem = i-(j*j);
      if(dp[rem]<min){
        min=dp[rem];
      }
    }
    dp[i]=min+1;
  }
  return dp[n];
}
int main(){
  int n;
  cin>>n;
  cout<<minimumSquare(n);

}