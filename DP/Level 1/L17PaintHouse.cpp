// Time complexity m*n*n

#include <iostream>
#include <limits.h>
using namespace std;

// int main(){
//     int m = 5;
//     int n=  4;
//     int arr[m][n]={{4,5,1,2},{7,2,5,4},{8,7,5,6},{1,2,4,5},{7,5,8,1}};

//     for(int i=1;i<m;i++){
//         for(int j=0;j<n;j++){
//             int k= 1;
//             int mi = arr[i-1][0];
//             while(k<n){
//                 if(k==j){
//                     k++;
//                     continue;
//                 }
//                 mi = min(mi,arr[i-1][k]);
//                 k++;
//             }
//             arr[i][j]=arr[i][j]+mi;
//         }
//     }
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     int ans = arr[m-1][0];
//     for(int i=m-1;i<m;i++){
//         for(int j=1;j<n;j++){
//             ans = min(ans,arr[i][j]);
//         }
//     }
//     cout<<arr[m-1][n-1]<<" ";
//     return 0;
// }

// Optimize:
int main()
{
    int m = 5;
    int n = 4;
    int arr[m][n] = {{4, 5, 1, 2}, {7, 2, 5, 4}, {8, 7, 5, 6}, {1, 2, 4, 5}, {7, 5, 8, 1}};

    int dp[m][n];
    int l = INT_MAX;
    int sl = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[0][i]<l){
            sl=l;
            l=arr[0][i];
        }
        else if(arr[0][i]<=sl){
            sl = arr[0][i];
        }
    }
    int nl = l;
    int nsl = sl;
    for(int i=1;i<m;i++){
        int l = INT_MAX;
        int sl = INT_MAX;
        for(int j=0;j<n;j++){
            if(arr[i-1][j]==nl){
                dp[i][j]=arr[i][j]+nsl;
            }
            else{
                dp[i][j]=arr[i][j]+nl;
            }

            if(dp[i][j]<=l){
                sl=l;
                l=dp[i][j];
            }
            else if(dp[i][j]<sl){
                sl = dp[i][j];
            }
        }
        nl=l;
        nsl=sl;
        cout<<nl<<" "<<nsl<<endl;
    }
    cout<<nl;
    return 0;
}
