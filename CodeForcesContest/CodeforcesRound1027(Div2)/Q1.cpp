#include<iostream>
#include<vector>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int k,l,m,n;
    cin>>k>>l>>m>>n;
    int one = min(k,m);
    int two = min(l,n);
    if(one>two){
      cout<<"Gellyfish"<<endl;
    }
    else if(two>one){
      cout<<"Flower"<<endl;
    }
    else{
      one = max(k,m);
      two = max(l,n);
      if(one==two){
        cout<<"Gellyfish"<<endl;
      }
      else if(one>two){
        cout<<"Gellyfish"<<endl;
      }
      else{
        cout<<"GellyFish"<<endl;
      }
    }
  }
  return 0;
}