#include <iostream>
#include <vector>
using namespace std;
int CNOO(vector<vector<int>> vec)
{
    int m = vec.size();
    int n = vec[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));
    int a = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = vec[i][j];
                a = max(a, vec[i][j]);
            }
            else
            {
                if (vec[i][j])
                {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    a = max(a, dp[i][j]);
                }
            }
        }
    }
    return a;
}
int main()
{
    vector<vector<int>> vec = {
        {0, 1, 1, 1, 1, 1},
        {0, 1, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 0}};
    cout << CNOO(vec);
    return 0;
}