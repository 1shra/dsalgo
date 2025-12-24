// Try this:

// Define two classes, Engine and Car.

// Make Engine a friend class of Car.

// Give Car a private member speed.

// Write a method inside Engine that accesses and prints Car’s private speed.

// You don’t need full syntax for main() — just the class definitions and the friend declaration + function.

// Go ahead and give it a shot! I’ll help you polish it.



#include<bits/stdc++.h>
using namespace std;
class Car{
  private:
    int speed;
  public:
    void getSpeed(int a){
      speed = a;
    }
    friend class Engine;
};

class Engine{
  public:
    void showSpeed(Car& c){
      cout<<c.speed<<endl;
    }
};

int main() {
    Car c;
    c.getSpeed(100);  // set speed
    Engine e;
    e.showSpeed(c);   // prints 100
    return 0;
}
