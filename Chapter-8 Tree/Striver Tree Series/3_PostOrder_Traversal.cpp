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

void dfs(Node* root, vector<int> &postorder)
{
    if (root == NULL)
        return;

    dfs(root->left,postorder);
    dfs(root->right,postorder);
    postorder.push_back(root->data);

}
vector<int> postorderTraversal(Node* root)
{
    vector<int> postorder;
    dfs(root,postorder);

    return postorder;
}

int main()
{
    struct Node *root= new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> arr = postorderTraversal(root);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}