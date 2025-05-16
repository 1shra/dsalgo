#include<iostream>
using namespace std;
void bubble(int* arr,int n){
 for(int j=0;j<n-1;j++){
  for(int i=0;i<n-j-1;i++){
    if(arr[i]>arr[i+1]){
      int temp =arr[i];
      arr[i]=arr[i+1];
      arr[i+1]=temp;
    }
  }
 }
  return;
}

int main(){
  int arr[]={4,5,2,8,2,9};
  int size = sizeof(arr)/sizeof(arr[0]);
  bubble(arr,size);
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}