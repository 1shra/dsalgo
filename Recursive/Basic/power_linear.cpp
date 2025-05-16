#include<iostream>
using namespace std;
long int power_linear( int x,int n){
    if(n<=0){
        return 1;
    }
    return x*power_linear(x,n-1);
}
int main(){
    cout<<power_linear(11,13);
}