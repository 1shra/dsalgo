#include<iostream>
#include<vector>
using namespace std;
class Node
{
  public:
    int data;
    Node* next;
public:
  Node(int data1, Node* next1){
    data = data1;
    next = next1;
  }
  Node(int data1){
    data = data1;
    next = nullptr;
  }
};


Node* covertArrtoLl(vector<int> & arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i=1;i<arr.size();i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}

void print(Node* head){
  Node* temp = head;
  while(temp!= nullptr){
    cout<<temp->data<<endl;
    temp=temp->next;
  }
  return;
}

Node* middleofLL(Node* head){
  Node* t1 = head;
  Node* t2 = head;
  while(t2!=nullptr&&t2->next!=nullptr){
    t2=t2->next->next;
    t1=t1->next;
  }
  return t1;
}

int main(){
  vector<int> arr = {1,2,3,4,5,6,8,9,7};
  Node* head = covertArrtoLl(arr);
  print(head);
  Node* middle = middleofLL(head);
  cout<<"Middle Postion of linked list = "<<middle->data<<endl;
  return 0;
}