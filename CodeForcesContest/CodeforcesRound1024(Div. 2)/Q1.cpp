#include <iostream>
using namespace std;

int main()
{
  int K;
  cin >> K;
  while (K--)
  {
    int n, m, q, p;
    cin >> n >> m >> q >> p;
    if (n % q == 0)
    {
      if (((n / q) * p )!= m)
      {
        cout << "No" << endl;
        continue;
      }
    }
    cout << "Yes" << endl;
  }
  return 0;
}