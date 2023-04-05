#include<stdio.h>

int main()
{
    char A[]="decimal";
    char B[]="medical";
    int i,H[26]={0};

    for (i=0;A[i]!='\0';i++)
    {
        H[A[i]-97]++;
    }

    for (i=0;B[i]!='\0';i++)
    {
        H[A[i]-97]--;
        if (H[A[i]-97]<0)
        {
            printf("\nnot anagram");
            break;
        }
    }
    if (B[i]=='\0')
       printf("\nit is anagram");
    
    return 0;
}