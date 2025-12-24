#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int &i: vec) cin>>i;
    int flag=1;
    sort(vec.begin(),vec.end());
    for(int i=1;i<n;i+=2){
      if(i+1<n&&vec[i]!=vec[i+1]){
        flag=0;
        break;
      }
    }
    if(flag) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
  }
  return 0;
}