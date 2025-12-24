#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> vec(n);
    int co=0,ce=0;
    for(int & i:vec){
      cin>>i;
      if(i%2){
        co++;
      }
      else{
        ce++;
      }
    }
    if(!(co==0||ce==0)){
      sort(vec.begin(),vec.end());
    }
    for(int i:vec){
      cout<<i<<" ";
    }
    cout<<endl;
  }
  return 0;
}