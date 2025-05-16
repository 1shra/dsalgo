#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a = "06";

    int dp[a.length()];
    dp[0] = 1;

    for (int i = 1; i < a.length(); i++)
    {
        int n = a[i - 1];
        int m = a[i];
        if (n == '0' && m == '0')
        {
            dp[i] = 0;
        }
        else if (n != '0' && m == '0')
        {
            if (a[i - 1] == '1' || a[i - 1] == '2')
            {
                dp[i] = (i >= 2) ? dp[i - 2] : 1;
            }
            else
            {
                dp[i] = 0;
            }
        }
        else if (n == '0' && n != '0')
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            if (stoi(a.substr(i - 1, i + 1)) <= 26)
            {
                dp[i] = dp[i - 2];
            }
            dp[i] += dp[i - 1];
        }
    }
    cout << dp[a.length() - 1];
}