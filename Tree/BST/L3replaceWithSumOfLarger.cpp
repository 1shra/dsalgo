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
static int k = 0;
Node *leftmax(Node *root)
{
    if (root->right == nullptr)
    {
        return root;
    }
    return leftmax(root->right);
}

int sum_Of_larger_bst(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    sum_Of_larger_bst(root->right);
    int a = root->data;
    root->data = k;
    k += a;
    sum_Of_larger_bst(root->left);
}

int main()
{
    int arr[] = {60, 40, 10, 30, 50, 70, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = buildBST(arr, n);
    cout << "Level Order Traversal" << endl;
    levelTraversal(root);
    cout << "sum of the larger" << endl;
    sum_Of_larger_bst(root);
    levelTraversal(root);
    return 0;
}