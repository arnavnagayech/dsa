#include<stdio.h>
#include<stdlib.h>

struct list
{
    int age,rollno;
    struct list*next;
};
struct list *start=NULL, *start1=NULL;
struct list *nn(int age,int rollno)
{
    struct list *ptr=(struct list*) malloc(sizeof(struct list));
    ptr->age=age;
    ptr->rollno=rollno;
    ptr->next=NULL;
    return ptr;
};
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
        if(start==NULL)
            start=ptr;
        else
        {
            ptr1=start;
            while (ptr1->next!=NULL)
            {
                ptr1=ptr1->next;
            }
            ptr1->next=ptr;
        }
        printf("\ndo you want to continue?(y/n): ");
        fflush(stdin);
        ch=getchar();

    }while(ch=='y' || ch=='Y');
}

void add1()
{
    int age,rollno;
    char ch;
    struct list *ptr,*ptr1;
    do
    {
        printf("\nenter age1: ");
        scanf("%d",&age);
        printf("\nenter rollno1: ");
        scanf("%d",&rollno);
        ptr=nn(age,rollno);
        if(start1==NULL)
            start1=ptr;
        else
        {
            ptr1=start1;
            while (ptr1->next!=NULL)
            {
                ptr1=ptr1->next;
            }
            ptr1->next=ptr;
        }
        printf("\ndo you want to continue?(y/n): ");
        fflush(stdin);
        ch=getchar();

    }while(ch=='y' || ch=='Y');
}

void display()
{
    struct list *ptr=start;
    if(start==NULL)
       printf("\nlist is empty");
    else
    {
        while (ptr!=NULL)
        {
            printf("\n%d----->%d",ptr->age,ptr->rollno);
            ptr=ptr->next;
        }
    }
}

void display1()
{
    struct list *ptr=start1;
    if(start1==NULL)
       printf("\nlist is empty");
    else
    {
        printf("\nnew list:\n");
        while (ptr!=NULL)
        {
            printf("\n%d----->%d",ptr->age,ptr->rollno);
            ptr=ptr->next;
        }
    }
}

void rdisplay(struct list *ptr)
{
    if (ptr!=NULL)
    {
        printf("\n%d----->%d",ptr->age,ptr->rollno);
        rdisplay(ptr->next);
    }
}

int countNode()
{
    struct list *ptr=start;
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    return count;
}

void insert()
{
    struct list *ptr,*ptr1;
    int pos,age,rollno,n,count;
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
            ptr->next=start;
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
            if(pos==n+1)
            {
                ptr1->next=ptr;
            }
            else
            {
                ptr->next->next=ptr1->next;
                ptr1->next=ptr;
            }
        }
    }
}

void delete()
{
    int pos,n,count;
    struct list *ptr,*ptr1;
    printf("\nenter position to delete: ");
    scanf("%d",&pos);
    n=countNode();
    if (pos<1 || pos>n)
       printf("\nnot possible to delete");
    else
    {
        if (pos==1)
        {
            ptr=start;
            start=ptr->next;
            free(ptr);
            ptr=NULL;
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
    int pos,n,age,rollno,count;
    struct list *ptr,*ptr1;
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
        while (ptr!=NULL)
        {
            ptr2=ptr->next;
            ptr->next=ptr1;
            ptr1=ptr;
            ptr=ptr2;
        }
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
        while(ptr!=NULL && ptr->next!=NULL)
        {
            ptr=ptr->next->next;
            if (ptr!=NULL)
                ptr1=ptr1->next;
        }
        printf("\n%d------>%d\n",ptr1->age,ptr1->rollno);   
    } 
}

void deleteByRollno()
{
    struct list *ptr=start,*ptr1,*ptr2;
    int rollno;
    printf("\nenter rollno: ");
    scanf("%d",&rollno);
    if (start->rollno==rollno)
    {
        ptr1=start;
        start=start->next;
        free(ptr1);
        ptr1=NULL;
    }
    else
    {
        ptr=start;
        while(ptr!=NULL && ptr->rollno!=rollno)
        {
            ptr1=ptr;
            ptr=ptr->next;
        }
        if (ptr!=NULL)
        {
            ptr1->next=ptr->next;
            free(ptr);
            ptr=NULL;
        }
        else
           printf("\nrollno not present in list");
    }
}

void isSorted()
{
    struct list *ptr=start;
    int rollno=-1,flag=0;
    while(ptr!=NULL)
    {
        if(ptr->rollno<rollno)
        {
            flag=1;
            break;
        }
        rollno=ptr->rollno;
        ptr=ptr->next;
    }
    if (flag==1)
      printf("\nunsorted");
    else
      printf("\nsorted");
}

void sort()
{
    struct list *ptr=start, *ptr1;
    int srollno;
    while(ptr!=NULL)
    {
        ptr1=ptr->next;
        while(ptr1!=NULL)
        {
            if(ptr1->rollno > ptr->rollno)
               ptr1=ptr1->next;
            else
            {
                srollno = ptr1->rollno;
                ptr1->rollno = ptr->rollno;
                ptr->rollno = srollno;
                ptr1 = ptr1->next;
            }
        }
        ptr=ptr->next;
   }
}

void insertAtSortedPosition()
{
    struct list *ptr,*ptr1=start,*ptr2;
    int age,rollno;
    printf("\nenter age: ");
    scanf("%d",&age);
    printf("\nenter rollno: ");
    scanf("%d",&rollno);
    ptr=nn(age,rollno);
    if (ptr1->rollno>ptr->rollno)
    {
        ptr->next=start;
        start=ptr;
    }
    else
    {
        while (ptr1!=NULL && ptr1->rollno<ptr->rollno)
        {
            ptr2=ptr1;
            ptr1=ptr1->next;
        }
        ptr2->next=ptr;
        ptr->next=ptr1;
    }
}

void isLoop()
{
    struct list *ptr=start,*ptr1=start;
    do
    {
        ptr=ptr->next;
        ptr1=ptr1->next;
        if (ptr1!=NULL)
           ptr1=ptr1->next;

    } while (ptr!=ptr1 && ptr!=NULL && ptr1!=NULL);
    if (ptr==ptr1 && ptr1!=NULL)
       printf("\nthere is a cycle");
    else
       printf("\nthere is no cycle");
}

void deleteDuplicateRollnoSorted()
{
    struct list *ptr=start,*ptr1=NULL;
    if (start==NULL)
      printf("\nlist is empty");
    else
    {
        ptr1=ptr->next;
        while (ptr1!=NULL)
        {
            if (ptr->rollno!=ptr1->rollno)
            {
                ptr=ptr1;
                ptr1=ptr1->next;
            }
            else
            {
                ptr->next=ptr1->next;
                free(ptr1);
                ptr1=ptr->next;
            }
        }
    }
}

void append()
{
    struct list *ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=start1;
}

void merge2ListSortedRollno()
{
    struct list *start2,*last;
    if (start->rollno < start1->rollno)
    {
        start2 = last = start;
        start = start->next;
        last->next = NULL;
    }
    else
    {
        start2=last=start1;
        start1=start1->next;
        last->next=NULL;
    }
    while(start!=NULL && start1!=NULL)
    {
        if (start->rollno > start1->rollno)
        {
            last->next=start1;
            last=start1;
            start1=start1->next;
            last->next=NULL;
        }
        else
        {
            last->next=start;
            last=start;
            start=start->next;
            last->next=NULL;
        }
    }
    if (start!=NULL)
       last->next=start;
       
    if (start1!=NULL)
        last->next=start1;
        
    start=start2;
}

void removeNthFromEnd() 
{
    struct list *ptr=start, *ptr1=start;   
	int pos, i;
	printf("\nenter position to remove from last: ");
    scanf("%d",&pos);

    for(i=0;i<pos;i++)
    	ptr = ptr->next;
    
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }
        
    ptr1->next = ptr1->next->next;
}



int main()
{
    int ch;
    while (1)
    {
        printf("\n1. Add");
        printf("\n2. Display");
        printf("\n3. rdisplay");
        printf("\n4. CountNode");
        printf("\n5. Insert");
        printf("\n6. Delete");
        printf("\n7. Update");
        printf("\n8. Reverse");
        printf("\n9. Middle Node");
        printf("\n10. Delete By Rollno");
        printf("\n11. Check Sorted or not");
        printf("\n12. Sort Given LinkedList");
        printf("\n13. Insert at Sorted Position");
        printf("\n14. Check if Loop present or Not");
        printf("\n15. Delete Duplicate Rollno in Sorted list");
        printf("\n16. Add new List");
        printf("\n17. Display new List");
        printf("\n18. Append both Lists");
        printf("\n19. Merge 2 Sorted Lists");
        printf("\n20. Remove Nth From End");
        printf("\n21. Exit");
        printf("\nenter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: add();
                    break;
            case 2: display();
                    break;
            case 3: rdisplay(start);
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
            case 10: deleteByRollno();
                    break;
            case 11: isSorted();
                    break;
            case 12: sort();
                    break;
            case 13: insertAtSortedPosition();
                    break;
            case 14: isLoop();
                    break;
            case 15: deleteDuplicateRollnoSorted();
                    break;
            case 16: add1();
                    break;
            case 17: display1();
                    break;
            case 18: append();
                    break;
            case 19 : merge2ListSortedRollno();
                    break;
            case 20 : removeNthFromEnd();
                    break;
            case 21: return 0;
                    break;
            default: printf("\ninvalid choice");
        }
    }
}
