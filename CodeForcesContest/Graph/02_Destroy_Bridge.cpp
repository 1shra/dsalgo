#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin>>n;
  while(n--){
    int a,b;
    cin>>a>>b;
    if(b>=a-1) cout<<1;
    else cout<<a;
    cout<<endl;
  }
}