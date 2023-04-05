#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};

vector < int > preOrderTrav(Node * curr)
{
  vector < int > preOrder;
  if (curr == NULL)
    return preOrder;

  stack < Node * > s;
  s.push(curr);

  while (!s.empty())
   {
    Node * topNode = s.top();
    preOrder.push_back(topNode -> data);
    s.pop();

    if (topNode -> right != NULL)
      s.push(topNode -> right);

    if (topNode -> left != NULL)
      s.push(topNode -> left);
  }
  return preOrder;
}

int main()
{
  struct Node *root = new  Node(1);

  root -> left = new  Node(2);
  root -> right = new  Node(3);
  root -> left -> left = new  Node(4);
  root -> left -> right = new  Node(5);
  root -> left -> right -> left = new  Node(8);
  root -> right -> left = new  Node(6);
  root -> right -> right = new  Node(7);
  root -> right -> right -> left =  new Node(9);
  root -> right -> right -> right = new  Node(10);

  vector < int > preOrder = preOrderTrav(root);

  cout << "PreOrder Traversal : ";
  for (int i = 0; i < preOrder.size(); i++)
    cout << preOrder[i] << " ";
  
  return 0;
}