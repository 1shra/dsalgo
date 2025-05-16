#include<iostream>
using namespace std;

/*My approach*/
// string st(string s,int n){
//   if(n==0){
//     string l;
//     return l;
//   }
//   string a = st(s,n-1);
//   a= s[n-1] + a;
//   return a;  
// }
// int main(){
//   string s = "Ashraf Ali";
//   string k = st(s,s.length());
//   for(int i=0;i<s.length();i++){
//     cout<<k[i];
//   }
//   return 0;
// }


/*Approch 2*/

void reverse(string &s,int l,int h){
  if(l<h){
    swap(s[l],s[h]);
    reverse(s,l+1,h-1);
  }
}
int main(){
  string str = "Ashraf Ali";
  reverse(str,0,str.length()-1);
  cout<<str;
  return 0;
}