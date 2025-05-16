#include <iostream>
#include <stack>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
int findIndex(string str,int i,int j){
    if (i>j){
        return -1;
    }
    int cnt=0;
    for(int k=i;k<=j;k++){
        if(str[k]=='(') cnt++;
        else if (str[k]==')'){
            cnt--;
            if(cnt==0) return k;
        }
    }
    return -1;
}
Node* constructTreeRecur(string str,int i,int j){
    if(i>j){
        return nullptr;
    }
    int val=0;
    while(i<=j&&str[i]>='0'&&str[i]<='9'){
        val*=10;
        val+=(str[i]-'0');
        i++;
    }
    cout<<val<<endl;
    Node* root = new Node(val);
    int index = -1;
    if(i<=j&&str[i]=='('){
        index = findIndex(str,i,j);

    }
    if(index!=-1){
        root->left=constructTreeRecur(str,i+1,index-1);
        root->right=constructTreeRecur(str,i+2,j-1);
    }
    return root;
}
Node* treeFromString(string s)
{
    Node* root = constructTreeRecur(s,0,s.length()-1);
    return root;
}


void inorder_Traversal(Node *root){
    if (root == nullptr)
    {
        return;
    }
    inorder_Traversal(root->left);
    cout << root->data << " ";
    inorder_Traversal(root->right);
}

int main()
{
    string s = "4(2(3)(1))(6(5))";
    Node *p = treeFromString(s);
    inorder_Traversal(p);
    return 0;
}