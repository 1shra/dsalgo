#include<iostream>
#include<vector>
using namespace std;
int LBS(vector<int> &vec){
  int n = vec.size();
  vector<int>incdp(n,1);
  for(int i=1;i<n;i++){
    int ans=0;
    for(int j=i-1;j>=0;j--){
      if(vec[i]>vec[j]){
        ans=max(ans,incdp[j]);
      }
    }
    incdp[i]+=ans;
  }
  vector<int> decdp(n,1);
  for(int i=n-2;i>=0;i--){
    int ans=0;
    for(int j=i+1;j<n;j++){
      if(vec[i]>vec[j]){
        ans = max(ans,decdp[j]);
      }
    }
    decdp[i]+=ans;
  }
  // for(int i:incdp){
  //   cout<<i<<" ";
  // }
  int ans=0;
  for(int i=0;i<vec.size();i++){
    if(ans<(incdp[i]+decdp[i]-1)){
      ans=(incdp[i]+decdp[i]-1);
    }
  }
  return ans;
}
int main(){
  vector<int> arr = {10,22,9,33,21,50,41,3};
  cout<<LBS(arr);
}