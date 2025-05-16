#include<iostream>
using namespace std;
 
void insertion_s(int* arr,int n){
  for(int i=1;i<n;i++){
    int a=i;
    while(a>0){
      if(arr[a]<arr[a-1]){
        int temp = arr[a];
        arr[a]=arr[a-1];
        arr[a-1]=temp;
        a--;
      }
      else{
        break;
      }
    }
  }
  return;
}

int main(){
  int arr[]={4,5,30,20,2,8,2,9};
  int size = sizeof(arr)/sizeof(arr[0]);
  insertion_s(arr,size);
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}