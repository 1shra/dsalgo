#include<bits/stdc++.h>
using namespace std;

class Play{
  public:
  Play(){
    cout<<"Constructor is called"<<endl;
  }
  ~Play(){
    cout<<"Destructor is called"<<endl;
  }
};


int main(){
  // {
  //   Play *p= new Play();
  //   delete p;
  // }
  {
    Play p;
  }
  cout<<"Hello"<<endl;
}