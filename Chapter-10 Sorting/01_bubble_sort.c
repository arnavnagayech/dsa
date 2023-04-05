#include<stdio.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void bubbleSort(int A[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        int flag=0;
        for (int j=0;j<n-i-1;j++)
        {
            if (A[j]>A[j+1])
            {
                swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
        if (flag==0)
            break;
    }
}

int main()
{
    int A[]={3,7,9,10,6,5,12,4,11,2},n=10;
    bubbleSort(A,n);
    printf("\nAfter Sorting:\n");
    for (int i=0;i<n;i++)
        printf("%d ",A[i]);
    
    printf("\n\n");
    return 0;
}