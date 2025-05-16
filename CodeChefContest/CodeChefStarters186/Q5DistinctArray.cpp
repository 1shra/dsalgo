/*
link: https://www.codechef.com/problems/DISTARR
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
  // your code goes here
  int mod = 998244353;
  int t;
  cin >> t;
  while (t--)
  {
    int a;
    cin >> a;
    vector<int> vec;
    for (int i = 0; i < a; i++)
    {
      int d;
      cin >> d;
      vec.push_back(d);
    }
    sort(vec.begin(), vec.end());
    long long int product = 1;
    for (int i = 0; i < a; i++)
    {
      product = (product * (vec[i] - i)) % mod;
    }
    cout << product % mod << endl;
  }
}
