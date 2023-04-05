#include<stdio.h>

int main()
{
    char A[]="How are   u";
    int word=1;

    for (int i=0;A[i]!='\0';i++)
    {
        if (A[i]==' ' && A[i-1]!=' ')
        {
            word++;
        }
    }
    printf("\nnumber of words: %d",word);

    return 0;
}