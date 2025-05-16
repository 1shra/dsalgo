#include<iostream>
using namespace std;
void toh(int n,char t1,char t2,char t3){
    if(n==0){
        return;
    }
    toh(n-1,t1,t3,t2);
    cout<<n<<"["<<t1<<" ->"<<t2<<"] "<<endl;
    toh(n-1,t3,t2,t1);
}



int main(){
    int disk=2;
    char t1 = 'A';
    char t2 = 'B';
    char t3 = 'C';
    toh(disk,t1,t2,t3);
}