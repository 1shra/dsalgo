#include<iostream>
using namespace std;
int knapsack(int a,int ball[],int prof[],int t){
    int dp[a+1][t+1];
    for(int i=0;i<=a;i++){
        for(int j=0;j<=t;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=t;j++){
            if(j-ball[i-1]<0){
                dp[i][j] = dp[i-1][j];
                continue;
            }
            dp[i][j]=max(dp[i][j-ball[i-1]]+prof[i-1],dp[i-1][j]);
        }
    }
    for(int i=0;i<=a;i++){
        for(int j=0;j<=t;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
int main()
{
    int a = 5;
    int prof[] = {15, 14, 10, 45, 30};
    int ball[] = {2, 5, 1, 3, 4};
    int target = 7;
    cout << knapsack(a, ball, prof, target);
    return 0;
}