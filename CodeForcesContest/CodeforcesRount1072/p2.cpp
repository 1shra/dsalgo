#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
  return __gcd(a,b);
}
int main(){
  ll t;
  cin>>t;
  while(t--){
    ll a,b,k;
    cin>>a>>b>>k;
  
    ll mx = max(ceil(((double)a/k)),ceil(((double)b/k)));
    if(mx<=gcd(a,b)){
      cout<<1<<endl;
    }
    else{
      cout<<2<<endl;
    }
  }
}