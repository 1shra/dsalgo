#include<bits/stdc++.h>
using namespace std;


int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    vector<int> vec(n,0);
    for(int i=0;i<n;i++){
      cin>>vec[i];
    }
    int ans=0;
    int cnt=0;
    for(int i=0;i<n;i++){
      if(vec[i]==0){
        cnt++;
      }
      else{
        cnt=0;
      }
      if(cnt==k){
        ans++;
        cnt=-1;
      }
    }
    cout<<ans<<endl;
  }
}