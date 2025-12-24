#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    string b;
    cin>>b;
    int l=0,h=n-1;
    map<int,int> mp;
    for(char i:b){
      mp[i-'0']++;
    }
    int cnt0=mp[0];
    int cnt1=mp[1];
    int cnt2=mp[2];
    string a="";
    for(int i=0;i<n;i++){
      a+='+';
    }
    for(l;l<cnt0;l++){
      a[l]='-';
    }
    // cout<<a<<endl;
    for(h;h>=0&&cnt1;h--){
      a[h]='-';
      cnt1--;
    }
    // cout<<a<<endl;
    int remelem = h-l+1;
    if(remelem==cnt2&&cnt2!=0){
      while(l<=h){
        a[l]='-';
        a[h]='-';
        l++;
        h--;
      }
    }
    else{
      while(l<=h&&cnt2){
        a[l]='?';
        a[h]='?';
        l++;
        h--;
        cnt2--;
      }
    }
    cout<<a<<endl;
  }
  return 0;
}