#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    int height;
    struct tree *left;
    struct tree *right;
};
struct tree *root=NULL;

int nodeHeight(struct tree *t) {
    int hl, hr;
    hl = t && t->left ? t->left->height : 0;
    hr = t && t->right ? t->right->height : 0;
    
    return hl>hr ? hl+1 : hr+1;
}

int balanceFactor(struct tree *t) {
    int hl, hr;
    hl = t && t->left ? t->left->height : 0;
    hr = t && t->right ? t->right->height : 0;
    
    return hl-hr;
}

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

struct tree* LLrotation(struct tree *t)
{
    struct tree *pl = t->left;
    struct tree *plr = pl->right;
    
    pl->right = t;
    t->left = plr;
    t->height = nodeHeight(t);
    pl->height = nodeHeight(pl);
    
    // If the node we are rotating is root, update it
    if (t == root)
        root = pl;
    
    return pl;
}

struct tree* LRrotation(struct tree *t) {
    struct tree *pl = t->left;
    struct tree *plr = pl->right;
    
    pl->right = plr->left;
    t->left = plr->right;
    
    plr->left = pl;
    plr->right = t;
    
    t->height = nodeHeight(t);
    pl->height = nodeHeight(pl);
    plr->height = nodeHeight(plr);
    
    // If the node we are rotating is root, update it
    if (root == t)
        root = plr;
    
    return plr;
}

// Not implemented
struct tree* RRrotation(struct tree *t)
{
    return NULL;
}

// Not implemented
struct tree* RLrotation(struct tree *t)
{
    return NULL;
}

struct tree* recursiveInsert(struct tree *t, int key) {
    
    if (t == NULL) {
        struct tree *t = (struct tree *)malloc(sizeof(struct tree));
        t->data = key;
        t->height = 1; // height of 1 because 't' is the only node currently in BST
        t->left = t->right = NULL;
        return t;
    }
    
    if (key < t->data)
    {
        t->left = recursiveInsert(t->left, key);
    }
    else if (key > t->data) {
        t->right = recursiveInsert(t->right, key);
    }
    t->height = nodeHeight(t);
    
    // If so, perform LL Rotation
    if (balanceFactor(t) == 2 && balanceFactor(t->left) == 1)
        return LLrotation(t);
    // If so, perform LR Rotation
    else if (balanceFactor(t) == 2 && balanceFactor(t->left) == -1)
        return LRrotation(t);
    // If so, perform RR Rotation
    else if (balanceFactor(t) == -2 && balanceFactor(t->right) == -1)
        return RRrotation(t);
    // If so, perform RL Rotation
    else if (balanceFactor(t) == -2 && balanceFactor(t->right) == 1)
        return RLrotation(t);
    
    return t;
}

int main()
{
    root = recursiveInsert(root, 10);
    root = recursiveInsert(root, 5);
    root = recursiveInsert(root, 2);
    
    printf("The root Node is: %d\n", root->data);
    
    return 0;
}