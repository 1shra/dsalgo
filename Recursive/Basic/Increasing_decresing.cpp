#include<iostream>
using namespace std;
void ptr(int i){
    if(i==0){
        return;
    }
    cout<<i<<endl;
    ptr(i-1);
    cout<<i<<endl;
}
int main(){
    ptr(5);
}