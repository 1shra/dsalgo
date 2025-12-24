#include <bits/stdc++.h>
using namespace std;


// Here’s a class. Try to write a friend function that prints the balance.

// class BankAccount
// {
// private:
//   int balance;

// public:
//   BankAccount() { balance = 1000; }

//   friend void printbalance(BankAccount);
// };
// // 🔲 Define the friend function here void printbalance(BankAccount b){
// void printbalance(BankAccount b)
// {
//   cout << b.balance << endl;
// }




// 🧩 Challenge: Write a Friend Function to Compare Two Private Values

// You have a class Score with a private variable marks.
// Write a friend function called compareScores that compares the marks of two Score objects and prints which one is higher.

class Score {
private:
    int marks;

public:
    Score(int m) { marks = m; }

    // 🔲 Declare the friend function here
    friend void compareScore(Score,Score);
};

void compareScore(Score m,Score n){
  if(m.marks>n.marks){
    cout<<m.marks<<endl;
  }
  else{
    cout<<n.marks<<endl;
  }
}

int main() {
    Score s1(85), s2(90);
    compareScore(s1, s2);
    return 0;
}

