//Here include tax fee for each time sell 

#include<iostream>
#include<vector>
using namespace std;
// int buyAsell(int pri[],int n,int t){
//     vector<vector<int>> dp(n,vector<int> (2));
//     dp[0][0]=pri[0];
//     dp[0][1]=0;
//     for(int i=1;i<n;i++){
//         dp[i][0]=min(dp[i-1][0],pri[i]-dp[i-1][1]);
//         dp[i][1]=max(dp[i-1][1],pri[i]-dp[i-1][0]-t);
//     }
//     return dp[n-1][1];
// }


int buyAsell(int pri[],int n,int tax){
    int obsp= -pri[0];
    int ossp= 0;
    for(int i=1;i<n;i++){
        int nbsp = 0;
        int nssp=0;
        if(ossp-pri[i]>obsp){
            nbsp=ossp-pri[i];
        }
        else{
            nbsp=obsp;
        }

        if(obsp+pri[i]-tax>ossp){
            nssp=obsp+pri[i]-tax;
        }
        else{
            nssp = ossp;
        }
        ossp=nssp;
        obsp=nbsp;
    }
    return ossp;
}
int main(){

    int pri[] = {4,5,2,4,3,3,1,2,5,4};
    cout<<buyAsell(pri,sizeof(pri)/sizeof(pri[0]),1);
}