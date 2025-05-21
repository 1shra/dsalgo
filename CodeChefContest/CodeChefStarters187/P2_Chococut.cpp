// Problem 2:
// Link: https://www.codechef.com/problems/CHOCUT

#include <bits/stdc++.h>
using namespace std;

int main()
{
  // your code goes here
  int t;
  cin >> t;
  while (t--)
  {
    int n, m, k;
    cin >> n >> m >> k;
    int a = n * m;
    if (n * m < k)
    {
      cout << 0 << endl;
      continue;
    }
    int l = 0;
    while (k > l)
    {
      l += n;
    }
    int o = 0;
    while (k > o)
    {
      o += m;
    }
    // cout<<o<<" "<<l<<" ";
    if (l < o)
    {
      if (a < l)
      {
        cout << 0 << endl;
        continue;
      }
      cout << a - l << endl;
      continue;
    }
    else
    {
      if (a < o)
      {
        cout << 0 << endl;
        continue;
      }
      cout << a - o << endl;
      continue;
    }
  }
}
