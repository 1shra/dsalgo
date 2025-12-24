#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void racing(int n)
{
  vector<int> d(n+1);
  for (int i = 1; i <= n; i++)
  {
    cin>>d[i];
  }
  vector<pair<int, int>> kl(n+1);
  for (int i = 1; i <= n; i++)
  {
    int e, f;
    cin >> e;
    kl[i]= {e, f};
  }
  vector<pair<int, int>> dp(n + 1);
  dp[0] = {0, 0};
  bool flag = true;

  for (int i = 1; i <= n; ++i)
  {
    int l, h;
    if (d[i] == 0)
    {
      l = dp[i - 1].first;
      h = dp[i - 1].second;
    }
    else if (d[i] == 1)
    {
      l = dp[i - 1].first + 1;
      h = dp[i - 1].second + 1;
    }
    else
    {
      l = dp[i - 1].first;
      h = dp[i - 1].second + 1;
    }

    int L = max(kl[i].first, l);
    int H = min(kl[i].second, h);
    if (L > H)
    {
      flag = false;
      break;
    }
    dp[i] = {L, H};
  }

  if (!flag)
  {
    cout << -1 << "\n";
    return;
  }

  vector<int> res(n + 1);
  int h = dp[n].first;

  for (int i = n; i >= 1; --i)
  {
    if (d[i] != -1)
    {
      res[i] = d[i];
      h -= d[i];
    }
    else
    {
      if (h >= dp[i - 1].first && h <= dp[i - 1].second)
      {
        res[i] = 0;
      }
      else
      {
        res[i] = 1;
        h -= 1;
      }
    }
  }

  for (int i = 1; i <= n; ++i)
  {
    cout << res[i] << (i == n ? '\n' : ' ');
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    racing(n);
  }
}