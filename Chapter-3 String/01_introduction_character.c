#include<stdio.h>

int main()
{
    char temp;
    temp='A';
    // char X[5];
    // char X[5]={'A','B','C','D','E'};
    // char X[]={'A','B','C','D','E'};

    char X[5]={'A','B'};
    for (int i=0;i<5;i++)
        printf("\n%c",X[i]);

    printf("\n%c",temp);
    printf("\n%d",temp);
    return 0;
}