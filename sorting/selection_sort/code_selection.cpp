#include<iostream>
using namespace std;
void selection_s(int* arr,int n){
  for(int i=0;i<n-1;i++){
    int min=i;
    int a =i;
    while(a<n){
      if(arr[min]>arr[a]){
        min=a;
      }
      a++;
    }
    //swap
    int temp = arr[min];
    arr[min]=arr[i];
    arr[i]=temp;
  }
  return;
}

int main(){
  int arr[]={4,5,2,8,2,9};
  int size = sizeof(arr)/sizeof(arr[0]);
  selection_s(arr,size);
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}