#include<stdio.h>
#include <stdlib.h>

struct list
{
    int age,rollno;
    struct list *next;
};
struct list *start=NULL;
struct list *nn(int age,int rollno)
{
    struct list *ptr=(struct list*) malloc(sizeof(struct list));
    ptr->age=age;
    ptr->rollno=rollno;
    ptr->next=NULL;
    return ptr;
}
void add()
{
    int age,rollno;
    char ch;
    struct list *ptr,*ptr1;
    do
    {
        printf("\nenter age: ");
        scanf("%d",&age);
        printf("\nenter rollno: ");
        scanf("%d",&rollno);
        ptr=nn(age,rollno);
        if (start==NULL)
        {
            start=ptr;
            start->next=start;
        }
        else
        {
            ptr1=start;
            while (ptr1->next!=start)
            {
                ptr1=ptr1->next;
            }
            ptr1->next=ptr;
            ptr->next=start;
        }
        printf("\ndo you want to continue?(y/n): ");
        fflush(stdin);
        ch=getchar();

    } while (ch=='y' || ch=='Y');
}

void display()
{
    struct list *ptr=start;
    if (start==NULL)
       printf("\nlist is empty");
    else
    {
        do
        {
            printf("\n%d----->%d",ptr->age,ptr->rollno);
            ptr=ptr->next;
        
        } while (ptr!=start);
    }
}

int countNode()
{
    struct list *ptr=start;
    int count=0;
    if (start==NULL)
      printf("\nlist is empty");
    else
    {
        do
        {
            ptr=ptr->next;
            count++;
        } while (ptr!=start);
    }
    return count;
}

void insert()
{
    int pos,n,count,age,rollno;
    struct list *ptr,*ptr1;
    printf("\nenter position: ");
    scanf("%d",&pos);
    n=countNode();
    if (pos<1 || pos>n+1)
       printf("\nnot possible to insert");
    else
    {
        printf("\nenter age: ");
        scanf("%d",&age);
        printf("\nenter rollno: ");
        scanf("%d",&rollno);
        ptr=nn(age,rollno);
        if (pos==1)
        {
            ptr1=start;
            while(ptr1->next!=start)
              ptr1=ptr1->next;
            ptr->next=start;
            ptr1->next=ptr;
            start=ptr;
        }
        else
        {
            ptr1=start;
            count=0;
            while(pos-2>count)
            {
                ptr1=ptr1->next;
                count++;
            }
            ptr->next=ptr1->next;
            ptr1->next=ptr;
        }
    }
}

void delete()
{
    int pos,n,count;
    struct list *ptr,*ptr1;
    printf("\nenter position: ");
    scanf("%d",&pos);
    n=countNode();
    if (pos<1 || pos>n+1)
       printf("\nnot possible to insert");
    else
    {
        if (pos==1)
        {
            if (start->next==start)
            {
                free(start);
                start=NULL;
            }
            else
            {
                ptr=start;
                while(ptr->next!=start)
                    ptr=ptr->next;
                start=start->next;
                free(ptr->next);
                ptr->next=start;
            }
        }
        else
        {
            ptr=start;
            count=0;
            while(pos-2>count)
            {
                ptr=ptr->next;
                count++;
            }
            ptr1=ptr->next;
            ptr->next=ptr->next->next;
            free(ptr1);
            ptr1=NULL;
        }
    }
}

void update()
{
    int pos,n,count,age,rollno;
    struct list *ptr;
    printf("\nenter position to update: ");
    scanf("%d",&pos);
    n=countNode();
    if (pos<1 || pos>n)
      printf("\nnot possible to update");
    else
    {
        ptr=start;
        count=0;
        while(pos-1>count)
        {
            ptr=ptr->next;
            count++;
        }
        printf("\nenter new age: ");
        scanf("%d",&ptr->age);
        printf("\nenter new rollno: ");
        scanf("%d",&ptr->rollno);
    }
}

void reverse()
{
    struct list *ptr=start,*ptr1=NULL,*ptr2=NULL;
    if (start==NULL)
       printf("\nlist is empty");
    else
    {
        ptr=start;
        do
        {
            ptr2=ptr->next;
            ptr->next=ptr1;
            ptr1=ptr;
            ptr=ptr2;
        }while (ptr!=start);

        start=ptr1;
    }
}

void middle()
{
    struct list *ptr=start,*ptr1=start;
    if(start==NULL)
       printf("\nlist is empty");
    else
    {
        while(ptr->next!=start)
        {
            ptr=ptr->next;
            if (ptr!=NULL)
                ptr=ptr->next;
            ptr1=ptr1->next;
        }
        printf("\n\n%d------>%d\n\n",ptr1->age,ptr1->rollno);   
    } 
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n1. Add");
        printf("\n2. Display");
        printf("\n3. CountNode");
        printf("\n4. Insert");
        printf("\n5. Delete");
        printf("\n6. Update");
        printf("\n7. Reverse");
        printf("\n8. Middle Node");
        printf("\n9. Exit");
        printf("\nenter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: add();
                    break;
            case 2: display();
                    break;
            case 3: printf("\ntotal nodes = %d\n",countNode());
                    break;
            case 4: insert();
                    break;
            case 5: delete();
                    break;
            case 6: update();
                    break;
            case 7: reverse();
                    break;
            case 8: middle();
                    break;
            case 9: return 0;
                    break;

            default: printf("\nwrong choice");
        }
    }
}