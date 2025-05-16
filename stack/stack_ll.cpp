#include<iostream>
using namespace std;

class myStack{
  struct node{
    int num;
    node* next;
    node* prev;
    node(int num){
      this->num=num;
    }
  };
  node* head = nullptr;
  node* mid = nullptr;
  int size =0;

public:
  void push(int data){
      node* temp = new node(data);
      if(size==0){
        head=temp;
        mid=temp;
        size++;
        return;
      }
      head->next=temp;
      temp->prev=head;

      head=head->next;
      if(size%2==1){
        mid=mid->next;
      }
      size++;
  }
  int pop(){
    int data=-1;
    if(size!=0){
      node* topop=head;
      data = topop->num;
      if(size==1){
        head = nullptr;
        mid=nullptr;
      }
      else{
        head = head->prev;
        head->next=nullptr;
        if(size%2==0){
          mid=mid->prev;
        }
      }
      delete topop;
      size--;
    }
    return data;
  }
  int findmiddle(){
    if(size==0){
      return -1;
    }
    return mid->num;
  }
  void deletemiddle(){
    if(size!=0){
      node* todelete = mid;
      if(size==1){
        head=nullptr;
        mid=nullptr;
      }
      else if(size==2){
        head=head->prev;
        mid=mid->prev;
        head->next=nullptr;
      }
      else{
        mid->next->prev=mid->prev;
        mid->prev->next=mid->next;
        if(size%2==0){
          mid=mid->prev;
        }
        else{
          mid=mid->next;
        }
      }
      delete todelete;
      size--;
    }
  }
};

int main(){
  myStack s;
  s.push(11);
  s.push(12);
  s.push(13);
  s.push(14);
  s.push(15);
  s.push(16);
  s.push(17);
  s.push(18);
  s.push(19);
  s.push(20);

  cout<<"Popped : "<<s.pop()<<endl;
  cout<<"Popped : "<<s.pop()<<endl;
  cout<<"Middle Element : "<<s.findmiddle()<<endl;
  s.deletemiddle();
  cout<<"Next Middle Element : "<<s.findmiddle()<<endl;
  return 0;
}

