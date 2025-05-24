#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
  int t=0;
  cin>>t;
  while(t--){
    string b;
    cin>>b;

    int m = b.size();
    int count=0;
    int sum=0;
    for(int i=0;i<m;i++){
      sum +=(b[i]==')'?-1:+1);
      if(sum==0){
        count++;
      }
    }
    if(count>1){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  } 
}