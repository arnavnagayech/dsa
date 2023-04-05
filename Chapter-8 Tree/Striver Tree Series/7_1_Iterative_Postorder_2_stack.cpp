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

vector < int > postOrderTrav2Stack(Node * curr)
{

  vector < int > postOrder;
  if (curr == NULL) 
    return postOrder;

  stack < Node * > s1;
  stack < Node * > s2;

  s1.push(curr);
  while (!s1.empty()) 
  {
    curr = s1.top();
    s1.pop();
    s2.push(curr);
    if (curr -> left != NULL)
      s1.push(curr -> left);

    if (curr -> right != NULL)
      s1.push(curr -> right);
  }
  while (!s2.empty()) 
  {
    postOrder.push_back(s2.top() -> data);
    s2.pop();
  }
  return postOrder;
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

  vector < int > postOrder = postOrderTrav2Stack(root);

  cout << "PostOrder Traversal : ";
  for (int i = 0; i < postOrder.size(); i++)
    cout << postOrder[i] << " ";
  
  return 0;
}