#include<iostream>
#include<vector>
using namespace std;
int find_oc_Array(int arr[],int idx,int s,int oc){
    if(oc == arr[idx]){
        return idx;
    }
    if(idx==s){
        return -1;
    }

    find_oc_Array(arr,idx+1,s,oc);
    
}

int main(){
    int arr[]={90,20,80,40,70,50,70};
    int size = sizeof(arr)/sizeof(arr[0]);
    int idx =0;
    int oc=60;
    cout<<find_oc_Array(arr,idx,size-1,oc);
    
}