#include<iostream>
using namespace std;

int main(){
  int a;
  cin>>a;

  for(int i=1;i<2*a;i++){
    for(int j=1;j<=a;j++){
      if(i<a){
        if(j<=a-i){
          cout<<" ";
        }
        else{
          cout<<"*";
        }
      }
      if(i==a){
        cout<<"*";
      }
      if(i>a){
        if(i-a>=j){
          cout<<" ";
        }
        else{
          cout<<"*";
        }
      }
    }
    cout<<endl;
  }

}