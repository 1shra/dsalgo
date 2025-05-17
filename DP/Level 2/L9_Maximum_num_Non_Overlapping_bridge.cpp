#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int MaxNonOverlappingBridge(vector<int> &north, vector<int> &south, int n)
{
  vector<pair<int, int>> p;
  for (int i = 0; i < north.size(); i++)
  {
    p.push_back({north[i], i});
  }

  sort(p.begin(), p.end());
  // for(auto i:p){
  //   cout<<'{'<<i.first<<','<<i.second<<'}'<<endl;
  // }
  int ans = 0;
  vector<int> dp(n, 1);
  for (int i = 1; i < n; i++)
  {
    int j = south[p[i].second];
    int count = 0;

    for (int k = i - 1; k >= 0; k--)
    {
      int l = south[p[k].second];
      if (l < j)
      {
        count = max(count, dp[k]);
      }
    }
    dp[i] = count + 1;
    ans = max(ans, dp[i]);
  }
  return ans;
}

int main()
{
  int n = 10;
  vector<int> north = {10, 2, 8, 17, 21, 50, 41, 60, 80, 1};
  vector<int> south = {20, 7, 15, 3, 40, 4, 57, 80, 90, 30};
  cout << MaxNonOverlappingBridge(north, south, n);
}