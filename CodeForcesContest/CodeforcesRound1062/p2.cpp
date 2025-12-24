#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    map<char,int>mp;
    for(char i:a){
      mp[i]++;
    }
    int flag=1;
    for(char i:b){
      if(mp.find(i)!=mp.end()){
        mp[i]--;
        if(mp[i]==0){
          mp.erase(i);
        }
      }
      else{
        flag=0;
      }
    }
    string z = flag?"Yes":"No";
    cout<<z<<endl;
  }
  return 0;
}