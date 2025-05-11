#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
      int val;
      cin >> val;
      vec.push_back(val);
    }
    int gre = ((n + 1) / 2) - 1;

    long long a = vec[0];
    long long b = vec[0] * -1;
    int p = 0, q = 0;
    int ans=0;
    for (int i = 1; i < n; i++)
    {
      long long vali = vec[i];
      long long negvali = (vec[i] * -1);
      if (vali < a && negvali < a)
      {
        p++;
      }
      else if (vali > a && negvali > a)
      {
      }
      else
      {
        q++;
      }
    }
    if (p <= gre && gre <= p + q)
    {
      ans=1;
    }
    p=0,q=0;
    for (int i = 1; i < n; i++)
    {
      long long vali = vec[i];
      long long negvali = vec[i] * -1;
      if (vali < b && negvali < b)
      {
        p++;
      }
      else if (vali > b && negvali > b)
      {
        continue;
      }
      else
      {
        q++;
      }
    }
    if (ans||(p <= gre && gre <= p + q))
    {
      cout << "Yes" << endl;
      continue;
    }
    cout << "No" << endl;
  }
  return 0;
}