/*
1920. Build Array from Permutation
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> buildArray(vector<int>& nums) {
  int n = nums.size();
  vector<int> ans(n);
  for(int i=0;i<nums.size();i++){
      ans[i]=nums[nums[i]];
  }
  return ans;
}

int main(){
  int n;
  vector<int> vec = {0,2,1,5,3,4}; 
  vector<int> ans = buildArray(vec);
  for(int i=0;i<vec.size();i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}