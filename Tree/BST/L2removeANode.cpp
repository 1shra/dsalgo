#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
Node *BST(int a, Node *root)
{
    if (root == nullptr)
    {
        Node *p = new Node(a);
        return p;
    }
    if (root->data > a)
    {
        Node *p = BST(a, root->left);
        root->left = p;
    }
    else if (root->data <= a)
    {
        Node *p = BST(a, root->right);
        root->right = p;
    }
    return root;
}
Node *buildBST(int arr[], int n)
{
    Node *root = new Node(arr[0]);
    for (int i = 1; i < n; i++)
    {
        BST(arr[i], root);
    }
    return root;
}

void levelTraversal(Node *root)
{
    queue<pair<Node *, char>> que;
    que.push({root, 'o'});
    while (!que.empty())
    {
        int n = que.size();
        while (n)
        {
            Node *p = que.front().first;
            cout << p->data << que.front().second << " ";
            que.pop();
            if (p->left)
                que.push({p->left, 'l'});
            if (p->right)
                que.push({p->right, 'r'});
            n--;
        }
        cout << endl;
    }
}

Node *leftmax(Node *root)
{
    if (root->right == nullptr)
    {
        return root;
    }
    return leftmax(root->right);
}

Node *removeaNode(Node *root, int val)
{
    if(root==nullptr){
        return nullptr;
    }
    if (root->data == val)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return nullptr;
        }
        else if (root->left && root->right)
        {
            Node *q = leftmax(root->left);
            if (q == root->left)
            {
                q->right = root->right;
                return q;
            }
            else
            {
                root->left = removeaNode(root->left, q->data);
                Node *w = new Node(q->data);
                w->left = root->left;
                w->right = root->right;
                return w;
            }
        }
        else
        {
            if (root->left)
            {
                return root->left;
            }
            else
            {
                return root->right;
            }
        }
    }
    if (root->data > val)
    {
        Node *p = removeaNode(root->left, val);
        root->left = p;
    }
    else
    {
        Node *p = removeaNode(root->right, val);
        root->right = p;
    }
    return root;
}

int main()
{
    int arr[] = {60, 40, 10, 30, 50, 70, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = buildBST(arr, n);
    cout << "Level Order Traversal" << endl;
    levelTraversal(root);
    cout << "Level Order Traversal of Removed Tree" << endl;
    root = removeaNode(root, 40);
    levelTraversal(root);
    return 0;
}