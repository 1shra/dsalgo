#include<iostream>
#include<vector>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int l=0;
    int r =0;
    int maxlength =0;
    int n=nums.size();
    int len;
    int zeroes=0;
    while(r<n){
        if(nums[r]==0){
            zeroes++;
        }
        if(zeroes>k){
            if(nums[l]==0){
                k++;
            }
            l++;
        }
        if(zeroes<=k){
                len=r-l+1;
                maxlength=max(maxlength,len);
                cout<<maxlength<<" ";
            }
        r++;
        // maxlength=max(maxlength,len);
    }
    cout<<endl;
    return maxlength ;
}

int main(){
    vector<int> vec = {0,1,1,0,0,1,1,0};
    cout<<longestOnes(vec,2);
    return 0;
}