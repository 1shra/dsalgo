#include<iostream>
#include<vector>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node* prev;

  public:
  Node(int data1,Node* next1,Node* prev1){
    data=data1;
    next=next1;
    prev=prev1;
  }
  public:
  Node(int data1){
    data=data1;
    next=nullptr;
    prev = nullptr;
  }
};

//Convert array to doubly linkedlist
Node* convertArr2DLL(vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* back = head;
  for(int i=1;i<arr.size();i++){
    Node* temp = new Node(arr[i],nullptr,back);
    back->next=temp;
    back=temp;
  }
  return head;
}

//Delete the head
Node* deletehead(Node* head){
  if(head == nullptr||head->next == nullptr){
    return nullptr;
  };
  Node* back = head;
  head = head->next;
  back->next = nullptr;
  delete back;
  return head;
}

//Delete the tail
Node* deletetail(Node* head){
  if(head==nullptr||head->next==nullptr){
    return nullptr;
  }
  Node* temp = head;
  Node* back = nullptr;
  while(temp->next!=nullptr){
    temp=temp->next;
  }
  back=temp->prev;
  temp->prev=nullptr;
  back->next=nullptr;
  delete temp;
  return head;
}

//Used to print the number
void print(Node* head){
  Node* temp = head;
  while(temp!=nullptr){
    cout<<temp->data<<endl;
    temp=temp->next;
  }
  return;
}




int main(){
  vector<int>arr = {5,2,3,4,5,8};
  Node* head = convertArr2DLL(arr);
  head = deletehead(head);
  head = deletetail(head);
  print(head);
  return 0;
}
