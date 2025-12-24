//code to check valid parenthesis

#include<iostream>
using namespace std;
bool check(string s){
  int cnt=0;
  for(char i:s){
    if(i=='('){
      cnt++;
    }
    else{
      cnt--;
    }
  }
  return (cnt==0);
}
int main(){
  string s = "(())(()";
  cout<<check(s);
  return 0;
}