#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> a[n];
    vector<int> indegree(n);

    for (int i = 0; i < n - 1; i++)
    {
      int u, v, x, y;
      cin >> u >> v >> x >> y;
      u--;
      v--;
      if (x > y)
      {
        a[u].push_back(v);
        indegree[v]++;
      }
      else
      {
        a[v].push_back(u);
        indegree[u]++;
      }
    }
    queue<int> que;
    for (int i = 0; i < n; i++)
    {
      if (indegree[i] == 0)
      {
        que.push(i);
      }
    }
    vector<int> ans;
    while (!que.empty())
    {
      int node = que.front();
      que.pop();
      ans.push_back(node);
      for (auto it : a[node])
      {
        indegree[it]--;
        if (indegree[it] == 0)
        {
          que.push(it);
        }
      }
    }
    vector<int> v(n);
    int k = 0;
    for (int i = n; i >= 1; i--)
    {
      v[ans[k++]] = i;
    }
    for (int i : v)
    {
      cout << i << " ";
    }
    cout << endl;
  }
}