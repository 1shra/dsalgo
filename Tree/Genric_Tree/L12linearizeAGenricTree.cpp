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
Node *getTail(Node *sl)
{
    while (sl->vec.size() == 1)
    {
        sl = sl->vec[0];
    }
    return sl;
}
void Linearize(Node *root)
{
    for (Node *child : root->vec)
    {
        Linearize(child);
    }
    while (root->vec.size() > 1)
    {
        Node *last = root->vec[root->vec.size() - 1];
        // cout<<last->data<<endl;
        root->vec.pop_back();
        Node *sl = root->vec[root->vec.size() - 1];

        Node *slt = getTail(sl);
        slt->vec.push_back(last);
    }
}
int main()
{
    int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    // int arr[] = {1, 2, 3, -1, -1,-1};
    // int arr[] = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1};

    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = buildGenericTree(arr, n);
    if (root)
    {
        // cout<<endl;
        cout << "level order of given generict tree " << endl;
        levelOrder(root);
        cout << "Linearize a Generic Tree" << endl;
        Linearize(root);
        levelOrder(root);
    }
    else
    {
        cout << "Tree is Empty" << endl;
    }
    return 0;
}