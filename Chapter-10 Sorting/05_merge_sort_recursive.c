#include<stdio.h>

void merge(int *A, int low, int mid, int high)
{
	
	int temp[high - low + 1];
    
	int i = low, j = mid+1, k = 0;

	while(i <= mid && j <= high)
    {
		if(A[i] <= A[j])
        {
			temp[k++] = A[i++];
		}
		else 
			temp[k++] = A[j++];
	}

	while(i <= mid)
    {
		temp[k++] = A[i++];
	}

	while(j <= high)
    {
		temp[k++] = A[j++];
	}

	for(i = low; i <= high; i += 1) 
		A[i] = temp[i - low] ;
	
}

void recursiveMergeSort (int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low+high)/2;
        recursiveMergeSort(A, low, mid);
        recursiveMergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}

int main()
{
    int A[]={1,5,9,2,4,8,7,6,3,10},n=10;
    recursiveMergeSort(A,0,n-1);
    printf("\nAfter Sorting:\n");
    for (int i=0;i<10;i++)
        printf("%d ",A[i]);
    
    printf("\n\n");
    return 0;
}
