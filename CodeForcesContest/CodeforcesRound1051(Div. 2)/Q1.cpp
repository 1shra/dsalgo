#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> vec(n);
    int f=1;
    for(int i=0;i<n;i++){
      cin>>vec[i];
    }
    int ans=1;
    for(int i=1;i<n;i++){
      if(vec[i-1]<vec[i]&&f){
        continue;
      }
      else if(vec[i-1]>vec[i]){
        f=0;
      }
      else{
        ans=0;
      }
    }
    if(ans){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
    
  }
  return 0;
}