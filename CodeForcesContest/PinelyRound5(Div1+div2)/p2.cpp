#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
   int t;
  cin >> t;
  while (t--)
  {
    int  n;
    ll x;
    cin >>  n >> x;
    vector<ll>  vec( n);
    ll total = 0;
    for (int i = 0; i <  n; ++i)
    {
      cin >>  vec[i];
      total +=  vec[i];
    }
    ll l = total / x;
    sort( vec.begin(),  vec.end());
    ll  bon = 0;
    for (int i =  n - l; i <  n; ++i)
    {
       bon +=  vec[i];
    }
    cout <<  bon << '\n';
    vector<ll>  ord;
    ll  s = 0;
    int left = 0, right =  n - 1;
    for (int i = 0; i <  n; ++i)
    {
      ll  r =  s % x;
      ll d = ( r == 0 ? x : x -  r);
      if (left <= right &&  vec[left] < d)
      {
         ord.push_back( vec[left]);
         s +=  vec[left];
        ++left;
      }
      else
      {
         ord.push_back( vec[right]);
         s +=  vec[right];
        --right;
      }
    }

    for (int i = 0; i <  n; ++i)
    {
      cout <<  ord[i];
      if (i + 1 <  n)
        cout << " ";
      else
        cout << '\n';
    }
  }
  return 0;
}
