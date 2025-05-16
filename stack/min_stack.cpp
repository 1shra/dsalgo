#include<iostream>
#include<stack>
using namespace std;

class stac{
  stack<pair<int,int>> st;

  void pus(int x){
    if(st.empty()){
      st.push({x,x});
    }
    else{
      st.push({x,min(x,st.top().second)});
    }
  }
  int getmin(){
    return st.top().second;
  }
  int top(){
    return st.top().first;
  }
}


int main(){
  
  cout<<getmin();
  return 0;
}