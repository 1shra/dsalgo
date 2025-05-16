#include<iostream>
using namespace std;
void printArray(int arr[],int size){
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  return;
}
void merge(int arr[],int left,int mid ,int right){
  int n1 =mid-left+1;
  int n2 = right-mid;


  int leftAarr[n1],rightArr[n2];

  for(int i =0;i<n1;i++){
    leftAarr[i]=arr  
  }
}
void mergeSort(int arr[],int left,int right){
  if(left<right){
    int mid=left+(right-left)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);

    merge(arr,left,mid,right);
  }
}

int main(){
  int arr[]={9,5,2,8,1,4,7,3,6};
  int arrSize = sizeof(arr)/sizeof(arr[0]);
  cout<<"Original array";
  cout<<endl;
  printArray(arr,arrSize);
  cout<<endl;
  cout<<"Sorted array";
  mergeSort(arr, 0 , arrSize-1);
  return 0;
}