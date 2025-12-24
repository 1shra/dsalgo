//LINK:- https://codeforces.com/contest/2162/problem/C
#include <bits/stdc++.h>
using namespace std;

string decToBinary(int n)
{
  string a = "";
  while (n > 0)
  {
    int r = n % 2;
    n /= 2;
    a=to_string(r)+a;
  }
  return a;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int a, b;
    cin >> a >> b;

    if (a == b)
    {
      cout << 0 << endl;
      continue;
    }
    string ba = decToBinary(a);
    string bb = decToBinary(b);
    // cout << ba << endl;
    // cout << bb;
    if(ba.length()<bb.length()){
      cout<<-1<<endl;
      continue;
    }

    for(int i=0;i<(ba.size()-bb.size());i++){
      bb='0'+bb;
    }
    vector<int> ans;
    int flag=1;
    for(int i=ba.size()-1;i>=0;i--){
      if(ba[i]==bb[i]){
        continue;
      }
      else{
        int x = 1<<(ba.size()-i-1);
        if(x>a){
          flag=0;
          cout<<-1<<endl;
          break;
        }
        a=a^x;
        ans.push_back(x);
      }
    }
    if(flag)
      cout<<ans.size()<<endl;
      for(int i:ans){
        cout<<i<<" ";
      }
      cout<<endl;
  }
}