#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *nn(int key)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=key;
    ptr->next=NULL;
    return ptr;
}

void sortedInsert(struct Node **H,int key)
{
    struct Node *ptr,*q=NULL,*p=*H;
    ptr=nn(key);
    if (*H==NULL)
        *H=ptr;
    else
    {
        while (ptr!=NULL && ptr->data< key)
        {
            q=p;
            p=p->next;
        }
        if (p==*H)
        {
            ptr->next=*H;
            *H=ptr;
        }
        else
        {
            ptr->next=q->next;
            q->next=ptr;
        }
    }
}

struct Node *search(struct Node *p,int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
            return p;
        p=p->next;
    }
    return NULL;
}

int hash(int key)
{
    return key % 10;
}

void insert(struct Node *H[], int key)
{
    int index = hash(key);
    sortedInsert(&H[index], key);
}

int main()
{
    // array of pointers
    struct Node *HT[10]; // a hash table of size 10
    struct Node *temp;
    
    for (int i = 0; i < 10; i++)
        HT[i] = NULL;
    
    insert(HT, 12);
    insert(HT, 22);
    insert(HT, 42);
    
    temp = search(HT[hash(22)], 22);
    printf("%d\n", temp->data);
    
    return 0;
}