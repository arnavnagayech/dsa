#include<stdio.h>
#include<stdlib.h>

struct stack 
{
    char data;
    struct stack *next;
};
struct stack *top=NULL;
struct stack *nn(char data)
{
    struct stack *ptr=(struct stack*) malloc(sizeof(struct stack));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

void push(char data)
{
    struct stack *ptr;
    ptr=nn(data);
    if (top==NULL)
      top=ptr;
    else
    {
        ptr->next=top, ;
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

int isBalanced(char *str)
{
    for (int i=0;str[i];i++)
    {
        if (str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            push(str[i]);
        }
        else if (str[i]==')')
        {
            if (top==NULL || top->data!='(')
              return 0;
            pop();
        }
        else if (str[i]=='}')
        {
            if (top==NULL || top->data!='{')
              return 0;
            pop();
        }
        else if (str[i]==']')
        {
            if (top==NULL || top->data!='[')
              return 0;
            pop();
        }
    }
    if (top==NULL)
      return 1;
    else
      return 0;
}

int main()
{
    int x;
    char str[20];
    printf("\nenter expression: ");
    scanf("%s",&str);
    x=isBalanced(str);
    if (x==0)
      printf("\nnot balanced");
    else 
      printf("\nbalanced");
}