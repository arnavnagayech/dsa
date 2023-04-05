#include<stdio.h>
#include<stdlib.h>

struct cqueue
{
    int data;
    struct cqueue *next;
};
struct cqueue *front=NULL,*rear=NULL;
struct cqueue *nn(int data)
{
    struct cqueue *ptr=(struct cqueue *) malloc (sizeof(struct cqueue));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

void insert()
{
    struct cqueue *ptr;
    int data;
    printf("\nenter data: ");
    scanf("%d",&data);
    ptr=nn(data);
    if (front==NULL)
    {
        front=rear=ptr;
        front->next=front;
    }
    else
    {
        rear->next=ptr;
        rear=ptr;
        rear->next=front;
    }
}

void delete()
{
    struct cqueue *ptr;
    if(front==NULL)
      printf("\nqueue is empty\n");
    else if (front==rear)
    {  
        free(front);
        front=rear=NULL;
    }
    else
    {
        ptr=front;
        front=front->next;
        rear->next=front;
        free(ptr);
        ptr=NULL;
    }
}

void display()
{
    struct cqueue *ptr=front;
    if (front==NULL)
      printf("\nqueue is empty\n");
    else
    {
        do
        {
            printf("\n%d",ptr->data);
            ptr=ptr->next;
        }while(ptr!=front);
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