#define size 5
#include<stdio.h>
int stack[size];
int top=-1;

void push()
{
    if (top==size-1)
      printf("\nstack is full\n");
    else
    {
        printf("\nenter age: ");
        scanf("%d",&stack[++top]);
    }
}

void pop()
{
    if (top==-1)
      printf("\nstack is empty\n");
    else
    {
        top--;
    }
}

void peek()
{
    if (top==-1)
      printf("\nstack is empty\n");
    else
    {
        printf("\nelement on top is %d\n",stack[top]);
    }
}

void display()
{
    if (top==-1)
      printf("\nstack is empty\n");
    else
    {
        printf("\n\nelements in stack are: ");
        for (int i=top;i>=0;i--)
          printf("\n%d",stack[i]);
    }
}

char* isEmpty()
{
    if (top==-1)
      return "true";
    else
    return "false";
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
        printf("\n5.IsEmpty");
        printf("\n6.Exit");
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
            case 5: printf("\n%s\n",isEmpty());
                    break;
            case 6: return 0;
                    break;

            default: printf("\ninvalid choice");
        }
    }
    return 0;
}