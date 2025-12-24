#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while (t--) {
    int n,k;
    cin>>n>>k;

    vector<int> value(n);
    vector<pair<pair<int, int>, int>> vec;

    for (int i=0;i<n;i++) {
      int a,b,c;
      cin>>a>>b>>c;
      vec.push_back({{a, b}, i});  
      value[i]=c;
    }

    sort(vec.begin(), vec.end());

    for (int i=0;i<n;i++) {
      int l =vec[i].first.first;
      int r =vec[i].first.second;
      int idx =vec[i].second;

      if (l <=k && r >=k) { 
        if (value[idx] >k) {
          k =value[idx];
        }
      }
    }
    cout<<k<<endl;
  }
}
