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
    int flag=0;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if((vec[j]%vec[i])%2==0){
          cout<<vec[i]<<" "<<vec[j]<<endl;
          flag=1;
          break;
        }
      }
      if(flag){
        break;
      }
    }
    if(!flag){
      cout<<-1<<endl;
    }
  }
  return 0;
}