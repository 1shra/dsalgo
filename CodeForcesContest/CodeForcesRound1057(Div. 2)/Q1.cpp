#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
      cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    int cnt=1;
    int prevEat=vec[0];
    for(int i=1;i<n;i++){
      if(prevEat<vec[i]){
        prevEat=vec[i];
        cnt++;
      }
    }
    cout<<cnt<<endl;
  }
}