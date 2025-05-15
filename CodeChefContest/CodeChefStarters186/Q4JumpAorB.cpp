/*
link: https://www.codechef.com/problems/JUMPAB
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
    long long n, m, c, d;
    cin >> n >> m >> c >> d;
    if (c == d)
    {
      if ((n * c) == m)
      {
        cout << "Yes";
      }
      else
      {
        cout << "No";
      }
      cout << endl;
      continue;
    }
    long long dif = c - d;
    long long num = m - n * d;
    if (num % dif != 0)
    {
      cout << "No" << endl;
      continue;
    }
    long long x = num / dif;
    if (x >= 0 && x <= n)
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }
}
