#include <iostream>
#include <vector>
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
int  maximumValue(Node* root){
    int m = root->data;
     for(Node* child: root->vec){
        int i = maximumValue(child);
        if(i>m){
            m=i;
        }
     }
     return m;
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
int main(){
    int arr[] = {1200, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 190, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    // int arr[] = {1, 2, 3, -1, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = buildGenericTree(arr, n);
    if (root)
    {
        cout << "Size of given generict tree " << maximumValue(root)<<endl;
    }
    else
    {
        cout << "Tree is Empty" << endl;
    }
    return 0;
}