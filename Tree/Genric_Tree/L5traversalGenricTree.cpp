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
void Traversal(Node *root)
{
    cout << "Node Pre " << root->data << endl;
    for (Node *child : root->vec)
    {
        cout << "Edge Pre " << root->data << "--" << child->data << endl;
        Traversal(child);
        cout << "Edge Post " << root->data << "--" << child->data << endl;
    }
    cout << "Node Post " << root->data << endl;
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
    // int arr[] = {1,2, -1};
    int arr[] = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = buildGenericTree(arr, n);
    if (root)
    {
        cout << "Travesal of given generict tree " << endl;
        Traversal(root);
    }
    else
    {
        cout << "Tree is Empty" << endl;
    }
    return 0;
}