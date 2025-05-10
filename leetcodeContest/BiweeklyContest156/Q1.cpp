/*
3541. Find Most Frequent Vowel and Consonant
*/
#include<iostream>
#include<map>
using namespace std;

int maxFreqSum(string s) {
  map<int,int> vow;
  map<char,int>cons;
  for(int i=0;i<s.length();i++){
    if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
      vow[s[i]]++;
    }
    else{
      cons[s[i]]++;
    }
  }

  int mxcon=0;
  int mxvow=0;

  for(auto &i:vow){
    mxvow = max(mxvow,i.second);
  }
  for(auto &i:cons){
    mxcon = max(mxcon,i.second);
  }
  return mxcon+mxvow;
}
int main(){
  string k; 
  cin>>k;
  cout<<maxFreqSum(k)<<endl;
}