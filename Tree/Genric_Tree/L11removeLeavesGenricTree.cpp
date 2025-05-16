#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
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
void levelOrder(Node *root)
{
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        int cuq = que.size();

        for (int i = 0; i < cuq; i++)
        {
            root = que.front();
            que.pop();
            cout << root->data << " ";
            for (Node *child : root->vec)
            {
                que.push(child);
            }
        }
        cout << endl;
    }
    return;
}
void removeLeaves(Node *root)
{
    int n = root->vec.size();
    for (int i =  n- 1; i >= 0; i--)
    {
        Node *child = root->vec[i];
        if (child->vec.size() == 0)
        {
            root->vec.erase(root->vec.begin() + i);
        }
    }
    for (Node *child : root->vec)
    {
        removeLeaves(child);
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
    // int arr[] = {1200, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 190, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    // int arr[] = {1, 2, 3, -1, -1,-1};
    int arr[] = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1};

    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = buildGenericTree(arr, n);
    if (root)
    {
        levelOrder(root);
        // cout<<endl;
        cout << "Size of given generict tree " << endl;
        removeLeaves(root);
        levelOrder(root);
    }
    else
    {
        cout << "Tree is Empty" << endl;
    }
    return 0;
}