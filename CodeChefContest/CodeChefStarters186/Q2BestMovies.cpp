/*
link: https://www.codechef.com/problems/BESTMOVIE
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  // your code goes here
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    // vector<pair<int,int>> vec;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      int a, b;
      cin >> a >> b;
      if (a >= 7)
      {
        ans = min(ans, b);
      }
    }
    if (ans == INT_MAX)
    {
      cout << -1 << endl;
      continue;
    }
    cout << ans << endl;
  }
  return 0;
}
