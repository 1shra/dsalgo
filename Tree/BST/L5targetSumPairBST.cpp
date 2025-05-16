#include <iostream>
#include <queue>
#include <vector>
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
void targetSumPairBst(Node *root, int target, int sum, vector<int> &vec)
{
    if (root)
    {
        return;
    }
    if (sum > target)
    {
        return;
    }
    if (sum == target)
    {
        for (int i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    targetSumPairBst(root->left, target, sum, vec);
    targetSumPairBst(root->right, target, sum, vec);

    vec.push_back(root->data);
    targetSumPairBst(root->left, target, sum + root->data, vec);
    targetSumPairBst(root->right, target, sum + root->data, vec);
    vec.pop_back();
    return;
}

int main()
{
    int arr[] = {60, 40, 10, 30, 50, 70, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = buildBST(arr, n);
    cout << "Level Order Traversal" << endl;
    levelTraversal(root);
    cout << "sum of the larger" << endl;
    vector<int> res;
    targetSumPairBst(root, 80, 0, res);
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     for (int j = 0; j < vec[0].size(); i++)
    //     {
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}