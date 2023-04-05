#include<stdio.h>

void merge(int A[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    int B[100];

    while (i<=mid && j<=high)
    {
        if (A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for (;i<=mid;i++)
        B[k++]=A[i];
    for (;j<=high;j++)
        B[k++]=A[j];

    for (int i=low ; i<=high ; i++)
        A[i]=B[i];
}

void mergeSort(int A[],int n)
{
    int p,low,mid,high;
    for (p=2;p<=n;p=p*2)
    {
        for (int i=0;i+p-1<=n;i=i+p)
        {
            low=i;
            high=i+p-1;
            mid=(low+high)/2;
            merge(A,low,mid,high);
        }
    }
    if (p/2<n)
        merge(A,0,p/2-1,n);
}

int main()
{
    int A[]={1,5,9,2,4,8,7,6,3,10},n=10;
    mergeSort(A,n);
    printf("\nAfter Sorting:\n");
    for (int i=0;i<10;i++)
        printf("%d ",A[i]);
    
    printf("\n\n");
    return 0;
}