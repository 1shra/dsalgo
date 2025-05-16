#include <iostream>
#include <vector>
#include<queue>
using namespace std;
class step{
    public:
    int i;
    int j;
    int rem;
    string psf;
    step(int i1,int j1,int rem1,string pf){
        i=i1;
        j=j1;
        rem=rem1;
        psf=pf;
    }
};


void printPath(vector<vector<int>> & dp,vector<vector<int>> & vec){
    int n = dp.size()-1;
    int m = dp[0].size()-1;
    queue<step*> q;
    q.push(new step(n,m,dp[n][m],""));
    cout<<"All Path to reach the end of matrix: "<<endl;
    while(!q.empty()){
        step* bloc = q.front();
        q.pop();
        int re = bloc->rem;
        int n = bloc->i;
        int m = bloc->j;
        if(n==0&&m==0){
            string path = bloc->psf;
            path=to_string(vec[0][0])+path;
            cout<<path<<endl;
            continue;
        }
        if(n-1>=0&&(re-vec[n][m]==dp[n-1][m])){
            string pf = bloc->psf;
            pf = "->"+to_string(vec[n][m])+pf;
            q.push(new step(n-1,m,re-vec[n][m],pf));
        }
        if(m-1>=0&&(re-vec[n][m]==dp[n][m-1])){
            string pf = bloc->psf;
            pf = "->"+to_string(vec[n][m])+pf;
            q.push(new step(n,m-1,re-vec[n][m],pf));
        }
    }
    return;
}
void minimumCost(vector<vector<int>> &vec, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0] = vec[0][0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i-1][0]+ vec[i][0];
    }
    for (int i = 1; i < m; i++)
    {
        dp[0][i] = dp[0][i-1]+vec[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] =vec[i][j]+ (min(dp[i - 1][j], dp[i][j - 1]));
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<dp[n - 1][m - 1]<<endl;
    printPath(dp,vec);
}
int main()
{
    vector<vector<int>> vec = {
        {2, 6, 4, 1},
        {9, 1, 1, 0},
        {0, 7, 5, 2},
        {4, 3, 0, 4},
        {2, 0, 1, 10}};
    int n = vec.size();
    int m = vec[0].size();
    minimumCost(vec, n, m);
}