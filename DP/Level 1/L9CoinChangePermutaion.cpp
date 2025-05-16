#include<iostream>
#include<vector>
using namespace std;
int PermutCoinChange(vector<int>&vec,int d){
    vector<int> dp(d+1,0);
    dp[0]=1;
    for(int i=1;i<dp.size();i++){
        for(int j=0;j<vec.size();j++){
            if((i-vec[j])>=0){
                dp[i]+=dp[i-vec[j]];
            }
        }
    }
    for(int k:dp){
        cout<<k<<" ";
    }
    cout<<endl;
    return dp[d];

}
int main(){
    vector<int> vec{2,3,5,6};
    int d = 10;
    cout<<PermutCoinChange(vec,d);
}