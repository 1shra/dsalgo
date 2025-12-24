#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
      cin>>vec[i];
    }
    int l =vec[k-1];
    sort(vec.begin(),vec.end());
    for(int i = 0; i < n; i++){
        if(vec[i] == l){
            k = i;
        }
    }
    int wl  = 0;
    bool ans = false;
    for(int i = k; i < n-1; i++){
        wl += abs(vec[i]-vec[i+1]);
        if(wl > vec[i]){
            ans = 1;
            break;
        }
    }

    if(ans){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
  }
}