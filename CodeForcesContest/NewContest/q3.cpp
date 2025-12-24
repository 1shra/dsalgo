#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;
    multiset<long long> sword;
    for (int i = 0; i < n; ++i)
    {
      long long a;
      cin >> a;
      sword.insert(a);
    }
    vector<int> monster(m), recover(m);
    for (int i = 0; i < m; ++i)
      cin >> monster[i];
    for (int i = 0; i < m; ++i)
      cin >> recover[i];
    vector<pair<int, int>> pr;
    vector<int> ans;
    for (int i = 0; i < m; ++i)
    {
      if (recover[i] == 0)
      {
        ans.push_back(monster[i]);
      }
      else
      {
        pr.emplace_back(monster[i], recover[i]);
      }
    }
    sort(pr.begin(), pr.end());
    sort(ans.begin(), ans.end());
    int res = 0;
    for (auto &p : pr)
    {
      int h = p.first, rw = p.second;
      auto it = sword.lower_bound(h);
      if (it != sword.end())
      {
        long long sd = *it;
        sword.erase(it);
        ++res;
        sword.insert(max((long long)rw, sd));
      }
    }
    for (int h : ans)
    {
      auto it = sword.lower_bound(h);
      if (it != sword.end())
      {
        sword.erase(it);
        ++res;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
