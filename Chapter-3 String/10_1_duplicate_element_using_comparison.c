#include<stdio.h>

void duplicate(char A[])
{
    int i,j,count;
    for (i=0;A[i]!='\0';i++)
    {
        count=1;
        for (j=0;A[j]!='\0';j++)
        {
            if (j>i)
            {
                if (A[i]==A[j])
                    count++;
            }
        }
        if (count>1)
           printf("\ncharacter %c present %d times",A[i],count);
    }
}
int main()
{
    char A[]="finding";
    duplicate(A);
    return 0;
}