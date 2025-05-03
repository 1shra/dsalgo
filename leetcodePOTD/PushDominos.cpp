// 4/3/2025 Leetcode POTD
// link: https://leetcode.com/problems/push-dominoes/description/?envType=daily-question&envId=2025-05-02

#include<iostream>
#include<vector>
using namespace std;
vector<int> rightpos(string dom){
  int n = dom.length();
  int a =-1;
  vector<int> res(n,0);
  for(int i=0;i<n;i++){
      if(dom[i]=='R'){
          a=i;
      }
      else if(dom[i]=='L'){
          a=-1;
      }
      res[i]=a;
      
  }
  return res;
}
vector<int> leftpos(string dom){
  int n = dom.length();
  int a = -1;
  vector<int> res(n,0);
  for(int i=n-1;i>=0;i--){
      if(dom[i]=='L'){
          a=i;
      }
      if(dom[i]=='R'){
          a=-1;
      }
      res[i]=a;
  }
  return res;
}
string pushDominoes(string dom) {
  vector<int> right = rightpos(dom);
  vector<int> left = leftpos(dom);
  // for(int i:right){
  //     cout<<i<<" ";
  // }
  // cout<<endl;
  // for(int j:left){
  //     cout<<j<<" ";
  // }
  int n = dom.length();
  for(int i=0;i<n;i++){
      if(dom[i]=='.'){

          int r = right[i];
          int l = left[i];
          if(r==l){
              continue;
          }
          else if(r==-1){
              dom[i]='L';
          }
          else if(l==-1){
              dom[i]='R';
          }
          else if((abs(i-r)>abs(i-l))){
              dom[i]='L';
          }
          else if(abs(i-r)<abs(i-l)){
              dom[i]='R';
          }
      }
  }
  return dom;
}
int main(){
  int n;
  cin>>n;
  vector<string> vec(n);
  while(n){
    string domino ="";
    cin>>domino;
    vec.push_back(pushDominoes(domino));
    n--;
  }
  for(string i:vec){
    cout<<i<<endl;
  }
  return 0;
}
