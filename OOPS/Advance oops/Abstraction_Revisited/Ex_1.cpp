// Question:
// Problem: Create an abstract class Vehicle with pure virtual functions and implement concrete classes.

// Requirements:
// Create an abstract class Vehicle with:
// Pure virtual function start()
// Pure virtual function stop()
// Pure virtual function getInfo()
// Concrete function honk() that prints "Beep beep!"
// Create concrete classes Car and Motorcycle that inherit from Vehicle
// Each should implement the pure virtual functions appropriately

/*

#include <iostream>
#include <string>
using namespace std;

// Your Vehicle abstract class here
class Vehicle{
  public:
  virtual void start()=0;
  virtual void stop()=0;
  virtual void getInfo()=0;

  void honk() const {
    cout<<"Beep Beep"<<endl;
  }
};

// Implement Car and Motorcycle classes
class Car:public Vehicle{
  protected:
    string name;
    string model;
    int year;
  public:
  Car(string name,string model,int year):name(name),model(model),year(year){};
  void start() override{
    cout<<"Car "<<name<<" engine is Started"<<endl;
  }
  void stop() override{
    cout<<"Car "<<name<<" engine is Stop"<<endl;
  }
  void getInfo() override{
    cout<<"Car name: "<<name<<", Model name: "<<model<<", year: "<<year<<endl;
  }
};

class Motorcycle:public Vehicle{
  private:
    string name;
    string model;
    int year;
  public:
    Motorcycle(string name,string model,int year):name(name),model(model),year(year){};
    void start() override{
      cout<<"Bike "<<name<<" engine is started"<<endl;
    }
    void stop() override{
      cout<<"Bike "<<name<<" engine is stop"<<endl;
    }
    void getInfo() override{
      cout<<"Bike name: "<<name<<", Model Name: "<<model<<", year: "<<year<<endl;
    }
};


int main() {
    // Test your implementation
    // Vehicle v; // This should cause error
    
    Car car("Toyota", "Camry", 2020);
    Motorcycle bike("Harley", "Davidson", 2022);
    
    car.start();
    car.getInfo();
    car.honk();
    car.stop();
    
    cout << "-------------------" << endl;
    
    bike.start();
    bike.getInfo();
    bike.honk();
    bike.stop();
    
    return 0;
}
*/

// Minor Imporvements/Suggestions
/*
1. Add a virtual destructor in the base class (good practice):
class Vehicle {
public:
    virtual ~Vehicle() = default;  // Add this
    virtual void start() = 0;
    // ... rest of your code
};


2. Consider moving common attributes to base class (optional but good design):
class Vehicle {
protected:  // protected so derived classes can access
    string name;
    string model; 
    int year;
    
public:
    Vehicle(string n, string m, int y) : name(n), model(m), year(y) {}
    virtual ~Vehicle() = default;
    // ... rest of your code
};

class Car : public Vehicle {
public:
    Car(string n, string m, int y) : Vehicle(n, m, y) {}  // simpler!
    // ... methods can now use name, model, year directly
};

*/

// Grading



// correcting mistake
#include <iostream>
#include <string>
using namespace std;

// Your Vehicle abstract class here
class Vehicle{
  private:
    string name,model;
    int year;
    public:
    Vehicle(string name,string model,int year):name(name),model(model),year(year){}
    virtual ~Vehicle()=default;
    virtual void start()=0;
    virtual void stop()=0;
  virtual void getInfo()=0;

  void honk() const {
    cout<<"Beep Beep"<<endl;
  }
};

// Implement Car and Motorcycle classes
class Car:public Vehicle{
  protected:
    string name;
    string model;
    int year;
  public:
  Car(string name,string model,int year):Vehicle(name,model,year){}
  void start() override{
    cout<<"Car "<<name<<" engine is Started"<<endl;
  }
  void stop() override{
    cout<<"Car "<<name<<" engine is Stop"<<endl;
  }
  void getInfo() override{
    cout<<"Car name: "<<name<<", Model name: "<<model<<", year: "<<year<<endl;
  }
};

class Motorcycle:public Vehicle{
  private:
    string name;
    string model;
    int year;
  public:
    Motorcycle(string name,string model,int year):Vehicle(name,model,year){}
    void start() override{
      cout<<"Bike "<<name<<" engine is started"<<endl;
    }
    void stop() override{
      cout<<"Bike "<<name<<" engine is stop"<<endl;
    }
    void getInfo() override{
      cout<<"Bike name: "<<name<<", Model Name: "<<model<<", year: "<<year<<endl;
    }
};


int main() {
    // Test your implementation
    // Vehicle v; // This should cause error
    
    Car car("Toyota", "Camry", 2020);
    Motorcycle bike("Harley", "Davidson", 2022);
    
    car.start();
    car.getInfo();
    car.honk();
    car.stop();
    
    cout << "-------------------" << endl;
    
    bike.start();
    bike.getInfo();
    bike.honk();
    bike.stop();
    
    return 0;
}