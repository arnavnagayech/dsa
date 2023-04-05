#include<stdio.h>

int linearSearch(int arr[],int key)
{
   for (int i=0;i<=5;i++)
   {
       if(arr[i]==key)
          return i;
   }
   return -1;
}

int main()
{
    int arr[6],l;
    int key;
    printf("\nenter elements: ");
    for (int i=0;i<=5;i++)
      scanf("%d",&arr[i]);
    printf("\nenter element to search: ");
    scanf("%d",&key);
    l=linearSearch(arr,key);
    if (l>-1)
      printf("\nelement found at %d index",l);
    else 
      printf("\nelement not found");

    return 0;
}