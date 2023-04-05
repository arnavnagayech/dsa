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

struct stack 
{
    struct tree * data;
    struct stack *next;
};
struct stack *top=NULL;
struct stack *nn(struct tree * data)
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
    ptr=top;
    if (top!=NULL)
    {
        top=top->next;
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

void preorderIterative(struct tree *t)
{
    while (top!=NULL || t!=NULL)
    {
        if (t!=NULL)
        {
            printf("%d ",t->data);
            push(t);
            t=t->left;
        }
        else
        {
            t=pop();
            t=t->right;
        }
    }
}

void inorderIterative(struct tree *t)
{
    while (top!=NULL || t!=NULL)
    {
        if (t!=NULL)
        {
            push(t);
            t=t->left;
        }
        else
        {
            t=pop();
            printf("%d ",t->data);
            t=t->right;
        }
    }
}

// void postorderIterative(struct tree *t)
// {
//     long int temp;
//     while (top!=NULL || t!=NULL)
//     {
//         if (t!=NULL)
//         {
//             push(t);
//             t=t->left;
//         }
//         else
//         {
//             temp=pop();
//             if (temp>0)
//             {
//                 push(-temp);
//                 t=struct tree *temp->right;
//             }
//             else
//             {
//                 printf("%d ",struct tree *temp->data);
//                 t=NULL;
//             }
//         }
//     }
// }

int main()
{
    struct tree *root;
    root=createBinaryTree();
    
    printf("\nIterative Preorder: ");
    preorderIterative(root);
    
    printf("\nIterative Inorder: ");
    inorderIterative(root);

    // printf("\nIterative Postorder: ");
    // postorderIterative(root);
    
    return 0;
}