#include <iostream>
using namespace std;

int cntbit(int x)
{
  int bits = 0;
  while (x > 0)
  {
    bits++;
    x >>= 1;
  }
  return bits;
}

bool ispal(int x)
{
  int bits = cntbit(x);
  for (int i = 0; i < bits / 2; ++i)
  {
    if (((x >> i) & 1) != ((x >> (bits - 1 - i)) & 1))
      return false;
  }
  return true;
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    if (n == 0)
    {
      cout << "YES\n";
      continue;
    }

    int lastZeroCnt = 0;
    while ((n >> lastZeroCnt) % 2 == 0)
    {
      lastZeroCnt++;
    }

    bool check = false;

    for (int shift = 0; shift <= lastZeroCnt; ++shift)
    {
      int shiftedNum = n >> shift;

      if (ispal(shiftedNum))
      {
        int bits = cntbit(shiftedNum);
        if (bits % 2 == 1 && ((shiftedNum >> (bits / 2)) & 1) != 0)
        {
          continue;
        }

        check = true;
        break;
      }
    }

    if (check)
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }

  return 0;
}
