#include <stdio.h>
#include <stdlib.h>

int findmax(int A[], int n)
{
    int max=TMP_MAX;
    for (int i=0;i<n;i++)
    {
        if (A[i]>max)
            max=A[i];
    }
    
    return max;
}

void countSort(int A[], int n)
{
    int i,j;
    int max=findmax(A,n);
    int *count=(int*)malloc(sizeof(int)*(max+1));

    for (i=0;i<max+1;i++)
    {
        count[i]=0;
    }
    for (i=0;i<n;i++)
    {
        count[A[i]]++;
    }
    i=0;
    j=0;
    while(j<max+1)
    {
        if (count[j]>0)
        {
            A[i++]=j;
            count[j]--;
        }
        else
            j++;
    }
}

int main()
{
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n = 10;
    countSort(A,n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n\n");
    
    return 0;
}