#include<bits/stdc++.h>
using namespace std;


int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> vec(n);

    map<int,int> mp;
    for(int i=0;i<n;i++){
      cin>>vec[i];
      mp[vec[i]]++;
    }
    vector<int> gret;
    vector<int> smal;
    for(auto i:mp){
      if(i.second>=2){
        gret.push_back(i.first);
      }
      else{
        smal.push_back(i.first);
      }
    }
    int side=
    for(int i=0;i<gret.size();i++){
      int cnt = mp[gret[i]]/2;


    }

  }
}