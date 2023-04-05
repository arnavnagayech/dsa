#include<stdio.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void selectionSort(int A[],int n)
{
    int i,j,k;
    for (i=0;i<n-1;i++)
    {
        for (j=k=i;j<n;j++)
        {
            if (A[j] < A[k])
                k=j;
        }
        swap(&A[i],&A[k]);
    }
}

int main()
{
    int A[]={3,7,9,10,6,5,12,4,11,2},n=10;
    selectionSort(A,n);
    printf("\nAfter Sorting:\n");
    for (int i=0;i<n;i++)
        printf("%d ",A[i]);
    
    printf("\n\n");
    return 0;
}