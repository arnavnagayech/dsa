#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree *root=NULL;

struct stack 
{
    struct tree * data;
    struct stack *next;
};

struct stack *top=NULL;
struct stack *nn(struct tree *data)
{
    struct stack *ptr=(struct stack*) malloc(sizeof(struct stack));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

void push(struct tree *data)
{
    struct stack *ptr;
    ptr=nn(data);
    if (top==NULL)
      top=ptr;
    else
    {
        ptr->next=ptr;
        top=ptr;
    }
}

struct tree * pop()
{
    struct tree *ptr;
    ptr=top->data;
    if (top!=NULL)
    {
        top=top->next;
    }
    return ptr;
}

void inorder(struct tree *t)
{
    if (t!=NULL)
    {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}

struct tree * createPreorder(int pre[],int n)
{
    struct tree *t,*p;
    int i=0;
    struct tree *root=(struct tree*) malloc(sizeof(struct tree));
    root->data=pre[i++];
    root->left=root->right=NULL;
    p=root;
    while(i<n)
    {
        if (pre[i]<p->data)
        {
            struct tree *t=(struct tree*) malloc(sizeof(struct tree));
            t->data=pre[i++];
            t->left=t->right=NULL;
            p->left=t;
            push(p);
            p=t;
        }
        else
        {
            if (pre[i] > p->data && pre[i] < top->data)
            {
                struct tree *t=(struct tree*) malloc(sizeof(struct tree));
                t->data=pre[i++];
                t->left=t->right=NULL;
                p->right=t;
                p=t;
            }
            else
              p=pop();
        }
    }
}

int main () 
{ 
    int pre[] = {10, 5, 1, 7, 40, 50}; 
    int size = sizeof( pre ) / sizeof( pre[0] ); 
  
    struct tree *root = createPreorder(pre, size); 
  
    printf("Inorder traversal of the constructed tree: \n"); 
    inorder(root); 
  
    return 0; 
} 