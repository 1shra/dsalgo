#include<bits/stdc++.h>
using namespace std;


int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int>vec(n);
    int ans=0;
    for(int i=0;i<n;i++){
      cin>>vec[i];
      ans=max(ans,vec[i]);
    }
    
    cout<<ans<<endl;
  }
}