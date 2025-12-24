#include<iostream>
#include<vector>
using namespace std;


int main(){
  int t=0;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> vec(n);
    int i=0;
    for(i=0;i<n;i++){
      cin>>vec[i];
    }
    int count=0;
    int flag=0;
    if(vec[0]==1){
      count=1;
    }
    else{
      count=0;
    }

    for(int i=1;i<n;i++){
      if(vec[i]==0){
        if(vec[i-1]==0){
          flag=1;
          break;
        }
      }
      else{
        count++;
      }
    }
    if(flag||count==n){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
}