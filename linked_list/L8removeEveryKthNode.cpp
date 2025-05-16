#include<iostream>
#include<vector>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  public:
  Node(int data1,Node* next1){
    data=data1;
    next=next1;
  }
  public:
  Node(int data1){
    data=data1;
    next=nullptr;
  }
};
Node* convertArrtoLl(vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i=1; i<arr.size();i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover=temp;
  }
  return head;
}

Node* removeEveryKthNode(Node* head,int k){
  int count =k;
  if(k=1){
    return nullptr;
  }
  Node* temp = head;
  Node* prev = nullptr;
  while(temp!=nullptr){
    count--;
    if(count==0){
      prev->next=temp->next;
      free(temp);
      temp=prev->next;
      count = k;
      continue;
    }
    prev=temp;
    temp=temp->next;
  }
  return head;
}

void print(Node* head){
  Node* temp = head;
  while(temp!=nullptr){
    cout<<temp->data<<endl;
    temp = temp->next;
  }
}

int main(){
  vector<int> arr = {1,2,3,4,5,6,7,8,9};
  Node* head = convertArrtoLl(arr);
  print(head);
  cout<<"Print: "<<endl;
  Node* newHead = removeEveryKthNode(head,3);
  print(newHead);
}