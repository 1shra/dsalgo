/*
link: https://www.codechef.com/problems/APPROVAL
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
    int n = 5;
    vector<int> vec;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      vec.push_back(a);
      sum += a;
    }
    int avg = sum / 5;
    if (avg >= 7)
    {
      cout << 0 << endl;
      continue;
    }
    sort(vec.begin(), vec.end());
    int price = 0;
    for (int i = 0; i < n; i++)
    {
      int b = 10 - vec[i];
      sum += b;
      avg = sum / 5;
      price++;
      if (avg >= 7)
      {
        break;
      }
    }
    cout << price * 100 << endl;
  }
  return 0;
}
