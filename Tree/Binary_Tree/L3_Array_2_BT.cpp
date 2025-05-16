#include <iostream>
#include <vector>
using namespace std;
//* define tree stucture

class node
{
  public:
  int data;
  node* left;
  node* right;
  public:
  node(int val)
  {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

//* Converting Array to Binary Tree

void Array2BT(vector<int> &vec, node *root, int i, int n)
{
  if (2 * i + 1 < n)
  {
    node *l = new node(vec[2 * i + 1]);
    root->left = l;
    Array2BT(vec, root->left, 2 * i + 1, n);
  }
  if (2 * i + 2 < n)
  {
    node *r = new node(vec[2 * i + 2]);
    root->right = r;
    Array2BT(vec, root->right, 2 * i + 2, n);
  }
}

//* Tree Traversal
void inorder_Traversal(node *root)
{
  if (root == nullptr)
  {
    return;
  }
  inorder_Traversal(root->left);
  cout << root->data << " ";
  inorder_Traversal(root->right);
  return;
}
int main()
{
  vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
  node *root = new node(vec[0]);
  Array2BT(vec, root, 0, vec.size());
  inorder_Traversal(root);
}