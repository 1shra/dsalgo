#include <bits/stdc++.h>
using namespace std;
int N = 2e5 + 10;
vector<vector<int>> pfac(N + 1);
void solve()
{
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int &x : a)
    cin >> x;
  for (int &x : b)
    cin >> x;
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int x, int y) -> bool
       { return b[x] < b[y]; });

  int ans = b[ord[0]] + b[ord[1]];
  map<int, int> mp;
  for (int i = 0; i < n; i++)
  {
    for (int x : pfac[a[i]])
    {
      if (mp[x] > 0)
      {
        ans = 0;
      }
      mp[x]++;
    }
  }

  int idx = ord[0];
  vector<int> check;

  for (int i = 0; i < n; i++)
  {
    if (i == idx)
    {
      continue;
    }
    for (int x : pfac[a[i]])
    {
      check.push_back(x);
    }
  }

  for (int x : check)
  {
    int times = x - (a[idx] % x);
    if (times == x)
    {
      times = 0;
    }
    ans = min(ans, times * b[idx]);
  }
  cout << ans << endl;
}
int main()
{
  for (int i = 2; i <= N; i++)
  {
    if (!pfac[i].empty())
    {
      continue;
    }
    for (int j = i; j <= N; j += i)
    {
      pfac[j].push_back(i);
    }
  }
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}