#include<stdio.h>
#include <stdlib.h>

struct list
{
    int age,rollno;
    struct list *pre;
    struct list *next;
};
struct list *start=NULL;
struct list *nn(int age,int rollno)
{
    struct list *ptr=(struct list*)malloc(sizeof(struct list));
    ptr->age=age;
    ptr->rollno=rollno;
    ptr->pre=NULL;
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
            start->pre=ptr;
            start->next=ptr;
        }
        else
        {
            ptr1=start;
            while(ptr1->next!=start)
            {
                ptr1=ptr1->next;
            }
            ptr->pre=ptr1;
            ptr->next=start;
            ptr1->next=ptr;
            start->pre=ptr;
        }
        printf("\ndo you want to continue?(y/n): ");
        fflush(stdin);
        ch=getchar();

    }while (ch=='y' || ch=='Y');
}

void fdisplay()
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

void bdisplay()
{
    struct list *ptr=start;
    if (start==NULL)
       printf("\nlist is empty");
    else
    {
        ptr=start->pre;
        do
        {
            printf("\n%d----->%d",ptr->age,ptr->rollno);
            ptr=ptr->pre;

        } while (ptr!=start->pre);
    }
}

int countNode()
{
    struct list *ptr=start;
    int count=0;
    do
    {
        ptr=ptr->next;
        count++;

    } while (ptr!=start);

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
        if(pos==1)
        {
            ptr->pre=start->pre;
            ptr->next=start;
            start->pre->next=ptr;
            start->pre=ptr;
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
            ptr->pre=ptr1;
            ptr->next;
            ptr1->next->pre=ptr;
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
                start->next->pre=start->pre;
                start=start->next;
                free(start->pre->next);
                start->pre->next=start;
            }
        }
        else
        {
            ptr=start;
            count=0;
            while(pos-1>count)
            {
                ptr=ptr->next;
                count++;
            }
            ptr->pre->next=ptr->next;
            ptr->next->pre=ptr->pre;
            free(ptr);
            ptr=NULL;
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
    struct list *ptr=start,*ptr1;
    if (start==NULL)
       printf("\nlist is empty");
    else
    {
        do
        {
            ptr1=ptr->pre;
            ptr->pre=ptr->next;
            ptr->next=ptr1;
            ptr=ptr->pre;  //important step
        }while (ptr!=start);

        start=ptr1->pre;
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
    while (1)
    {
        printf("\n1. Add");
        printf("\n2. Forward Display");
        printf("\n3. Backward Display");
        printf("\n4. CountNode");
        printf("\n5. Insert");
        printf("\n6. Delete");
        printf("\n7. Update");
        printf("\n8. Reverse");
        printf("\n9. Middle Node");
        printf("\n10. Exit");
        printf("\nenter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: add();
                    break;
            case 2: fdisplay();
                    break;
            case 3: bdisplay();
                    break;
            case 4: printf("\ntotal nodes = %d\n",countNode());
                   break;
            case 5: insert();
                    break;
            case 6: delete();
                    break;
            case 7: update();
                    break;
            case 8: reverse();
                    break;
            case 9: middle();
                    break;
            case 10: return 0;
                    break;

            default: printf("\ninvalid choice");
        }
    }
}
