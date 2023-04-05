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

vector < int > inOrderTrav(Node * curr) 
{
  vector < int > inOrder;
  stack < Node * > s;

  while (true) 
  {
    if (curr != NULL) 
    {
      s.push(curr);
      curr = curr -> left;
    } 
    else
    {
      if (s.empty()) 
        break;
      curr = s.top();
      inOrder.push_back(curr -> data);
      s.pop();
      curr = curr -> right;
    }
  }
  return inOrder;
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

  vector < int > inOrder = inOrderTrav(root);

  cout << "InOrder Traversal : ";
  for (int i = 0; i < inOrder.size(); i++)
    cout << inOrder[i] << " ";
  
  return 0;
}