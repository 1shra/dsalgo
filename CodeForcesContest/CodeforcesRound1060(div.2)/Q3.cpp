#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<vector<int>> pfac(N+1);

void solve(){
  int n;
  cin>>n;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) cin>>b[i];

  int ans=2;
  map<int,int> mp;
  for(int i=0;i<n;i++){
    for(int x:pfac[a[i]]){
      if(mp[x]>0){
        ans=0;
      }
      mp[x]++;
    }
  }
  //To check if increase by one is there any one prime factor
  for(int i=0;i<n;i++){
    for(int x:pfac[a[i]]){
      mp[x]--;
    }
    for(int x:pfac[a[i]+1]){
      if(mp[x]>0){
        ans=min(ans,1);
      }
    }
    for(int x: pfac[a[i]]){
      mp[x]++;
    }
  }
  cout<<ans<<endl;
}


int main() {
  for(int i=2;i<=N;i++){
    if(!pfac[i].empty()){
      continue;
    }
    for(int j=i;j<=N;j+=i){
      pfac[j].push_back(i);
    }
  }
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}