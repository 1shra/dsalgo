#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  ll t;
  cin >> t;
  while (t--)
  {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(k);
    for (ll i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    for (ll j = 0; j < k; j++)
    {
      cin >> b[j];
    }

    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    ll ans = 0;
    int r = 0;

    for (int i = 0; i < k; i++)
    {
      int sz = b[i];
      for (int j = 0; j < sz-1&&r!=n; j++)
      {
        ans += a[r];
        r++;
      }
      if(r<n){
        r++;
      }
    }
    for (ll i = r; i < n; i++)
    {
      ans += a[i];
    }
    cout << ans << endl;
  }
}