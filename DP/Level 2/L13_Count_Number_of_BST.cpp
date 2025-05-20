#include<iostream>
#include<vector>
using namespace std;
int CNBST(int n){
  vector<int> dp(n+1);
  dp[0]=1;
  dp[1]=1;
  for(int i=2;i<=n;i++){
    int ans=0;
    for(int j=0;j<i;j++){
      ans+=(dp[j]*dp[i-j-1]);
    }
    dp[i]=ans;
  }
  return dp[n];
}

int main(){
  int n;
  cin>>n;
  cout<<CNBST(n);
}