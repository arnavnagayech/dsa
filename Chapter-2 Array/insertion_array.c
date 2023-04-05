#include<stdio.h>

void display(int arr[],int size)
{
    for(int i=0;i<=size-1;i++)
      printf("\n%d",arr[i]);
}

int insert(int arr[],int capacity,int size,int element,int index)
{
    if(size>=capacity)
       return -1;
    else
    {
        for(int i=index;i<=size-1;i++)
        {
            arr[i+1]=arr[i];
        }
        arr[index]=element;
        return 1;
    }
    
}
int main()
{
    int arr[100];
    int size,element,index,capacity=100;
    printf("\nenter size: ");
    scanf("%d",&size);
    for(int i=0;i<=size-1;i++)
    {
        printf("\nenter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    display(arr,size);
    printf("\nenter element to insert: ");
    scanf("%d",&element);
    printf("\nenter index at which need to insert: ");
    scanf("%d",&index);
    insert(arr,capacity,size,element,index);
    size=size+1;
    display(arr,size);
    return 0;
}