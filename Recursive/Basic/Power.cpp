#include<iostream>
#include<climits>
using namespace std;
double power(double a,int b){
  if(b==0){
    return 1;
  }
  else if(b<0){
    return 1/power(a,-b);
  }
  if(b%2==0){
    return power(a*a,b/2);
  }
  return a*power(a,b-1);
}
int main(){
  cout<<power(2,INT_MIN);
  return 0;
}