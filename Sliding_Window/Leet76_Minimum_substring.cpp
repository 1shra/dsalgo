#include<iostream>
#include<map>
using namespace std;
string sub(string s,string p){
  map<char,int> mp;
  for(int i=0;i<p.length();i++){
    mp[p[i]]++;
  }
  int a=p.length();
  int count=0;
  int minsize=99999;
  int start=0;
  int l=-1;
  for(int i=0;i<s.length();i++){
    if(mp.find(s[i])!=mp.end()){
        if(mp[s[i]]>0){
          count++;
          while(count==a){
          if(minsize>i-start+1){
            minsize=i-start+1;
            l=start;
          }
          mp[s[start]]++;
          if(mp[s[start]]>0){
            count--;
          }
          start++;
        }
      }   
    }
    mp[s[i]]--;
  }
  if(l==-1){
    return "";
  }
  return s.substr(l,minsize);
}

int main(){
  string s="TOXIC";
  string p = "TX";
  string l = sub(s,p);  
  cout<<l;
  return 0;
}