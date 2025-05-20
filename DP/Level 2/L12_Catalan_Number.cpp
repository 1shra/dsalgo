#include<iostream>
#include<vector>
using namespace std;
int catalanNumber(int n){
  vector<int> dp(n+1);
  dp[0]=1;
  dp[1]=1;
  for(int i=2;i<=n;i++){
    int ans=0;
    int j=0,k=i-1;
    while(k>=0){
      ans+=(dp[j]*dp[k]);
      k--;
      j++;
    }
    dp[i]=ans;
  }
  for(int i:dp){
    cout<<i<<" ";
  }
  return dp[n];
}
int main(){
  int n;
  cin>>n;
  
  cout<<catalanNumber(n);
}