#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  while(n--){
    int k;
    cin>>k;
    int d = k%2?k/2:(k-2)/2;
    cout<<d<<endl;
  }
  return 0;
}