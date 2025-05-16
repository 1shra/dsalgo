#include<iostream>
using namespace std;
int countways(int n,int m){
    int dp[n+1];
    for(int i = 1 ; i<=n;i++){
        if(i<m){
            dp[i]=i;
        }
        else if(i==m){
            dp[i]=2;
        }
        else{
            dp[i]=dp[i-1]+dp[i-m];
        }
    }
    return dp[n];

}
int main(){
    int n=5, m=4;
    cout<<countways(n,m);
    return 0;
}