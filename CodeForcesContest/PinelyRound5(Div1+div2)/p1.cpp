#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--){
    int self,x,d,nr;
    cin>>self>>x>>d>>nr;
    string ss;
    cin>>ss;
    int res=0;
    for(char c:ss){
      bool round = (c=='1'||self<x);
      if(round){
        res++;
        self = max(0,self-d);
      }
    }
    cout<<res<<endl;
  }
  return 0;
}