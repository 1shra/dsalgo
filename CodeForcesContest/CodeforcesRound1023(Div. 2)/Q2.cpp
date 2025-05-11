/*
A. LRU and VIP
*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  while (n--)
  {
    int a;
    cin>>a;
    int k;
    cin>>k;
    int mx = 0;
    int mi = INT_MAX;
    vector<int> vec;
    for(int i=0;i<a;i++){
      int k;
      cin>>k;
      vec.push_back(k);
    }
    long long int sum = 0;
    for(int i:vec){
      mx = (mx<i)? i:mx;
      mi = (mi>i)? i:mi;
      sum+=i;
    }
    int mxs=0;
    for(int i:vec){
      if(i==mx) mxs++; 
    }

    if(mx-mi-1>k||(mx-mi == k+1 &&mxs>1)){
      cout<<"Jerry"<<endl;
    }
    else{
      string a = (sum%2==1)?"Tom":"Jerry";
      cout<<a<<endl;
    }
  }
  return 0;
}