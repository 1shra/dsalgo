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
  Node(int data1){
    data=data1;
    next=nullptr;
  }
};
Node* convertArrtoLL(vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i = 1; i<arr.size();i++){
    Node* temp = new Node(arr[i]);
    mover->next=temp;
    mover=temp;
  }
  return head;
}
Node* removeDuplicate(Node* head){
  Node* temp=head;
  Node* prev=nullptr;
  unordered_map<int,bool> ap;
  while(temp!=nullptr){
    if(ap[temp->data]){
      prev->next = temp->next;
      free(temp);
      temp=prev->next;
    }
    else{
      ap[temp->data]=1;
      prev=temp;
      temp=temp->next;
    }
  }
  prev->next =nullptr;
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
  vector<int> arr = {1,4,5,6,78,6,6,6,6,6,66,6,66,6,6,66,666,6666};
  Node* head = convertArrtoLL(arr);
  print(head);
  cout<<"Remove the duplicate"<<endl;
  Node* newHead = removeDuplicate(head);
  print(newHead);
}