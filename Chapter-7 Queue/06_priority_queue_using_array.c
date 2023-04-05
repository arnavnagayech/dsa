#define size 5
#include<stdio.h>
int front=-1,rear=-1;

struct csd
{
    int data;
    int key;
};
struct csd pqueue[size];

void insert()
{
    int data,key,i;
    if (rear==size-1)
      printf("\nqueue is full\n");
    else
    {
        printf("\nenter data: ");
        scanf("%d",&data);
        printf("\nenter key: ");
        scanf("%d",&key);
        if (front==-1)
        {
            i=-1;
            front=0;
        }
        else
        {
            for (i=rear;i>=0 && pqueue[i].key<key;i--)
                pqueue[i+1]=pqueue[i];
        }
        pqueue[i+1].data=data;
        pqueue[i+1].key=key;
        rear++;
    }
}

void delete()
{
    if(front==-1)
      printf("\nqueue is empty\n");
    else
    {
        rear--;
        if(rear==-1)
            front=-1;
    }
}

void display()
{
    if (front==-1)
      printf("\nqueue is empty\n");
    else
    {
        for (int i=rear;i>=front;i--)
            printf("\n%d----->%d",pqueue[i].data,pqueue[i].key);
    }
}

int main()
{
    int ch;
    while (1)
    {
       printf("\n1.Insert");
       printf("\n2.Delete");
       printf("\n3.Display");
       printf("\n4.Exit");
       printf("\nenter your choice: ");
       scanf("%d",&ch);
       switch (ch)
       {
        case 1: insert();
                break;
        case 2: delete();
                break;
        case 3: display();
                break;
        case 4: return 0;
                break;
        default: printf("\ninvalid choice\n");
       }
    }
    return 0;
}