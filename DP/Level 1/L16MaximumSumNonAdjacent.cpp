#include<iostream>
using namespace std;
int DpMax(int arr[],int n){
    int a = arr[0];
    int b = arr[1]>a?arr[1]:a;
    for (int i = 2; i < n; i++)
    {
        int c = a+arr[i];
        arr[i]= b>c?b:c;
        a=b;
        b=arr[i];
    }
    return arr[n-1];
}
int main(){
    int arr[]={5,10,10,100,5,6};
    cout<<DpMax(arr,sizeof(arr)/sizeof(arr[0]));
    return 0;

}