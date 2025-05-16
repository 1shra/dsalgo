#include<iostream>
#include<vector>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(int data1,int next1){
    data = data1;
    next = nullptr;
  }
  Node(int data1){
    data = data1;
    next = nullptr;
  }
};
Node* convertArr2LL(vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i=1;i<arr.size();i++){
    Node* temp = new Node(arr[i]);
    mover->next =temp;
    mover=temp;
  }
  return head;
}
//Used to remove the Head of linked list
Node* removeHead(Node* head){
  if(head==nullptr) return head;
  Node* temp = head;
  head=head->next;
  free(temp);
  return head;
}
//to remove tail of linked list
Node* removeTail(Node* head){
  Node* temp = head;
  Node* mover = temp->next;
  while(mover->next!=nullptr){
    temp=mover;
    mover=mover->next;
  }
  temp->next=nullptr;
  free(mover);
  return head;
}
//to delete kth level of the node
Node* reomveknode(Node* head,int k){
  if(head ==nullptr) return head;
  Node* temp = head;
  Node* mover = nullptr;
  if(k==1){
    head=mover;
    free(temp);
    return head;
  }
  int counter = 0;
  while (temp!=nullptr)
  {
    counter++;
    if(counter == k){
      mover->next = mover->next->next;
      free(temp);
      break;
    }
    mover = temp;
    temp=temp->next;
  }
  return head;
}
//Delete based on the value
Node* removeValue(Node* head,int value){
  if(head==nullptr) return head;
  Node* temp = head;
  Node* prev =  nullptr;
  if(head->data==value){
    head = head->next;
    free(temp);
    return head;
  }
  while(temp!=nullptr){
    if(temp->data==value){
      prev->next=prev->next->next;
      free(temp);
      return head;
    }
    prev=temp;
    temp=temp->next;
  }
  cout<<"No value present in ll"<<endl;
  return head;
}

//Inserting
//Insert at head of linked list
Node* insertAtHead(Node* head,int value){
  Node* temp = new Node(value);
  temp->next=head;
  head=temp;
  free(temp);
  return head;
}
//Insert at last of linked list
Node* insertAtLast(Node* head, int value){
  if(head==nullptr) return new Node(value);
  Node* temp = head;
  Node* temp1 = new Node(value);
  while (temp->next!=nullptr){
    temp=temp->next;
  }
  temp->next=temp1;
  return head;
}

//Used to print the linkedlist
void print(Node* head){
  Node* temp = head;
  while(temp!=nullptr){
    cout<<temp->data<<endl;
    temp=temp->next;
  }
}




int main(){
  vector<int> arr = {2, 5, 8,20,41,81, 7,9,24};
  Node* head = convertArr2LL(arr);
  head=removeHead(head);
  head=removeTail(head);
  head= reomveknode(head,4);
  head= removeValue(head,20);
  head = insertAtHead(head,51);
  // head = insertAtLast(head,89); //error
  print(head);
  return 0;
}