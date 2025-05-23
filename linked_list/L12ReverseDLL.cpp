#include<iostream>
#include<vector>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node* prev;

  public:
  Node(int data1,Node* next1, Node* prev1){
    data=data1;
    next=next1;
    prev=prev1;
  }
  public:
  Node(int data1){
    data=data1;
    next=nullptr;
    prev=nullptr;
  }
};
Node* convertArr2DLL(vector<int> &arr){
  Node* head=new Node(arr[0]);
  Node* mover = head;
  for(int i=1;i<arr.size();i++){
    Node* temp = new Node(arr[i],nullptr,mover);
    mover->next=temp;
    mover=temp;
  }
  return head;
}
void print(Node* head){
  Node* temp = head;
  while(temp!=nullptr){
    cout<<temp->data<<endl;
    temp=temp->next;
  }
}
Node* reversell(Node* head){
  Node* cur  = head;
  Node* prev = nullptr;
  Node* future = nullptr;
  while(cur){
    future = cur->next;
    cur->next = prev;
    prev = cur;
    cur = future;
  }
  head = prev; 
  return head;
}
int main(){
  vector<int> arr ={4,5,6,8,7,89};
  Node* head = convertArr2DLL(arr);
  print(head);
  head = reversell(head);
  print(head);
  
}