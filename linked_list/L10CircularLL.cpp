#include<iostream>
#include<vector>
#include<unordered_map>

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
Node* convertArrToCll(vector<int> & arr){
  Node* head  = new Node(arr[0]);
  Node* mover = head;
  for(int i = 1;i<arr.size();i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover=temp;
  }
  mover->next=head;
  return head;
}

Node* removeloop(Node* head){
  Node* curr = head;
  unordered_map<Node*,bool> visit;
  Node* prev = nullptr;
  
  while(curr!=nullptr){
    if(visit[curr]){
      break;
    }
    else{
      visit[curr]=1;
      prev = curr;
      curr=curr->next;
    }
  }
  prev->next = nullptr;
  return head;
}



void print(Node* head){
  Node* temp = head;
  while(temp!=nullptr){
    cout<<temp->data<<endl;
    temp=temp->next;
  }
}
int main(){
  vector<int> arr ={1,2,3,4,5,6,7,8,9};
  Node* head = convertArrToCll(arr);
  // print(head);
  Node* newHead = removeloop(head);
  print(newHead);
}