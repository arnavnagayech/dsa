#include<stdio.h>
#include<stdlib.h>

struct dequeue
{
    int data;
    struct dequeue *next;
};
struct dequeue *front=NULL,*rear=NULL;
struct dequeue *nn(int data)
{
    struct dequeue *ptr=(struct dequeue *) malloc (sizeof(struct dequeue));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

void insertLeft()
{
    struct dequeue *ptr;
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
        ptr->next=front;
        front=ptr;
    }
}

void insertRight()
{
   struct dequeue *ptr;
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

void deleteLeft()
{
     struct dequeue *ptr;
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

void deleteRight()
{
    struct dequeue *ptr=front,*ptr1=rear;
    if(front==NULL)
      printf("\nqueue is empty\n");
    else
    {
        while(ptr->next!=rear)
        {
            ptr=ptr->next;
        }
        ptr->next=NULL;
        rear=ptr;
        free(ptr1);
        ptr1=NULL;
    }
}

void display()
{
    struct dequeue *ptr=front;
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
       printf("\n1.Insert Left");
       printf("\n2.Insert Right");
       printf("\n3.Delete Left");
       printf("\n4.Delete Right");
       printf("\n5.Display");
       printf("\n6.Exit");
       printf("\nenter your choice: ");
       scanf("%d",&ch);
       switch (ch)
       {
        case 1: insertLeft();
                break;
        case 2: insertRight();
                break;
        case 3: deleteLeft();
                break;
        case 4: deleteRight();
                break;
        case 5: display();
                break;
        case 6: return 0;
                break;
        default: printf("\ninvalid choice\n");
       }
    }
    return 0;
}