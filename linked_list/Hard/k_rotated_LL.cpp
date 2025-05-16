 #include<iostream>
 using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr||head->next == nullptr){
            return head;
        }
        int count=0;
        ListNode* tig = head;
        ListNode* prev = nullptr;
        int cnt=0;
        while(tig!=nullptr){
            prev=tig;
            tig=tig->next;
            cnt++;
        }
        tig=head;
        prev->next=head;
        k=cnt-k;
        while(k--){
            prev=tig;
            tig=tig->next;
        }
        prev->next=nullptr;
        return tig;
}
int main(){
  
}