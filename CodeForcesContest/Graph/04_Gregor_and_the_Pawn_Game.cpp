#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int t;
  cin >> t;
  while (t--)
  {
    int s;
    string s1, s2;
    cin >> s >> s1 >> s2;
    int count = 0;
    for (int i = 0; i < s; i++)
    {
      if (s2[i] == '1')
      {
        if (i - 1 >= 0&&s1[i-1]=='1')
        {
          
            // cout<<1<<i<<endl;
            count++;
            s1[i-1] = '0';
          
        }
        else if (s1[i] == '0')
        {
          // cout<<2<<i<<endl;
          count++;
        }
        else
        {
          if (i + 1 < s)
          {
            if (s1[i + 1] == '1')
            {
              // cout<<3<<i<<endl;
              s1[i + 1] = '0';
              count++;
            }
          }
        }
      }
    }
    cout << count << endl;
  }
}
int main()
{
  solve();
  return 0;
}