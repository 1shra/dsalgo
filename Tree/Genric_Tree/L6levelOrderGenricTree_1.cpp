// Implimentaion of  genric tree
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class Node
{
public:
    int data;
    vector<Node *> vec;

    Node(int val)
    {
        data = val;
    }
};

void levelOrder(Node* root){
    queue<Node*> que;
    cout<<root->data<<" ";
    que.push(root);
    while(!que.empty()){
        for(Node* child:que.front()->vec){
            cout<<child->data<<" ";
            que.push(child);
        }
        que.pop();
    }

}

Node *buildGenericTree(int arr[], int n)
{
    stack<Node *> st;
    Node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            Node *t = new Node(arr[i]);
            if (!st.empty())
            {
                st.top()->vec.push_back(t);
            }
            else
            {
                root = t;
            }
            st.push(t);
        }
    }
    return root;
}

int main()
{
    // int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    // int arr[] = {1, 2, 3, -1, -1};
    int arr[]={10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = buildGenericTree(arr, n);
    if (root)
    {
        cout << "level order of given generict tree "<<endl;
        levelOrder(root);
    }
    else
    {
        cout << "Tree is Empty" << endl;
    }
    return 0;
}