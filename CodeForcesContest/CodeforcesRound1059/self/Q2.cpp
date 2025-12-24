#include <bits/stdc++.h>
using namespace std;


int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string t;
    cin>>t;
    int zero=0;
    vector<int> ind;
    for(int i=0;i<n;i++){
      if(t[i]=='0'){
        zero++;
        ind.push_back(i);
      }
    }
    if(zero==n||zero==0){
      cout<<"0"<<endl;
      cout<<endl;
    }
    else{
      cout<<zero<<endl;
      for(int i:ind){
        cout<<i<<" ";
      }
      cout<<endl;
    }
  }
}
