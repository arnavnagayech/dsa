#include <stdio.h>
#include <stdlib.h>

struct list
{
    int rollno;
    struct list *next;
};
struct list *start = NULL, *start1 = NULL;
struct list *nn(int rollno)
{
    struct list *ptr = (struct list *)malloc(sizeof(struct list));
    ptr->rollno = rollno;
    ptr->next = NULL;
    return ptr;
};
void add()
{
    int rollno;
    char ch;
    struct list *ptr, *ptr1;
    do
    {
        printf("\nenter rollno: ");
        scanf("%d", &rollno);
        ptr = nn(rollno);
        if (start == NULL)
            start = ptr;
        else
        {
            ptr1 = start;
            while (ptr1->next != NULL)
            {
                ptr1 = ptr1->next;
            }
            ptr1->next = ptr;
        }
        printf("\ndo you want to continue?(y/n): ");
        fflush(stdin);
        ch = getchar();

    } while (ch == 'y' || ch == 'Y');
}

void add1()
{
    int rollno;
    char ch;
    struct list *ptr, *ptr1;
    do
    {
        printf("\nenter rollno1: ");
        scanf("%d", &rollno);
        ptr = nn(rollno);
        if (start1 == NULL)
            start1 = ptr;
        else
        {
            ptr1 = start1;
            while (ptr1->next != NULL)
            {
                ptr1 = ptr1->next;
            }
            ptr1->next = ptr;
        }
        printf("\ndo you want to continue?(y/n): ");
        fflush(stdin);
        ch = getchar();

    } while (ch == 'y' || ch == 'Y');
}

void display()
{
    struct list *ptr = start;
    if (start == NULL)
        printf("\nlist is empty");
    else
    {
        while (ptr != NULL)
        {
            printf("%d-->", ptr->rollno);
            ptr = ptr->next;
        }
        printf("null");
    }
}

void display1()
{
    struct list *ptr = start1;
    if (start1 == NULL)
        printf("\nlist is empty");
    else
    {
        printf("\nnew list:\n\n");
        while (ptr != NULL)
        {
            printf("%d-->", ptr->rollno);
            ptr = ptr->next;
        }
        printf("null");
    }
}

void rdisplay(struct list *ptr)
{
    if (ptr != NULL)
    {
        printf("%d-->", ptr->rollno);
        rdisplay(ptr->next);
    }
}

int countNode()
{
    struct list *ptr = start;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void insert()
{
    struct list *ptr, *ptr1;
    int pos, rollno, n, count;
    printf("\nenter position: ");
    scanf("%d", &pos);
    n = countNode();
    if (pos < 1 || pos > n + 1)
        printf("\nnot possible to insert");
    else
    {
        printf("\nenter rollno: ");
        scanf("%d", &rollno);
        ptr = nn(rollno);
        if (pos == 1)
        {
            ptr->next = start;
            start = ptr;
        }
        else
        {
            ptr1 = start;
            count = 0;
            while (pos - 2 > count)
            {
                ptr1 = ptr1->next;
                count++;
            }
            if (pos == n + 1)
            {
                ptr1->next = ptr;
            }
            else
            {
                ptr->next->next = ptr1->next;
                ptr1->next = ptr;
            }
        }
    }
}

void delete ()
{
    int pos, n, count;
    struct list *ptr, *ptr1;
    printf("\nenter position to delete: ");
    scanf("%d", &pos);
    n = countNode();
    if (pos < 1 || pos > n)
        printf("\nnot possible to delete");
    else
    {
        if (pos == 1)
        {
            ptr = start;
            start = ptr->next;
            free(ptr);
            ptr = NULL;
        }
        else
        {
            ptr = start;
            count = 0;
            while (pos - 2 > count)
            {
                ptr = ptr->next;
                count++;
            }
            ptr1 = ptr->next;
            ptr->next = ptr->next->next;
            free(ptr1);
            ptr1 = NULL;
        }
    }
}

void update()
{
    int pos, n, rollno, count;
    struct list *ptr, *ptr1;
    printf("\nenter position to update: ");
    scanf("%d", &pos);
    n = countNode();
    if (pos < 1 || pos > n)
        printf("\nnot possible to update");
    else
    {
        ptr = start;
        count = 0;
        while (pos - 1 > count)
        {
            ptr = ptr->next;
            count++;
        }
        printf("\nenter new rollno: ");
        scanf("%d", &ptr->rollno);
    }
}

void reverse()
{
    struct list *ptr = start, *ptr1 = NULL, *ptr2 = NULL;
    if (start == NULL)
        printf("\nlist is empty");
    else
    {
        ptr = start;
        while (ptr != NULL)
        {
            ptr2 = ptr->next;
            ptr->next = ptr1;
            ptr1 = ptr;
            ptr = ptr2;
        }
        start = ptr1;
    }
}

void middle()
{
    struct list *ptr = start, *ptr1 = start;
    if (start == NULL)
        printf("\nlist is empty");
    else
    {
        while (ptr->next != NULL && ptr->next->next != NULL)
        {
            ptr = ptr->next->next;
            ptr1 = ptr1->next;
        }
        printf("\n%d-->\n", ptr1->rollno);
    }
}

void deleteByRollno()
{
    struct list *ptr = start, *ptr1, *ptr2;
    int rollno;
    printf("\nenter rollno: ");
    scanf("%d", &rollno);
    if (start->rollno == rollno)
    {
        ptr1 = start;
        start = start->next;
        free(ptr1);
        ptr1 = NULL;
    }
    else
    {
        ptr = start;
        while (ptr != NULL && ptr->rollno != rollno)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        if (ptr != NULL)
        {
            ptr1->next = ptr->next;
            free(ptr);
            ptr = NULL;
        }
        else
            printf("\nrollno not present in list");
    }
}

void isSorted()
{
    struct list *ptr = start;
    int rollno = -1, flag = 0;
    while (ptr != NULL)
    {
        if (ptr->rollno < rollno)
        {
            flag = 1;
            break;
        }
        rollno = ptr->rollno;
        ptr = ptr->next;
    }
    if (flag == 1)
        printf("\nunsorted");
    else
        printf("\nsorted");
}

void sort()
{
    struct list *ptr = start, *ptr1;
    int srollno;
    while (ptr != NULL)
    {
        ptr1 = ptr->next;
        while (ptr1 != NULL)
        {
            if (ptr1->rollno > ptr->rollno)
                ptr1 = ptr1->next;
            else
            {
                srollno = ptr1->rollno;
                ptr1->rollno = ptr->rollno;
                ptr->rollno = srollno;
                ptr1 = ptr1->next;
            }
        }
        ptr = ptr->next;
    }
}

void insertAtSortedPosition()
{
    struct list *ptr, *ptr1 = start, *ptr2;
    int rollno;
    printf("\nenter rollno: ");
    scanf("%d", &rollno);
    ptr = nn(rollno);
    if (ptr1->rollno > ptr->rollno)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        while (ptr1 != NULL && ptr1->rollno < ptr->rollno)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
        ptr2->next = ptr;
        ptr->next = ptr1;
    }
}

void isCycle()
{
    if (start == NULL)
        printf("\nEmpty List");
    else
    {
        struct list *slow = start, *fast = start;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (slow == fast)
            printf("\nthere is a cycle");
        else
            printf("\nthere is no cycle");
    }
}

void deleteDuplicateRollnoSorted()
{
    struct list *ptr = start, *ptr1 = NULL;
    if (start == NULL)
        printf("\nlist is empty");
    else
    {
        ptr1 = ptr->next;
        while (ptr1 != NULL)
        {
            if (ptr->rollno != ptr1->rollno)
            {
                ptr = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                ptr->next = ptr1->next;
                free(ptr1);
                ptr1 = ptr->next;
            }
        }
    }
}

void append()
{
    struct list *ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = start1;
}

void merge2ListSortedRollno()
{
    struct list *start2, *last;
    if (start->rollno < start1->rollno)
    {
        start2 = last = start;
        start = start->next;
        last->next = NULL;
    }
    else
    {
        start2 = last = start1;
        start1 = start1->next;
        last->next = NULL;
    }
    while (start != NULL && start1 != NULL)
    {
        if (start->rollno > start1->rollno)
        {
            last->next = start1;
            last = start1;
            start1 = start1->next;
            last->next = NULL;
        }
        else
        {
            last->next = start;
            last = start;
            start = start->next;
            last->next = NULL;
        }
    }
    if (start != NULL)
        last->next = start;

    if (start1 != NULL)
        last->next = start1;

    start = start2;
}

void removeNthFromEnd()
{
    struct list *ptr = start, *ptr1 = start;
    int pos, i;
    printf("\nenter position to remove from last: ");
    scanf("%d", &pos);

    for (i = 0; i < pos; i++)
        ptr = ptr->next;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }

    ptr1->next = ptr1->next->next;
}

void Add2NumbersList()
{
    struct list *start2, *temp, *ptr = start, *ptr1 = start1, *ptr2;
    int rollno, carry = 0;
    start2 = nn(rollno);

    temp = start2;
    while (ptr != NULL || ptr1 != NULL || carry != 0)
    {
        int sum = 0;
        if (ptr != NULL)
        {
            sum += ptr->rollno;
            ptr = ptr->next;
        }
        if (ptr1 != NULL)
        {
            sum += ptr1->rollno;
            ptr1 = ptr1->next;
        }
        sum += carry;
        carry = sum / 10;
        ptr2 = nn(sum % 10);
        temp->next = ptr2;
        temp = temp->next;
    }
    start = start2->next;
}

void IntersectionNode() // correct but no output here
{
    struct list *ptr = start, *ptr1 = start1;

    while (ptr != ptr1)
    {
        if (ptr == NULL)
            ptr = start1;
        else
            ptr = ptr->next;

        if (ptr1 == NULL)
            ptr1 = start;
        else
            ptr1 = ptr1->next;
    }
    printf("\nIntersected at %d", ptr->rollno);
}

void isPalindrome()
{
    if (start == NULL || start->next == NULL)
        printf("\npalindrome");
    else
    {
        //Middle Node
        struct list *slow = start, *fast = start;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse
        struct list *ptr = slow->next, *ptr1 = NULL;
        while (ptr != NULL)
        {
            struct list *temp = ptr->next;
            ptr->next = ptr1;
            ptr1 = ptr;
            ptr = temp;
        }

        slow->next = ptr1;
        slow = slow->next;

        struct list *ptr3 = start;
        while (slow != NULL)
        {
            if (ptr3->rollno != slow->rollno)
            {
                printf("\nNo palindrome");
                break;
            }
            ptr3 = ptr3->next;
            if (slow->next == NULL)
                printf("\nIt is Palindrome");

            slow = slow->next;
        }
    }
}

int StartingPointOfCycle()
{
    if (start == NULL || start->next == NULL)
        return -1;
    else
    {
        struct list *slow = start, *fast = start, *entry = start;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) // there is a cycle
            {
                while (slow != entry) // found the entry location
                {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry->rollno;
            }
        }
        return -1;
    }
}

void rotateRight()
{
    int k;
    printf("\nenter position: ");
    scanf("%d", &k);

    if (start == NULL || start->next == NULL || k == 0)
        rdisplay(start);
    else
    {
        // length
        struct list *ptr = start;
        int len = 1;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            len++;
        }

        // go till that node
        ptr->next = start;
        k = k % len;
        k = len - k;
        while (k--)
        {
            ptr = ptr->next;
        }

        start = ptr->next;
        ptr->next = NULL;

        rdisplay(start);
    }
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
        printf("\n14. Check if Cycle present or Not");
        printf("\n15. Delete Duplicate Rollno in Sorted list");
        printf("\n16. Add new List");
        printf("\n17. Display new List");
        printf("\n18. Append both Lists");
        printf("\n19. Merge 2 Sorted Lists");
        printf("\n20. Remove Nth From End");
        printf("\n21. Add 2 List as Numbers ");
        printf("\n22. Intersection 0f 2 Lists ");
        printf("\n23. Check Palindrome");
        printf("\n24. Starting Point Of Cycle");
        printf("\n25. Rotate Linked List ");
        printf("\n26. Exit");
        printf("\nenter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            add();
            break;
        case 2:
            display();
            break;
        case 3:
            rdisplay(start);
            break;
        case 4:
            printf("\ntotal nodes = %d\n", countNode());
            break;
        case 5:
            insert();
            break;
        case 6:
            delete ();
            break;
        case 7:
            update();
            break;
        case 8:
            reverse();
            break;
        case 9:
            middle();
            break;
        case 10:
            deleteByRollno();
            break;
        case 11:
            isSorted();
            break;
        case 12:
            sort();
            break;
        case 13:
            insertAtSortedPosition();
            break;
        case 14:
            isCycle();
            break;
        case 15:
            deleteDuplicateRollnoSorted();
            break;
        case 16:
            add1();
            break;
        case 17:
            display1();
            break;
        case 18:
            append();
            break;
        case 19:
            merge2ListSortedRollno();
            break;
        case 20:
            removeNthFromEnd();
            break;
        case 21:
            Add2NumbersList();
            break;
        case 22:
            IntersectionNode();
            break;
        case 23:
            isPalindrome();
            break;
        case 24:
            if (StartingPointOfCycle() > -1)
                printf("\nstarting node of cycle\n");
            else
                printf("\nno cycle");
            break;
        case 25:
            rotateRight();
            break;
        case 26:
            return 0;
            break;
        default:
            printf("\ninvalid choice");
        }
    }
    return 0;
}
