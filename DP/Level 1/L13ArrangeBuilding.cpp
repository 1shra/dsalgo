#include<iostream>
using namespace std;
long long arrange(int b){
    int ob=1;
    int os=1;
    for(int i=2;i<=b;i++){
        int ns=ob+os;
        int nb=os;
        os=ns;
        ob=nb;
    }
    int total = ob+os;
    return total*total;
}

int main(){
    int a;
    cin>>a;
    cout<<arrange(a);
}