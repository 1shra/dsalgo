#include<bits/stdc++.h>
using namespace std;

int main(){
  int n=0;
  cin>>n;
  vector<int> vec(n-1);
  for(int i=0;i<n-1;i++){
    cin>>vec[i];
  }
  sort(vec.begin(),vec.end());
  for(int i=1;i<=n;i++){
    if(vec[i-1]!=i){
      cout<<i;
      break;
    }
  }
}