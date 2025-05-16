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
vector<int> nodeToRoot(Node *root, int data)
{
    if (root->data == data)
    {
        return {data};
    }
    for (Node *child : root->vec)
    {
        vector<int> pc = nodeToRoot(child, data);
        if (!pc.empty())
        {
            pc.push_back(root->data);
            return pc;
        }
    }
    return {};
}
int DBN(Node *root, int a, int b)
{
    vector<int> p = nodeToRoot(root, a);
    vector<int> q = nodeToRoot(root, b);
    int i = p.size() - 1;
    int j = q.size() - 1;
    while (i != -1 && j != -1)
    {
        // cout << p[i] << " " << q[j] << endl;
        if (p[i] != q[j])
        {
            break;
        }
        i--;
        j--;
    }

    return (i + 1) + (j + 1);
}
int main()
{
    int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    // int arr[] = {1, 2, -1, 3, -1, 4, -1, 5, -1, 6, 7, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = buildTree(arr, n);
    traversalWithLevel(root);
    cout << "Node To root Path" << endl;
    cout << DBN(root, 50, 100) << endl;
}