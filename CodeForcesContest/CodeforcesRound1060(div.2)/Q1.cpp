#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    string a;
    cin>>a;
    int ans=0;
    int last = -100000;
    for(int i=0;i<n;i++){
      if(a[i]=='0'){
        continue;
      }
      if(i-last>=k){
        ans++;
      }
      last=i;
    }
    cout<<ans<<endl;
  }
}