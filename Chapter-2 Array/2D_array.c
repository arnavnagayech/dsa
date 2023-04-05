#include<stdio.h>
#include<stdlib.h>

int main()
{
    int A[3][4]={{1,2,3,4},{2,3,4,5},{3,4,5,6}};
    int *B[3];
    int **C;

    printf("\nfirst declaration: \n");
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<4;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }

    B[0]=(int *)malloc(4*sizeof(int));
    B[1]=(int *)malloc(4*sizeof(int));
    B[2]=(int *)malloc(4*sizeof(int));
    printf("\nsecond declaration: \n");
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<4;j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }

    C=(int **)malloc(3*sizeof(int));
    C[0]=(int *)malloc(4*sizeof(int));
    C[1]=(int *)malloc(4*sizeof(int));
    C[2]=(int *)malloc(4*sizeof(int));
    printf("\nthird declaration: \n");
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<4;j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}