#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin>>n;
  while(n--){
    int t;
    cin>>t;
    int ans=INT_MAX;
    while(t){
      ans=min(ans,t%10);
      t/=10;
    }
    cout<<ans<<endl;
  }
}