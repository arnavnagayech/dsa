#define size 5
#include<stdio.h>
int queue[size];
int front=-1,rear=-1;

void insert()
{
    if (rear==size-1)
      printf("\nqueue is full\n");
    else
    {
        printf("\nenter data: ");
        scanf("%d",&queue[++rear]);
        if (rear==0)
            front=0;
    }
}

void delete()
{
    if(front==-1)
      printf("\nqueue is empty\n");
    else
    {
        for (int i=front;i<rear;i++)
            queue[i]=queue[i+1];
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
        for (int i=front;i<=rear;i++)
            printf("\n%d",queue[i]);
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