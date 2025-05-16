// Find all binary strings that can be formed from a wildcard pattern


/*
Given a binary pattern containing ? wildcard character at a few positions, find all possible combinations of binary strings that can be formed by replacing the wildcard character by either 0 or 1.
*/
#include<iostream>
using namespace std;
void printAllCombinatioins(string pattern,int i,int n){
  if(pattern[i]==n){
    for(int i=0;i<pattern.length();i++){
      cout<<pattern[i];
    }
    cout<<endl;
    return;
  }
  if(pattern[i]=='?'){
    for(int k=0;k<2;k++){
      pattern[i]=k+'0';
      printAllCombinatioins(pattern,i+1,n);
      pattern[i]='?';
    }
    return;
  }
  printAllCombinatioins(pattern,i+1,n);
}
// 
int main(){
  string pattern = "1?11?00?1?";
  printAllCombinatioins(pattern,0,pattern.length());
  return 0;
}


#include<iostream>
using namespace std;
void printCombinatioin(string  pattern ,int i){
  if(pattern[i]=='\0'){
    cout<<pattern<<endl;
    return;
  }
  if(pattern[i] =='?'){
    for(int k=0;k<2;k++){
      pattern[i]='0'+k;
      printCombinatioin(pattern,i+1);
    }
    return;
  }
  printCombinatioin(pattern,i+1);
}

int main(){
  string pattern = "1?11?00?1?";
  printCombinatioin(pattern, 0);
  return 0;
}