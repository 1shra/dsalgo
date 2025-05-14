#include<iostream>
#include<vector>
using namespace std;
int Maxincsub(vector<int>vec){
  
  int n = vec.size();
  int res = vec[0];
  vector<int> dp(n,0);
  dp[0]=vec[0];
  for(int i=1;i<n;i++){
    dp[i]=vec[i];
    int ans=0;
    for(int j=i-1;j>=0;j--){
      if(vec[i]>vec[j]){
        ans=max(ans,dp[j]);
      }
    }
    dp[i]+=ans;
    res=max(res,dp[i]);
  }
  for(int i:dp){
    cout<<i<<" ";
  }
  cout<<endl;
  return res  ;
}
int main(){
  // vector<int> vec = {10,10,22,9,33,21,50,41,60,60,80,1};
  vector<int> vec = {42};
  for(auto i:vec) cout<<i<<" ";
  cout<<endl;
  cout<<Maxincsub(vec);

}