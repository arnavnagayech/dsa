#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree *root=NULL;
struct tree * newnode(int data)
{
    struct tree *ptr=(struct tree *) malloc (sizeof(struct tree));
    ptr->data=data;
    ptr->left=ptr->right=NULL;
    return ptr;
}

struct tree * RecursiveSearch(struct tree *t,int key)
{
    if (t!=NULL)
    {
        if (key==t->data)
            return t;
        else if (key < t->data)
            return RecursiveSearch(t->left,key);
        else
            return RecursiveSearch(t->right,key);
    }
    else
        return NULL;
}

struct tree * search(struct tree *t,int key)
{
    while (t!=NULL)
    {
        if (key==t->data)
            return t;
        else if (key < t->data)
            t=t->left;
        else
            t=t->right;
    }
    return NULL;
}

struct tree * RecursiveInsert(struct tree *t,int key)
{
    struct tree *p;
    if (t==NULL)
    {
        p=newnode(key);
        t=p;
        return t;
    }
    if (key < t->data)
           t->left=RecursiveInsert(t->left,key);
    else if (key > t->data)
            t->right=RecursiveInsert(t->right,key);

    return t;
}

void insert(int key)
{
    struct tree *t=root,*r=NULL,*p;
    if (root=NULL)
    {
        p=newnode(key);
        root=p;
        return;
    }
    while (t!=NULL)
    {
        r=t;
        if (key==t->data)
            return ;
        else if (key < t->data)
            t=t->left;
        else
            t=t->right;
    }
    p=newnode(key);
    if (p->data < r->data)
        r->left=p;
    else
        r->right=p;

}

void inorder(struct tree *t) {
    if (t!=NULL)
    {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}

struct tree * inpre(struct tree *t)
{
    while (t!=NULL && t->right)
        t=t->right;
    return t;
}

struct tree * inSucc(struct tree *t)
{
    while (t!=NULL && t->left)
        t=t->left;
    return t;
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

struct tree *delete(struct tree *t,int key)
{
    struct tree *p1;
    if (t!=NULL)
    {
        if (!(t->left!=NULL) && !(t->right!=NULL))
        {
            if (t==root && t->data==key)
            {
                root=NULL;
                return NULL;
            }
            free(t);
            return NULL;
        }
        else
        {
            if (key > t->data)
                t->right=delete(t->right,key);
            else if (key < t->data)
                t->left=delete(t->left,key);
            else
            {
                if (Height(t->left) < Height(t->right))
                {
                    p1=inSucc(t->right);
                    t->data=p1->data;
                    t->right=delete(t->right,p1->data);
                }
                else
                {
                    p1=inpre(t->left);
                    t->data=p1->data;
                    t->left=delete(t->left,p1->data);
                }
            }
        }
        return t;
    }
    return NULL;
}
int main()
{
    struct tree *root=NULL,*temp,*temp1;
    root=RecursiveInsert(root,60);
    RecursiveInsert(root,50);
    RecursiveInsert(root,40);
    RecursiveInsert(root,70);
    RecursiveInsert(root,55);
    RecursiveInsert(root,75);
    inorder(root);
    delete(root,70);
    delete(root,55);
    delete(root,75);
    printf("\n\n\n");
    inorder(root);

    temp=search(root,50);
    if (temp!=NULL)
        printf("\nelement %d is present",temp->data);
    else
        printf("\nelement not found");

    temp1=RecursiveSearch(root,90);
    if (temp1!=NULL)
        printf("\nelement %d is present",temp->data);
    else
        printf("\nelement not found");

    return 0;
}