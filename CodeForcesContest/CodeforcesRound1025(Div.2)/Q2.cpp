#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long calulate(long long r){
  long long ans=0;
  while(r>1){
    if(r==3){
      r=1;
      ans+=2;
    }
    else{
      if(r%2){
        r/=2;
        r+=1;
      }
      else{
        r/=2;
      }
      ans++;
    }
  }
  return ans;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    long long r =n;
    long long c=m;
    r = 1+min(n-a,a-1);
    long long ans = 1+calulate(r)+calulate(c);
    r = n;
    c = m;
    c= 1 + min(m-b,b-1);
    ans =min(ans,1+calulate(r)+calulate(c));
    cout<<ans<<endl;
  }
}