#include<bits/stdc++.h>
using namespace std;


int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string a;
    cin>>a;
    map<char,int> mp;
    for(char i:a){
      mp[i]++;
    }
    if(mp['a']==mp['b']){
      cout<<0<<endl;
      continue;
    }
    char curr=a[0];
    int cnt=0;
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
      if(a[i]==curr){
        cnt++;
      }
      else{
        int cnta=mp['a'];
        int cntb=mp['b'];
        if(curr=='a'){
          cnta-=cnt;
        }
        else{
          cntb-=cnt;
        }
        
        // cout<<cnta<<" "<<cntb<<" "<<cnt<<" "<<curr<<endl;
        if(cnta==cntb){
          ans=min(ans,cnt);
        }
        cnt=1;
        curr=a[i];
      }
    }
    if(ans==INT_MAX){
      cout<<-1<<endl;
    }
    else{
      cout<<ans<<endl;
    }
  } 
}