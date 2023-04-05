#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};
struct queue *front=NULL,*rear=NULL;
struct queue *nn(int data)
{
    struct queue *ptr=(struct queue *) malloc (sizeof(struct queue));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

void insert()
{
    struct queue *ptr;
    int data;
    printf("\nenter data: ");
    scanf("%d",&data);
    ptr=nn(data);
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

void delete()
{
    struct queue *ptr;
    if(front==NULL)
      printf("\nqueue is empty\n");
    else
    {
        ptr=front;
        front=front->next;
        free(ptr);
        ptr=NULL;
    }
}

void display()
{
    struct queue *ptr=front;
    if (front==NULL)
      printf("\nqueue is empty\n");
    else
    {
        while(ptr!=NULL)
        {
            printf("\n%d",ptr->data);
            ptr=ptr->next;
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