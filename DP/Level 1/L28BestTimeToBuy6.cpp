// buy and sell the  stock at the most k times

#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int buyandsell(vector<int> &pri,int k){
    vector<vector<int>> dp(k+1,vector<int>(pri.size()));
    for(int i=0;i<=pri.size();i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=k;i++){
        dp[k][0]=0;
    }
    // Take more Time Complexity n^3
    // for(int i=1;i<=k;i++){
    //     for(int j=1;j<pri.size();j++){
    //         dp[i][j]=dp[i][j-1];
    //         int p = 0;
    //         for(int l=0;l<j;l++){
    //             p = (pri[j]-pri[l])+dp[i-1][l];
    //             if(dp[i][j]<p){
    //                 dp[i][j]=p;
    //             }
    //         }
    //     }
    // }



    //Minmizeing its time complexity 
    for(int i=1;i<=k;i++){
        int ma = INT_MIN; 
        for(int j=1;j<pri.size();j++){
            dp[i][j]=dp[i][j-1];
            if(dp[i-1][j-1]-pri[j]>ma){
                ma=dp[i-1][j-1]-pri[j];
            }
            if(dp[i][j]<ma+pri[j]){
                dp[i][j]=ma+pri[j];
            }
        }
        
    }
    for(int i=0;i<=k;i++){
        for(int j=0;j<pri.size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[k][pri.size()-1];
}
int main(){
    vector<int> pri = {9,6,7,6,3,8};
    int k = 3;
    cout<<buyandsell(pri,k);
}