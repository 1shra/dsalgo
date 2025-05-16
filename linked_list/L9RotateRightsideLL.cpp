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
  Node(int data1){
    data=data1;
    next=nullptr;
  }
};

Node* convertArrToLl(vector<int> & arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i=1;i<arr.size();i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover=temp;
  }
  return head;
}


Node* rotateRightSide(Node* head,int k){
  Node* temp=head;
  int count=1;
  while(temp->next!=nullptr){
    count++;
    temp=temp->next;
  }
  k%=count;
  count-=k;
  temp->next=head;
  while (count--)
  {
      temp=temp->next;
  }
  head=temp->next;
  temp->next=nullptr;
  return head;  
}

void print(Node* head){
  Node* temp =head;
  while(temp!=nullptr){
    cout<<temp->data<<endl;
    temp=temp->next;
  }
}

int main(){
  vector<int> arr = {1,2,3,4,5,6,7,8,9};
  Node* head  = convertArrToLl(arr);
  print(head);
  //Rotate right hand side
  cout<<"Rotate right side"<<endl;
  Node* newHead = rotateRightSide(head,10);
  print(newHead);
  return 0;
}