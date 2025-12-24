#include<iostream>
#include<memory>
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
  unique_ptr<Play> p = make_unique<Play>();
  cout<<"Hello"<<endl;
}