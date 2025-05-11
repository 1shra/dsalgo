/*
A. LRU and VIP
*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  while (n--)
  {
    int k;
    cin >> k;
    vector<int> vec;
    int ma = 0;
    int mi = INT_MAX;
    for (int i = 0; i < k; i++)
    {
      int l;
      cin >> l;
      ma = (l > ma) ? l : ma;
      mi = (l < mi) ? l : mi;
      vec.push_back(l);
    }
    if (ma == mi)
    {
      cout << "No" << endl;
      continue;
    }
    else
    {
      cout << "Yes" << endl;
      for (int i = 0; i < k; i++)
      {
        if (vec[i] == ma)
        {
          cout << "1" << " ";
        }
        else
        {
          cout << "2" << " ";
        }
      }
    }
  }
}