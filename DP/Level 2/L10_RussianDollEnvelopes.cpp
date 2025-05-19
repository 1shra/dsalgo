#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int RussianDollEnvelopes(int n,vector<int> width,vector<int> height){
  vector<pair<int,int>> p;
  for(int i=0;i<n;i++){
    p.push_back({width[i],i});
  }
  sort(p.begin(),p.end());
  int ans=0;
  vector<int> dp(n,1);
  for(int i=1;i<n;i++){
    int j = height[p[i].second];
    int count=0;
    for(int k=i-1;k>=0;k--){
      int l = height[p[k].second];
      if(l<j){
        count = max(count,dp[k]);
      }
    }
    dp[i] = count+1;
    ans= max(dp[i],ans);
  }
  return ans;
}

int main(){
  int n=11;
  vector<int> width = {17,26,25,48,63,42,9,4,21,68,58};
  vector<int> height = {5,18,34,84,72,86,55,70,45,76,51};
  cout<<RussianDollEnvelopes(n,width,height);
}