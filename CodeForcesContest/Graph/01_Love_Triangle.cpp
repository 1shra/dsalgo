#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> vec(n+1);
  for (int i = 1; i <= n; i++)
  {
    cin>>vec[i];
  }
  for(int i=1;i<=n;i++){
    int a,b,c;
    a=vec[i];
    b=vec[a];
    c=vec[b];
    if(vec[c]==a&&a!=b&&b!=c&&c!=a){
      cout<<"Yes";
      return 0;
    }
  }
  
  cout<<"NO";
}