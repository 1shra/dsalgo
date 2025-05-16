#include<iostream>
#include<vector>
using namespace std;
int numberofWay(int n){
    if(n<4){
        return n;
    }
    vector<int> vec(n+1);
    vec[0]=0;
    vec[1]=1;
    vec[2]=2;
    for(int i=3;i<=n;i++){
        vec[i]=vec[i-1]+vec[i-2];
    }
    return vec[n];
}
int main(){
    cout<<numberofWay(5);
}