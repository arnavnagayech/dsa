#include<stdio.h>
#include<stdlib.h>

void display(int arr[],int size)
{
    for(int i=0;i<=size-1;i++)
      printf("\n%d",arr[i]);
}

int delete(int arr[],int capacity,int size,int index)
{
    if(size>=index)
    {
        for(int i=index;i<=size-1;i++)
        {
            arr[i]=arr[i+1];
        }
        return 1;
    }
    else
     return -1;
    
}

int main()
{
    int arr[100];
    int size,index,capacity=100,l;
    printf("\nenter size: ");
    scanf("%d",&size);
    if (size==0)
    {
        printf("empty array\n");
        exit(0);
    }
       
    for(int i=0;i<=size-1;i++)
    {
        printf("\nenter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    display(arr,size);
    printf("\nenter index at which need to delete: ");
    scanf("%d",&index);
    l=delete(arr,capacity,size,index);
    if(l==1)
    {
        size=size-1;
        display(arr,size);
    }
    else
      printf("\nindex out of range");
      
    
    return 0;
}