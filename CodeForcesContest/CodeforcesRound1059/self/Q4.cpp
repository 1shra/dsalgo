#include <bits/stdc++.h>
using namespace std;

void query(int type, int l, int r)
{
  cout << type << " " << l << " " << r << endl;
  cout.flush();
}
int diff(int l, int r)
{
  int a, b;
  query(1, l + 1, r + 1);
  cin >> a;
  query(2, l + 1, r + 1);
  cin >> b;
  return b - a;
}
int main()
{
  int n;
  cin >> n;

  int start, end;
  {
    int low = 0, high = n - 1;
    while (low < high)
    {
      int mid = (low + high) / 2;
      if (diff(0, mid))
      {
        high = mid;
      }
      else
      {
        low = mid + 1;
      }
    }
    start = low;
  }
  // cout<<start<<endl;

  query(2, 1, n);
  int temp;
  cin >> temp;
  end = start + (temp - n * (n + 1) / 2 - 1);
  cout << "! " << start + 1 << " " << end + 1 << endl;
  return 1;
}
