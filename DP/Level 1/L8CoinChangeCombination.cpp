#include <iostream>
#include <vector>
#include <climits>
using namespace std;



int coinChange(vector<int>& vec, int amount) {
    int n=vec.size();
    vector<int> dp(amount+1);
    dp[0]=1;
    for(int i=0;i<vec.size();i++){
        for(int j=vec[i];j<dp.size();j++){
            dp[j]+=dp[j-vec[i]];
        }
        for(int K=0;K<dp.size();K++){
            cout<<dp[K]<<" ";
        }
        cout<<endl;
    }
    return dp[amount];
}

int main()
{
    vector<int> vec = {2,3,5};
    int tsum = 7;
    cout << coinChange(vec, tsum);
}