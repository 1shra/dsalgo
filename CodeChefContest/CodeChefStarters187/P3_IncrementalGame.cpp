// Problem 3:
// Link: https://www.codechef.com/problems/INCGAME

#include <bits/stdc++.h>
using namespace std;

int main()
{
  // your code goes here
  int t;
  cin >> t;
  while (t--)
  {
    int x, y, k;
    cin >> x >> y >> k;
    int win = 1;
    for (int i = 1; i <= k; i++)
    {
      if (i <= x)
      {
        int remx = x - i;
        int pile = y;
        if (remx <= i && pile <= i)
        {
          cout << "Alice" << endl;
          win = 0;
          break;
        }
      }
      if (i <= y)
      {
        int remy = y - i;
        int pile = x;
        if (remy <= i && pile <= i)
        {
          cout << "Alice" << endl;
          win = 0;
          break;
        }
      }
    }
    if (win)
    {
      cout << "Bob" << endl;
    }
  }
}
