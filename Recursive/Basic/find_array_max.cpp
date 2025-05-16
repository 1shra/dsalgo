#include<iostream>
using namespace std;

int max_Array(int arr[], int idx,int size){
    if(idx == size){
        return arr[idx];
    }    
    int misa = max_Array(arr,idx+1,size);
    if(misa>arr[idx]){
        return misa;
    }
    else{
        return arr[idx];
    }
}

int main(){
    int arr[]={10,20,70,40,50,60};
    int max=0;
    int size = sizeof(arr)/sizeof(arr[0]);
    int idx =0;
    cout<<max_Array(arr,idx,size-1);
}