#include<stdio.h>
#include<stdlib.h>

char postfix[30]="100 20 - 15 5 + /";
struct stack 
{
    char data;
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

void push(int data)
{
    struct stack *ptr;
    ptr=nn(data);
    if (top==NULL)
      top=ptr;
    else
    {
        ptr->next=top;
        top=ptr;
    }
}

int pop()
{
    struct stack *ptr;
    int data=top->data;
    ptr=top;
    top=top->next;
    free(ptr);
    ptr=NULL;
    return data;
}


void PostfixEvaluation()
{
    int i,n,x,y;
    for (i=0;postfix[i];i++)
    {
        if(isdigit(postfix[i]))
        {
           n=0;
           while (isdigit(postfix[i]))
           {
               n=n*10+(postfix[i]-'0');
               i++;
           }
           push(n);
        }
        else if (postfix[i]==' ')
        {
            continue;
        }
        else
        {
            x=pop();
            y=pop();
            if (postfix[i]=='-')
                push(y-x);
            else if (postfix[i]=='+')
                push(y+x);
            else if (postfix[i]=='*')
                push(y*x);
            else if (postfix[i]=='/')
                push(y/x);
        }
    }
    printf("\n%d",pop());
}

int main()
{
    PostfixEvaluation();
}