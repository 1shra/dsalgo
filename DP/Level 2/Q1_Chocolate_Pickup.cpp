#include <iostream>
#include <vector>
#include<limits>
using namespace std;
int calMax(int cr,int r1c,int r2c, int tr,int tc,vector<vector<int>> &choco,vector<vector<vector<int>>>& dp){
    if(r1c<0||r2c<0||r1c>=tc||r2c>=tc){
        return -1e8;
    }
    if(cr==tr-1){
        if(r1c==r2c){
            return choco[cr][r1c];
        }
        else{
            return choco[cr][r1c]+choco[cr][r2c];
        }
    }
    if(dp[cr][r1c][r2c]!=-1){
        return dp[cr][r1c][r2c];
    }

    int maxchoco = -1e8;

    for(int ar1=-1;ar1<=1;ar1++){
        for(int ar2=-1;ar2<=1;ar2++){
            int ch=0;
            if(r1c==r2c){
                ch += choco[cr][r2c];
            }
            else{
                ch += (choco[cr][r1c]+choco[cr][r2c]);
            }   

            ch+=calMax(cr+1,r1c+ar1,r2c+ar2,tr,tc,choco,dp);
            maxchoco=max(maxchoco,ch);
        }
        return dp[cr][r1c][r2c]=maxchoco;
    }

}
int main()
{
    int r = 4;
    int c = 3;
    vector<vector<int>> choco{{4, 1, 2}, {3, 6, 1}, {1, 6, 6}, {3, 1, 2}};
    vector<vector<vector<int>>> dp(r,vector<vector<int>> (c,vector<int>(c,-1)));
    int result = calMax(0,0,c-1,r,c,choco,dp);
    cout<<result;
    return 0;
}