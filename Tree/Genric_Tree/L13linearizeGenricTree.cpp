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
Node *linearize2(Node *root)
{
    if (root->vec.size() == 0)
    {
        return root;
    }
    Node *lkt = linearize2(root->vec[root->vec.size() - 1]);
    while (root->vec.size() > 1)
    {
        Node *last = root->vec[root->vec.size() - 1];
        root->vec.pop_back();
        Node *slkt = linearize2(root->vec[root->vec.size() - 1]);
        slkt->vec.push_back(last);
    }

    return lkt;
}
int main()
{
    int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    // int arr[] = {1, 2, -1, 3, -1, 4, -1, 5, -1, 6, 7, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = buildTree(arr, n);
    traversalWithLevel(root);
    cout << "Linearize" << endl;
    linearize2(root);

    traversalWithLevel(root);
}