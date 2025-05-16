#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// recursive
static int k = 0;
int MinStepsClimbing(vector<int> &vec, int i)
{
    k++;
    if (i >= vec.size() - 1)
    {
        return 0;
    }
    if (vec[i] == 0)
    {
        return INT_MAX;
    }
    int minSteps = INT_MAX;
    for (int j = 1; j <= vec[i]; j++)
    {
        int step = MinStepsClimbing(vec, i + j);
        if (step != INT_MAX)
        {
            minSteps = min(minSteps, 1 + step);
        }
    }
    return minSteps;
}
int MemoMinStepsClimbing(vector<int> &vec, int i, vector<int> &memo)
{
    if (i >= vec.size() - 1)
    {
        return 0;
    }
    if (vec[i] == 0)
    {
        return INT_MAX;
    }
    if (memo[i] != -1)
    {
        return memo[i];
    }
    int minSteps = INT_MAX;
    for (int j = 1; j <= vec[i]; j++)
    {
        int step = MemoMinStepsClimbing(vec, i + j, memo);
        if (step != INT_MAX)
        {
            minSteps = min(minSteps, 1 + step);
        }
    }
    memo[i] = minSteps;
    return minSteps;
}
int dp(vector<int> &vec)
{
    int n = vec.size();
    vector<int> dp(n, INT_MAX);
    dp[n-1] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (vec[i] == 0)
        {
            dp[i] = INT_MAX - 1;
            continue;
        }
        int b = INT_MAX;
        for (int j = 1; i + j <= n && j <= vec[i]; j++)
        {
            b = min(b, dp[i + j]);
        }
        dp[i] = 1+b;
    }
    for(int i:dp){
        cout<<i<<" ";
    }
    cout<<endl;

    return dp[0];
}

int main()
{
    vector<int> vec = {4, 1, 0, 2, 0, 3, 2};
    cout << "recursion" << endl;

    cout << MinStepsClimbing(vec, 0) << endl;
    cout << k << endl;
    int n = vec.size();
    k = 0;
    vector<int> memo(n, -1);
    cout << "Memorization" << endl;
    cout << MemoMinStepsClimbing(vec, 0, memo) << endl;
    cout << k<<endl;
    cout << "dp" << endl;
    cout << dp(vec)<<endl;
    return 0;
}