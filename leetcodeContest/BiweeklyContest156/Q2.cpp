/*
3542. Minimum Operations to Convert All Elements to Zero
*/
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
int minOperations(vector<int>& nums) {
    vector<pair<int,int>> vec;
    int n=nums.size();
    for(int i=0;i<nums.size();i++){
        vec.push_back({nums[i],i});
    }
    sort(vec.begin(),vec.end());
    set<int> s{n};
    
    int ans = 0;
    for(int i=0;i<n;i++){
        s.insert(vec[i].second);
        if(vec[i].first !=0) ans++;
        while(i+1<n&&vec[i].first==vec[i+1].first){
            int nextSmaller = *s.upper_bound(vec[i].second);
            int nextsame = vec[i+1].second;
            if(nextSmaller<nextsame){
                break;
            }
            i++;
            s.insert(vec[i].second);
        }
    }
    return ans;
}
int main(){
  vector<int> nums = {0,2};
  cout<<minOperations(nums);
}