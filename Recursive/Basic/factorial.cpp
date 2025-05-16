#include<iostream>
using namespace std;
int fact(int i){
    if(i==1||i<=0){
        return 1;
    }

    return i*fact(i-1);
}


int main(){
    cout<<fact(5);
}