#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
      cin>>vec[i];
    }
    map<int,int> mp;
    for(int i=0;i<n;i++){
      mp[vec[i]]++;
    }
    
    vector<int> cnt;
    for(auto i:mp){
      cnt.push_back(i.second);
    }
    sort(cnt.begin(),cnt.end());
    int e=cnt.size();
    int ma=0;
    for(int i=0;i<e;i++){
      // cout<<cnt[i]<<" "<<e-i<<" ";
      int k = cnt[i]*(e-i);
      // cout<<k<<endl;
      ma=max(k,ma);
    }
    cout<<ma<<endl;
  }
}