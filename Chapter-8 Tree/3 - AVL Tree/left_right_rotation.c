#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int key;
    int height;
    struct tree *left;
    struct tree *right;
};
struct tree *root=NULL;
struct tree* newNode(int key) 
{ 
    struct tree* node = (struct tree*) malloc(sizeof(struct tree)); 
    node->key = key; 
    node->left = node->right = NULL; 
    node->height = 1;  // new node is initially added at leaf 
    return(node); 
}

int height(struct tree *t)
{
    if (t==NULL)
        return 0;
    
    return t->height;
}

int balanceFactor(struct tree *t)
{
    if (t==NULL)
        return 0;
    
    return height(t->left) - height(t->right);
}

int max(int x, int y) 
{
    if (x>y)
       return x;
    
    return y; 
}

struct tree *rightRotate(struct tree *t) 
{ 
    struct tree *p1 = t->left; 
    struct tree *p2 = p1->right; 
  
    // Perform rotation 
    p1->right = t; 
    t->left = p2; 
  
    // Update heights 
    t->height = max(height(t->left), height(t->right))+1; 
    p1->height = max(height(p1->left), height(p1->right))+1; 
  
    // Return new root 
    return p1; 
}

struct tree *leftRotate(struct tree *t) 
{ 
    struct tree *p1 = t->right; 
    struct tree *p2 = p1->left; 
  
    // Perform rotation 
    p1->left = t; 
    t->right = p2; 
  
    // Update heights 
    t->height = max(height(t->left), height(t->right))+1; 
    p1->height = max(height(p1->left), height(p1->right))+1; 
  
    // Return new root 
    return p1; 
}

struct tree* recursiveInsert(struct tree *t, int key)
{
    if (t == NULL)
    {
        return newNode(key);
    }
    if (key < t->key)
    {
        t->left = recursiveInsert(t->left, key);
    }
    else if (key > t->key)
    {
        t->right = recursiveInsert(t->right, key);
    }
    else
       return t;
    t->height = max(height(t->left), height(t->right)) + 1;
    
    // If so, perform LL Rotation
    if (balanceFactor(t) < -1 && t->right->key < key)
        return leftRotate(t);
    // If so, perform RL Rotation
    else if (balanceFactor(t) < -1 && t->right->key > key)
    {
        t->right=rightRotate(t->right);
        return leftRotate(t);
    }
    // If so, perform RR Rotation
    else if (balanceFactor(t) > 1 && t->left->key > key)
        return rightRotate(t);
    // If so, perform LR Rotation
    else if (balanceFactor(t) > 1 && t->left->key < key)
    {
        t->left=leftRotate(t->left);
        return rightRotate(t);
    }

    return t;
}

int main()
{
    root = recursiveInsert(root, 10);
    root = recursiveInsert(root, 20);
    root = recursiveInsert(root, 30);
    
    printf("The root Node is: %d\n", root->key);
    
    return 0;
}