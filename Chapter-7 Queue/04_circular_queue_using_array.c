#define size 5
#include<stdio.h>
int cqueue[size];
int front=-1,rear=-1;

void insert()
{
    if ((rear+1)%size == front)
       printf("\nqueue is full");
    else
    {
        if (front==-1)
            front=rear=0;
        else if (rear==size-1)
            rear=0;
        else
            rear++;
        printf("\nenter data: ");
        scanf("%d",&cqueue[rear]);
    }
}

void delete()
{
    if (front==-1)
       printf("\nqueue is empty");
    else
    {
        if (front==rear)
            front=rear=-1;
        else if (front==size-1)
            front=0;
        else 
            front++;
    }
}

void display()
{
    if (front==-1)
       printf("\nqueue is empty");
    else 
    {
        if (rear>=front)
        {
            for (int i=front;i<=rear;i++)
                printf("\n%d",cqueue[i]);
        }
        else
        {
            for (int i=front;i<=size-1;i++)
                printf("\n%d",cqueue[i]);
            for (int i=0;i<=rear;i++)
                printf("\n%d",cqueue[i]);
        }
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
        default:printf("\ninvalid choice\n");
       }
    }
    return 0;
}