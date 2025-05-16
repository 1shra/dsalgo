#include<iostream>
#include<vector>
using namespace std;
class Node{
  public:
  int data;
  Node* next;

  public:
  Node(int data1, Node* next1){
    data = data1;
    next = next1;
  }

  public:
  Node(int data1){
    data= data1;
    next = nullptr;
  }
};
Node* convertArr2LL(vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i=1;i<arr.size();i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover =temp;
  }
  return head;
}
bool checkIfPresent(Node* head,int value){
  Node* temp = head;
  while(temp!=nullptr){
    if(temp->data==value){
      return 1;
    }
    temp=temp->next;
  }
  return 0;
}
int main(){
  vector<int> arr = {2, 5, 8, 7};
  Node* head = convertArr2LL(arr);
  // cout<<head->data<<endl;
  Node* temp = head;
  while(temp!=nullptr){
    cout<<temp->data<<endl;
    temp=temp->next;
  }
  bool search=checkIfPresent(head,9);
  cout<<search;
  return 0;
}