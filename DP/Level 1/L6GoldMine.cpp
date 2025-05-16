#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// recursive
int MinimumCostPath(vector<vector<int>> &vec, int i, int j, int m)
{
    if (i == m || i < 0)
    {
        return INT_MAX;
    }
    if (j == m - 1)
    {
        return vec[i][j];
    }
    return (vec[i][j]) + min(MinimumCostPath(vec, i + 1, j + 1, m), min(MinimumCostPath(vec, i - 1, j + 1, m), MinimumCostPath(vec, i, j + 1, m)));
}

int MemoMinimumCostPath(vector<vector<int>> &vec, int i, int j, int m, vector<vector<int>> &memo)
{
    if (i == m || i < 0)
    {
        return INT_MAX;
    }
    if (j == m - 1)
    {
        return vec[i][j];
    }
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }
    memo[i][j] = (vec[i][j]) + min(MemoMinimumCostPath(vec, i + 1, j + 1, m, memo), min(MemoMinimumCostPath(vec, i - 1, j + 1, m, memo), MemoMinimumCostPath(vec, i, j + 1, m, memo)));
    return memo[i][j];
}

int dpMini(vector<vector<int>> &vec)
{
    int n = vec.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for (int j = 0; j < n; j++)
    {
        dp[j][n - 1] = vec[j][n - 1];
    }
    for (int j = n - 2; j >= 0; j--)
    {

        for (int i = 0; i < n; i++)
        {
            if (i > 0)
            {
                dp[i][j] = dp[i - 1][j + 1];
            }
            if (i < n - 1)
            {
                dp[i][j] = min(dp[i][j], dp[i + 1][j + 1]);
            }
            dp[i][j] = vec[i][j] + min(dp[i][j], dp[i][j + 1]);
        }
    }
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        m = max(dp[i][0], m);
    }
    return m;
}

int main()
{
    // vector<vector<int>> vec = {
    //     {1, 2, 1},
    //     {4, 5, 6},
    //     {1, 1, 9}};
    vector<vector<int>> vec = {
        {2, 8, 4, 1, 6, 4, 2},
        {6, 0, 9, 5, 3, 8, 5},
        {1, 4, 3, 4, 0, 6, 5},
        {6, 4, 7, 2, 4, 6, 1},
        {1, 0, 3, 7, 1, 2, 7},
        {1, 5, 3, 2, 3, 0, 9},
        {2, 2, 5, 1, 9, 8, 0}};
    cout << "recursion" << endl;
    int j = 0;
    int m = 0;
    // cout << vec[0].size() << " ";
    for (int i = 0; i < vec.size(); i++)
    {
        int d = MinimumCostPath(vec, i, 0, vec.size());
        m = max(d, m);
    }
    cout << m << endl;

    cout << "Memorization" << endl;
    int n = vec.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    m = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        int d = MemoMinimumCostPath(vec, i, 0, vec.size(), memo);
        m = max(d, m);
    }

    cout << m << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }

    cout << "DP" << endl;
    cout << dpMini(vec) << endl;
}