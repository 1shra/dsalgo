#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int data;
    vector<Node *> vec;

    Node(int val)
    {
        data = val;
    }
};
Node *buildTree(int arr[], int n)
{
    stack<Node *> st;
    Node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            if (st.empty())
            {
                return root;
            }
            st.pop();
        }
        else
        {
            Node *t = new Node(arr[i]);
            if (st.empty())
            {
                root = t;
            }
            else
            {
                st.top()->vec.push_back(t);
            }
            st.push(t);
        }
    }
    return root;
}

void traversalWithLevel(Node *root)
{
    queue<Node *> mainQ;
    queue<Node *> childQ;

    mainQ.push(root);

    while (!mainQ.empty())
    {
        cout << mainQ.front()->data << " ";
        for (Node *itr : mainQ.front()->vec)
        {
            childQ.push(itr);
        }
        mainQ.pop();
        if (mainQ.empty())
        {
            cout << endl;
            mainQ = childQ;
            while (!childQ.empty())
            {
                childQ.pop();
            }
        }
    }
}

bool checksys(Node *root, Node *boot)
{
    if (root->vec.size() != boot->vec.size())
    {
        return false;
    }
    for (int i = 0; i < root->vec.size(); i++)
    {
        Node *c1 = root->vec[i];
        Node *c2 = boot->vec[root->vec.size() - 1 - i];
        if (checksys(c1, c2) == false)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    // int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    // int brr[] = {1, 2, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    int arr[] = {1, 2, 5,-1,-1, 3, 4,-1,-1, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    // int k = sizeof(brr) / sizeof(brr[0]);
    Node *root = buildTree(arr, n);
    // Node *boot = buildTree(brr, n);
    // traversalWithLevel(root);
    cout << "Node To root Path" << endl;
    cout << checksys(root, root) << endl;
}