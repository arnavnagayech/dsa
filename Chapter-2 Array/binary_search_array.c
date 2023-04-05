#include<stdio.h>

int binarySearch(int arr[],int size,int key)
{
  int start=0,end=size-1,mid;
  while(start<=end)
  {
        mid = (start + end)/2;
        if(arr[mid] == key)
            return mid;
        if(arr[mid]<key)
            start = mid+1;
        else
            end = mid -1;
   }
   return -1;
}

int main()
{
    int size,arr[size],l,key;
    printf("\nenter size: ");
    scanf("%d",&size);
    for (int i=0;i<=size-1;i++)
    {
      printf("\nenter element %d: ",i+1);
      scanf("%d",&arr[i]);
    }
    printf("\nenter element to search: ");
    scanf("%d",&key);
    l=binarySearch(arr,size,key);
    if (l>-1)
      printf("\nelement found at %d index",l);
    else 
      printf("\nelement not found");

    return 0;
}