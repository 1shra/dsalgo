#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  vector<int> prime = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
  while(t--){
    int n;
    cin>>n;
    vector<long long> vec(n);
    int k=INT_MAX;
    for(long long &i:vec){
      cin>>i;
    }
    int flag=1;
    if(k==1){
      cout<<2<<endl;
      continue;
    }
    for(int i=0;i<prime.size();i++){
      for(long long k:vec){
        if(flag&&k%prime[i]!=0){
          flag=0;
          cout<<prime[i]<<endl;
          break;
        }
      }
      if(!flag){
        break;
      }
    }
    if(flag) cout<<-1<<endl;
  }
  return 0;