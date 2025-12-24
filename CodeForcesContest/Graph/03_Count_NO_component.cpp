#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(vector<int> &visit, vector<vector<int>> &adj, int i)
  {
    for (int a : adj[i])
    {
      if (!visit[a])
      {
        visit[a] = 1;
        dfs(visit, adj, a);
      }
    }
  }
  int findNumberOfComponent(int V, vector<vector<int>> &edges)
  {
    vector<vector<int>> adj(V);
    for (int i = 0; i < edges.size(); i++)
    {
      int a, b;
      a = edges[i][0];
      b = edges[i][1];
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    int component = 0;
    vector<int> visit(V, 0);
    for (int i = 0; i < V; i++)
    {
      if (!visit[i])
      {
        visit[i] = 1;
        component++;
        dfs(visit, adj, i);
      }
    }
    return component;
  }
};

int main()
{
  int v = 0;
  vector<vector<int>> edge(0);
  // edge[0] = {0, 1};
  // edge[1] = {1, 2};
  Solution s;
  cout << (s.findNumberOfComponent(v, edge));
}