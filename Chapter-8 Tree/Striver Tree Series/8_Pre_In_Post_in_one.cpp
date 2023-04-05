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

void allTraversal(Node * root, vector < int > & pre, vector < int > & in , vector < int > & post) {
  stack < pair < Node * , int >> st;
  st.push({ root, 1 });
  if (root == NULL) 
    return;

  while (!st.empty())
  {
    auto it = st.top();
    st.pop();

    // this is part of pre
    // increment 1 to 2 
    // push the left side of the tree

    if (it.second == 1) 
    {
      pre.push_back(it.first -> data);
      it.second++;
      st.push(it);

      if (it.first -> left != NULL) 
      {
        st.push({it.first -> left,1});
      }
    }

    // this is a part of in 
    // increment 2 to 3 
    // push right 

    else if (it.second == 2) 
    {
      in .push_back(it.first -> data);
      it.second++;
      st.push(it);

      if (it.first -> right != NULL) 
      {
        st.push({it.first -> right,1 });
      }
    }

    // don't push it back again 
    else 
      post.push_back(it.first -> data);
    
  }
}


int main()
{

  struct Node * root = new Node(1);
  root -> left = new Node(2);
  root -> left -> left = new Node(4);
  root -> left -> right = new Node(5);
  root -> right = new Node(3);
  root -> right -> left = new Node(6);
  root -> right -> right = new Node(7);

  vector < int > pre, in , post;
  allTraversal(root, pre, in , post);

  cout << "preorder Traversal is : ";
  for (auto NodeVal: pre) 
    cout << NodeVal << " ";
  
  cout << endl;

  cout << "inorder Traversal is : ";
  for (auto NodeVal: in ) 
    cout << NodeVal << " ";
  
  cout << endl;

  cout << "postorder Traversal is : ";
  for (auto NodeVal: post) 
    cout << NodeVal << " ";
  
  cout << endl;

  return 0;
}