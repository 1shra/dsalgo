#include<iostream>
using namespace std;

int GCD(int a,int b){
  if(a==0){
    return b;
  }
  return GCD(b%a,a);
}

int LCM(int gcd,int a,int b){
  return ((a*b)/gcd);
}
int main(){
  int a = 18;
  int b = 12;
  int gcd = GCD(a,b);
  cout<<gcd<<endl;
  cout<<LCM(gcd,a,b);
}