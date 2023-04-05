#include<stdio.h>
#include<stdlib.h>

struct stack 
{
    int data;
    struct stack *next;
};
struct stack *top=NULL;
struct stack *nn(int data)
{
    struct stack *ptr=(struct stack*) malloc(sizeof(struct stack));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

void push()
{
    struct stack *ptr;
    int data;
    printf("\nenter data: ");
    scanf("%d",&data);
    ptr=nn(data);
    if (top==NULL)
      top=ptr;
    else
    {
        ptr->next=top;
        top=ptr;
    }
}

void pop()
{
    struct stack *ptr;
    if (top==NULL)
      printf("\nstack is empty\n");
    else
    {
        ptr=top;
        top=top->next;
        free(ptr);
        ptr=NULL;
    }
}

void peek()
{
    if (top==NULL)
      printf("\nstack is empty\n");
    else
    {
        printf("\n%d\n",top->data);
    }
}

void display()
{
   struct stack *ptr;
    if (top==NULL)
      printf("\nstack is empty\n");
    else
    {
        ptr=top;
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
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peek");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\nenter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: push();
                    break; 
            case 2: pop();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            case 5: return 0;
                    break;

            default: printf("\ninvalid choice");
        }
    }
    return 0;
}
