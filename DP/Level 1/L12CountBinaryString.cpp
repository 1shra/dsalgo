#include<iostream>
using namespace std;
int count(int a){
    if(a==1){
        return 1;
    }
    if(a==2){
        return 2;
    }
    int dp[a+1];
    dp[0]=0;
    dp[1]=2;
    dp[2]=3;
    for(int i=3;i<=a;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    for(int i=0;i<=a;i++){
        cout<<dp[i]<<" ";
    }
    return dp[a];
}

int main(){
    int a = 20;
    cout<<count(a);
}