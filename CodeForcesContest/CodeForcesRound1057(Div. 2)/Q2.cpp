#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int x,y,z;
    cin>>x>>y>>z;
    int flag=1;
    for(int i=0;i<32;i++){
      int mask=1;
      int a = (x>>i)&mask;
      int b = (y>>i)&mask;
      int c = (z>>i)&mask;
      // cout<<" "<<a<<" "<<b<<" "<<c<<" "<<i<<endl;
      if(a==1&&b==1&&c==0){
        flag=0;
        break;
      }
      if(a==1&&b==0&&c==1){
        flag=0;
        break;
      }
      if(a==0&&b==1&&c==1){
        flag=0;
        break;
      }
    }
    if(flag){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
}