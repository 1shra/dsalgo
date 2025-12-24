#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

long long di = 998244353;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int>p(n);
    vector<int>q(n);
    
    for(int i=0;i<n;i++) {
      cin>>p[i];
      p[i]=((long long)pow(2,p[i])%di);
    }
    for(int i=0;i<n;i++){
      cin>>q[i];
      q[i]=((long long)pow(2,q[i]))%di;
    }
    for()
    
  }
}