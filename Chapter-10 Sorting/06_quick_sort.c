#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;   
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int A[], int low, int high)
{
    int j;
    if (low < high)
    {
        j = partition(A, low, high);
        quickSort(A, low, j);
        quickSort(A, j+1, high);
    }
}

int main()
{
    int A[] = {3,7,9,10,6,5,12,4,11,2,TMP_MAX}, n = 11; //INT32_MAX will act as infinity
    quickSort(A, 0, n-1);
    
    for (int i = 0; i < n-1; i++)
        printf("%d ", A[i]);
    printf("\n\n");
    
    return 0;
}
