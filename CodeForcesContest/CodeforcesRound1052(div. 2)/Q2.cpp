#include <bits/stdc++.h>
using namespace std;

int ans(int n, int m, vector<vector<int>> &arr)
{
  vector<int> s(m + 1, 0);

  for (const auto &c : arr)
  {
    for (int x : c)
    {
      s[x]++;
    }
  }

  for (int i = 1; i <= m; i++)
  {
    if (s[i] == 0)
    {
      return 0;
    }
  }

  int way = 0;

  for (const auto &set : arr)
  {
    bool rem = true;
    for (int x : set)
    {
      if (s[x] == 1)
      {
        rem = false;
        break;
      }
    }
    if (rem)
    {
      way++;
    }
    if (way >= 2)
    {
      return 1;
    }
  }

  return 0;
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n);

    for (int i = 0; i < n; i++)
    {
      int k;
      cin >> k;
      s[i].resize(k);
      for (int j = 0; j < k; j++)
      {
        cin >> s[i][j];
      }
    }

    cout << (ans(n, m, s) ? "Yes" : "No") << endl;
  }

  return 0;
}
