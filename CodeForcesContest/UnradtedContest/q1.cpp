#include <bits/stdc++.h>
using namespace std;

int main()
{
  string a;
  cin >> a;
  if (a == "first")
  {
    int c;
    cin >> c;
    while(c--){
      int d;
      cin>>d;
      cout<<char(d+'a'-1);
    }
  }
  else
  {
    string d;
    cin >> d;
    int n = d.length();
    cout<<n<<endl;
    for (char i : d)
    {
      cout << (i - 'a'+1) << " ";
    }
  }
  return 0;
}