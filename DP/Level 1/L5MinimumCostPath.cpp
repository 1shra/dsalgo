#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// recursive
int MinimumCostPath(vector<vector<int>> &vec, int i, int j, int m)
{
    if (i == m - 1 && j == m - 1)
    {
        return vec[i][j];
    }
    if (i == m || j == m)
    {
        return INT_MAX;
    }
    int sum = (vec[i][j]) + min(MinimumCostPath(vec, i + 1, j, m), MinimumCostPath(vec, i, j + 1, m));
    return sum;
}

// Memorization
int MemoMinimumCostPath(vector<vector<int>> &vec, int i, int j, int m, vector<vector<int>> &memo)
{
    if (i == m - 1 && j == m - 1)
    {
        return vec[i][j];
    }
    if (i == m || j == m)
    {
        return INT_MAX;
    }
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }
    memo[i][j] = (vec[i][j]) + min(MinimumCostPath(vec, i + 1, j, m), MinimumCostPath(vec, i, j + 1, m));
    return memo[i][j];
}

// DP
int DP(vector<vector<int>> &vec, int i, int j, int m)
{
    vector<vector<int>> dp(m, vector<int>(m, -1));
    dp[0][0] = vec[0][0];
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = vec[i][0] + dp[i - 1][0];
        dp[0][i] = vec[0][i] + dp[0][i - 1];
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = vec[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // PRINT DP 2D ARRAY
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[m - 1][m - 1];
}
int main()
{
    vector<vector<int>> vec = {
        {1, 2, 1},
        {4, 5, 6},
        {1, 1, 9}};
    // vector<vector<int>> vec ={
    //     {2, 8, 4, 1, 6, 4, 2},
    //     {6, 0, 9, 5, 3, 8, 5},
    //     {1, 4, 3, 4, 0, 6, 5},
    //     {6, 4, 7, 2, 4, 6, 1},
    //     {1, 0, 3, 7, 1, 2, 7},
    //     {1, 5, 3, 2, 3, 0, 9},
    //     {2, 2, 5, 1, 9, 8, 0}};
    cout << "recursion" << endl;
    int i = 0;
    int j = 0;
    cout << MinimumCostPath(vec, i, j, 3) << endl;

    cout << "Memorizatioin" << endl;
    vector<vector<int>> memo = {
        {-1, -1, -1},
        {-1, -1, -1},
        {-1, -1, -1}};
    cout << MemoMinimumCostPath(vec, i, j, 3, memo) << endl;
    i = 0, j = 0;
    cout << "DP" << endl;
    cout << DP(vec, i, j, 3) << endl;
}