#include<iostream>
using namespace std;
int friends(int a){
    int dp[a+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=a;i++){
        dp[i]=dp[i-1]+(dp[i-2]*(i-1));
    }
    for(int i=0;i<=a;i++){
        cout<<dp[i]<<" ";
    }
    return dp[a];
}
int main(){
    int a = 5;
    cout<<friends(a);
}