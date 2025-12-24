#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    string s;
    cin >> n >> s;
    bool flag1 = false;
    int dig = 1<<n;
    for (int l = 0; l < dig; ++l)
    {
      string a = "", b = "";
      vector<int> ans;
      for (int i = 0; i < n; ++i)
      {
        if (l & (1<<i))
        {
          a.push_back(s[i]);
          ans.push_back(i + 1);
        }
        else
          b.push_back(s[i]);
      }
      bool flag2 = true;
      for (int i = 1; i < (int)a.size(); ++i)
        if (a[i] < a[i - 1])
        {
          flag2 = false;
          break;
        }
      if (!flag2)
        continue;
      for (int i = 0; i < (int)b.size() / 2; ++i)
        if (b[i] != b[b.size() - 1 - i])
        {
          flag2 = false;
          break;
        }
      if (!flag2)
        continue;
      cout<<ans.size()<<"\n";
      if (!ans.empty())
      {
        for (size_t i = 0; i < ans.size(); ++i)
        {
          if (i)
            cout<<' ';
          cout<<ans[i];
        }
        cout <<endl;
      }
      else
        cout <<endl;
      flag1 = true;
      break;
    }
    if (!flag1)
      cout<<"-1"<<endl;
  }
  return 0;
}
