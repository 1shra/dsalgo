#include <bits/stdc++.h>
using namespace std;

void solveTestCase()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> ones, zeros;

  for (int i = 0; i < n; ++i)
  {
    if (s[i] == '1')
    {
      ones.push_back(i + 1);
    }
    else
    {
      zeros.push_back(i + 1);
    }
  }

  if (ones.empty())
  {
    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
    {
      cout << i << " ";
    }
    cout << "\n";
    return;
  }

  vector<int> result(n);
  int a = 0, b = 0;

  for (int i = 0; i < n; ++i)
  {
    if ((i % 2 == 0 && a < ones.size()) || b >= zeros.size())
    {
      result[i] = ones[a++];
    }
    else
    {
      result[i] = zeros[b++];
    }
  }

  cout << "YES\n";
  for (int x : result)
  {
    cout << x << " ";
  }
  cout << "\n";
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    solveTestCase();
  }

  return 0;
}
