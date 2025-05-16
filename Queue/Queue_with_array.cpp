#include<iostream>
using namespace std;
class Queue{
  int *arr;
  int front;
  int back;
  int max_size;
  public:
    Queue(int default_size=10){
      arr= new int[default_size];
      max_size=default_size;
      front=-1;
      back=-1;
    }
    bool empty(){
      // if(size==0){
      //   return 1;
      // }
      // return 0;
      return front==back;
    }
    bool full(){
      // if(size==max_size){
      //   return 1;
      // }
      // return 0;
      return back==max_size;
    }
    void enqueue(int d){
      if(full()){
        cout<<"Queue Overflow"<<endl;
        return;
      }else{
        if(front==-1){
          front =0;
          back=0;
        }
        arr[back]=d;
        back++;
      }
    }
    void dequeue(){
      if(empty()){
        cout<<"Underflow";
      }
      else{
        arr[front]=-1;
        front++;
        if(front==back){
          front=-1;
          back=-1;
        }
      }
    }
    int getfront(){
      if(empty()){
        cout<<"Queue Underflow"<<endl;
        return -1;
      }
      return arr[front];
    }
    int getback(){
      if(full()){
        cout<<"Queue Overflow"<<endl;
        return -1;
      }
      return arr[back];
    }


    void print(){
      if(empty()){
        cout<<"Queue is empty"<<endl;
        return;
      }
      int i=0;
      while(i<max_size){
        cout<<arr[i]<<" ";
      }
      cout<<endl;
    }
};


int main(){

}