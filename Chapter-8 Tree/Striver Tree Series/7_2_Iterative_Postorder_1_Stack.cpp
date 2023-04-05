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

vector < int > postOrderTrav1Stack(Node * cur)
 {

  vector < int > postOrder;
  if (cur == NULL) 
    return postOrder;

  stack < Node * > st;
  while (cur != NULL || !st.empty())
  {

    if (cur != NULL) 
    {
      st.push(cur);
      cur = cur -> left;
    } 
    else 
    {
      Node * temp = st.top() -> right;
      if (temp == NULL) 
      {
        temp = st.top();
        st.pop();
        postOrder.push_back(temp -> data);

        while (!st.empty() && temp == st.top() -> right)
        {
          temp = st.top();
          st.pop();
          postOrder.push_back(temp -> data);
        }
      } 
      else 
        cur = temp;
    }
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

  vector < int > postOrder = postOrderTrav1Stack(root);

  cout << "PostOrder Traversal : ";
  for (int i = 0; i < postOrder.size(); i++)
    cout << postOrder[i] << " ";
  
  return 0;
}