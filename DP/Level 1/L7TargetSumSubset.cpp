#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// recursive

int TargetSum(vector<int> &vec, int tsum, int i)
{
    if (tsum == 0)
    {
        return 1;
    }
    if (i == vec.size() || tsum < 0)
    {
        return 0;
    }
    int a = TargetSum(vec, tsum, i + 1) + TargetSum(vec, tsum - vec[i], i + 1);
    return a;
}
// memoization
int memoTargetSum(vector<int> &vec, int tsum, int i, vector<int> &memo)
{
    if (tsum == 0)
    {
        return 1;
    }
    if (i == vec.size() || tsum < 0)
    {
        return 0;
    }
    if (memo[i] != -1)
    {
        return memo[i];
    }
    memo[i] = TargetSum(vec, tsum, i + 1) + TargetSum(vec, tsum - vec[i], i + 1);
    return memo[i];
}

bool dp(vector<int> &vec, int sum)
{
    int n = vec.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));


    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j - vec[i-1] < 0)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - vec[i-1]];
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= sum; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n][sum ];
}
int main()
{
    vector<int> vec = {29, 66, 31, 2, 28, 88, 1, 97, 73, 78, 62, 27};
    int tsum = 582;
    // vector<int> memo(vec.size(), -1);
    // cout << TargetSum(vec, tsum, 0) << endl;
    // cout << memoTargetSum(vec, tsum, 0, memo) << endl;
    cout << dp(vec, tsum);
}