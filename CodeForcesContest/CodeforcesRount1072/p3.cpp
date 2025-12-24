#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll countGood(ll n){
  if(n<=0) return 0;
  ll total = n;
  vector<int> pr = {2,3,5,7};
  int s = pr.size();

  for(int ma = 1 ;ma<(1<<s);++ma){
    ll lcm = 1;
    int bit = 0;
    for(int i=0;i<s;i++){
      if(ma&(1<<i)){
        lcm*=pr[i];
        bit++;
      }
    }
    ll cnt = n/lcm;
    if(bit%2) total -=cnt;
    else{
      total+=cnt;
    }
  }
  return total;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    ll l,r;
    cin>>l>>r;
    cout<<countGood(r)-countGood(l-1)<<endl;
  }
}