#include<iostream>
#include<vector>
using namespace std;
int min_Array(int arr[],int id,int s){
    if(id==s){
        return arr[id];
    }
    int min_elem = min_Array(arr, id+1,s);
    if(min_elem<arr[id]){
        return min_elem;
    }
    else{
        return arr[id];
    }


}
int main(){
    int arr[]={90,20,70,40,50,60};
    int size = sizeof(arr)/sizeof(arr[0]);
    int idx =0;
    cout<<min_Array(arr,idx,size-1);
    
}