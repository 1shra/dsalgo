#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
void printAllThePath(vector<int> &vec)
{
    int n = vec.size() - 1;
    vec[n] = 0;
    vector<int> dp(n + 1);
    dp[n]=0;
    for (int i = vec.size() - 2; i >= 0; i--)
    {
        int a = vec[i];
        int mi = INT_MAX;
        for (int j = 1; j <= a && (i + j) <= n; j++)
        {
            if (mi > dp[i + j])
            {
                mi = dp[i + j];
            }
        }
        if (mi == INT_MAX)
        {
            dp[i] = INT_MAX;
            continue;
        }
        dp[i] = mi + 1;
    }

    for (int i : dp)
    {
        cout << i << " ";
    }

    int i = 0, j;
    string pf = "";
    cout << endl;
    cout << "Path: 0->";
    while (i <= n)
    {
        int s = vec[i];
        int j = 1;
        // cout<<i;
        if (dp[i] == INT_MAX)
        {
            i+=1;
            continue;
        }
        while (i + j < n + 1 && j <= s)
        {
            if (dp[i + j] == dp[i] - 1)
            {
                pf += to_string((i + j)) + "->";
                break;
            }
            j++;
        }
        i = i + j;
    }
    pf=pf.substr(0,pf.length()-2);
    cout << pf;
    return;
}
int main()
{
    vector<int> vec = {2,1};
    printAllThePath(vec);
    return 0;
}