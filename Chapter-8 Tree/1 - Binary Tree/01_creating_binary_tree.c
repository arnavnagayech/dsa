#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree * newnode(int data)
{
    struct tree *ptr=(struct tree *) malloc (sizeof(struct tree));
    ptr->data=data;
    ptr->left=ptr->right=NULL;
    return ptr;
}

struct queue
{
    struct tree * data;
    struct queue *next;
};
struct queue *front=NULL,*rear=NULL;
struct queue *qnode(struct tree * data)
{
    struct queue *ptr=(struct queue *) malloc (sizeof(struct queue));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

void insert(struct tree * address)
{
    struct queue *ptr;
    ptr=qnode(address);
    if (front==NULL)
    {
        front=rear=ptr;
    }
    else
    {
        rear->next=ptr;
        rear=ptr;
    }
}

struct tree * delete()
{
    struct tree *ptr;
    ptr=front->data;
    if(front==rear)
      front=rear=NULL;
    else
    {
        front=front->next;
    }
    return ptr;
}

struct tree *createBinaryTree()
{
    int data;
    struct tree *root ,*ptr, *ptr1;
    printf("Enter root value: ");
    scanf("%d", &data);
    root=newnode(data);
    insert(root);
    
    while (front!=NULL)
    {
        ptr = delete();
        
        printf("Enter left child of %d (enter -1 if no left child): ", ptr->data);
        scanf("%d", &data);
        if (data != -1)
        {
            ptr1=newnode(data);
            ptr->left=ptr1;
            insert(ptr1);
        }
        printf("Enter right child of %d (enter -1 if no right child): ", ptr->data);
        scanf("%d", &data);
        if (data != -1)
        {
            ptr1=newnode(data);
            ptr->right=ptr1;
            insert(ptr1);
        }
    }
    return root;
}

void preorder(struct tree *t) {
    if (t!=NULL)
    {
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

void inorder(struct tree *t) {
    if (t!=NULL)
    {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}

void postorder(struct tree *t) {
    if (t!=NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%d ", t->data);
    }
}

void LevelOrder(struct tree *t)
{
    struct tree *ptr;
    insert(t);
    while(front!=NULL)
    {
        ptr=delete();
        printf("%d ",ptr->data);
        if (ptr->left!=NULL)
            insert(ptr->left);

        if (ptr->right!=NULL)
            insert(ptr->right);
    }
}

int count(struct tree *t)
{
    if (t!=NULL)
       return count(t->left) + count(t->right) +1;
    return 0;
}

int Height(struct tree *t)
{
    int x=0,y=0;
    if (t==0)
       return 0;
    
    x=Height(t->left);
    y=Height(t->right);
    if (x>y)
        return x+1;
    else
        return y+1;
        
}

int main()
{
    struct tree *root;
    root=createBinaryTree();
    
    printf("\nPreorder: ");
    preorder(root);
    
    printf("\nInorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\nLevelorder: ");
    LevelOrder(root);

    printf("\nnumber of nodes are %d",count(root));

    printf("\nheight is %d",Height(root));
    
    return 0;
}