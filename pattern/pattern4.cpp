#include<iostream>
using namespace std;
int count=0;
int fibo(int a){
  if(a==0){
    return 0;
  }
  if(a==1){
    return 1;
  }
  return (fibo(a-1)+fibo(a-2));
}
int main(){
  int a=20;
  cout<<fibo(a);
}