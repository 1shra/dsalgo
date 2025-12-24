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
  map<int,int>mp;
  int k=0;
  for(int i:vec){
    mp[i]++;
  }
  while(true){
    if(mp[k]==0){
      break;
    }
    k++;
  }
  cout<<k<<endl;
 } 
}