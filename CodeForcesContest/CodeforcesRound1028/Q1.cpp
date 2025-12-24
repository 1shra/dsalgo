#include<iostream>
#include<math.h>
using namespace std;

#define ll long long
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int i=0;
    while(pow(2,i)<=n){
      i++;
    }
    cout<<2LL*(i-1)+3<<endl;
  }
  return 0;
}