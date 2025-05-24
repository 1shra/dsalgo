#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int a;
    cin >> a;
    vector<int> vec;
    for (int i = 0; i < a; i++)
    {
      int c;
      cin >> c;
      vec.push_back(c);
    }
    sort(vec.begin(), vec.end());
    int ans = 51;
    for (int i = 0; i < a; i++)
    {
      int cnt = i;
      for (int j = a - 1; j >= 0; j--)
      {
        if ((vec[i] + vec[j]) % 2 == 0)
        {
          ans = min(cnt, ans);
        }
        else
        {
          cnt++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}