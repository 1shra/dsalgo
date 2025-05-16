#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class path
{
public:
  int rem;
  int idx;
  int val;
  string tpath;
  path(int rem1, int idx1, int val1, string path)
  {
    rem = rem1;
    idx = idx1;
    val = val1;
    tpath = path;
  }
};

vector<int> DP;
int lis(vector<int> &vec)
{
  int n = vec.size();
  vector<int> dp(n, 1);
  if (n == 0)
  {
    return 0;
  }
  int ans = -1;
  int l = 1;
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (vec[i] > vec[j])
      {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    if (l < dp[i])
    {
      l = dp[i];
      ans = i;
    }
  }
  for (int &i : dp)
  {
    cout << i << " ";
  }
  cout << endl;
  DP = dp;
  return ans;
}
void printpath(vector<int> vec, int d)
{
  queue<path *> que;
  que.push(new path(DP[d], d, vec[d], to_string(vec[d])));
  while (que.size())
  {
    path *rem = que.front();

    que.pop();
    if (rem->idx == 0)
    {
      cout << rem->tpath << endl;
    }
    string step = rem->tpath;
    for (int i = rem->idx - 1; i >= 0; i--)
    {
      if (rem->rem == DP[i] + 1 && rem->val >= vec[i])
      {
        string k = to_string(vec[i]) + " " + step;
        que.push(new path(DP[i], i, vec[i], k));
      }
    }
  }
}
int main()
{
  // vector<int> vec={5, 8, 3, 7, 9, 1};
  // vector<int> vec={22, 34, 36, 30};
  vector<int> vec = {10, 22, 331, 41, 601, 801};
  int d = lis(vec);

  printpath(vec, d);
  return 0;
}