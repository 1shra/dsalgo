#include <iostream>
#include <vector>
using namespace std;

class chai
{
public:
  string *teaName;
  int servings;
  vector<string> ingredients;
  // defualt constructor
  //  chai(){
  //    cout<<"Constuctor Called"<<endl;
  //  }
  //  chai(){
  //    teaName= "Unkown Tea";
  //    servings = 1;
  //    ingredients = {"Water", "Tea Leaves"};
  //    cout<<"consutor called"<<endl;
  //  }

  // Parameter Consturctor
  chai(string t, int s, vector<string> ing)
  {
    teaName = new string(t);
    servings = s;
    ingredients = ing;
    cout << "Param constructor called" << endl;
  }

  // copyConstructor
  chai(chai &other)
  {
    teaName = new string(*other.teaName);
    servings = other.servings;
    ingredients = other.ingredients;
    cout << "Copy Constructor Called" << endl;
  }

  ~chai()
  {
    delete teaName;
    cout << "destructor called" << endl;
  }

  void displayChaiDetails()
  {
    cout << "Tea Name: " << *(teaName) << endl;
    cout << "Serving: " << servings << endl;
    cout << "Ingredients: ";
    for (string ingredient : ingredients)
    {
      cout << ingredient << " ";
    }
    cout << endl;
  }
};
int main()
{
  // chai defaultChai;
  // defaultChai.displayChaiDetails();
  cout << endl;
  chai paramenterTea("Lemon Tea", 2, {"water", "Lemon", "Honey"});
  // paramenterTea.displayChaiDetails();

  // COPY THE OBJECT
  chai copyChai = paramenterTea;
  // copyChai.displayChaiDetails();

  *paramenterTea.teaName = "Modified Lemon tea";

  cout << endl;
  cout << *copyChai.teaName << endl;
  cout << *paramenterTea.teaName << endl;
  return 0;
}