#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
      cin>>vec[i];
    }
    int maxe = 0;
    int cnt=0;
    for(int i=0;i<n;i++){
      maxe=max(maxe,vec[i]);
      if(i%2){
        vec[i]=maxe;
        if(vec[i]<=vec[i-1]){
          maxe=max(maxe,vec[i-1]);
          cnt+=(vec[i-1]-(vec[i]-1));
          vec[i-1]=vec[i]-1;
        }
        if(i+1<n&&vec[i]<=vec[i+1]){
          maxe=max(maxe,vec[i+1]);
          cnt+=(vec[i+1]-(vec[i]-1));
          vec[i+1]=vec[i]-1;
        }
      }
    }
    cout<<cnt<<endl;
  }
  return 0;
}