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
    next= next1;
  }
  Node(int data1){
    data=data1;
    next=nullptr;
  }
};
Node* convertArrToLl(vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i=1;i<arr.size();i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover=temp;
  }
  return head;
}

Node* removeKthEnd(Node* head,int k){
  int count = 0;
  Node* temp= head;
  while(temp!=nullptr){
    count++;
    temp=temp->next;
  }
  count-=k;
  if(count==0){
    temp =head;
    head=head->next;
    free(temp);
    return head;
  }
  temp = head;
  Node* prev = nullptr;
  while(count--){
    prev=temp;
    temp=temp->next;
  }
  prev->next=temp->next;
  free(temp);
  return head;
}


void print(Node* head){
  Node* temp = head;
  while(temp!=nullptr){
    cout<<temp->data<<endl;
    temp=temp->next;
  }
  return;
}
int main(){
  vector<int>arr = { 1,2,3,4,5,6};
  Node* head = convertArrToLl(arr);
  print(head);

  Node* newHead = removeKthEnd(head,6);
  cout<<"print"<<endl;
  print(newHead);
}