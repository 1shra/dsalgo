#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int &i:vec) cin>>i;
    int x;
    cin>>x;
    int mn=INT_MAX;
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
      if(mx<vec[i]){
        mx=vec[i];
      }
      if(mn>vec[i]){
        mn=vec[i];
      }
    }
    if(x<=mx&&mn<=x){
      cout<<"YES";
    }
    else{
      cout<<"NO";
    }
    cout<<endl;
  }
  return 0;
}