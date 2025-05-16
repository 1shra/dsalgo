// given value k to rotate right hand side

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

Node* rotateLlByK(Node* head,int k){
  Node* temp = head;
  Node* prev = nullptr;
  Node* newHead = nullptr;
  int count = 0;
  while(temp->next!=nullptr){
    count++;
    if(count==k){
      prev = temp;
      temp=temp->next;
      prev->next = nullptr;
      newHead = temp;
      continue;
    }
    temp=temp->next;
  }
  temp->next=head;
  return newHead;
}


int main(){
  vector<int> arr = {1,2,3,4,5,6,8,9,7};
  Node* head = covertArrtoLl(arr);
  print(head);
  cout<<"Print the number after rotating by k = "<<endl;
  Node* newHead= rotateLlByK(head,2);
  print(newHead);
  return 0;
}