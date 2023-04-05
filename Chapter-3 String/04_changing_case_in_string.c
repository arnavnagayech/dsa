#include<stdio.h>

int main()
{
    char A[]="WELCOME";
    char B[]="WeLcOMe";
    
    //if only upper case is present
    for (int i=0;A[i]!='\0';i++)
    {
        A[i]=A[i]+32;
    }
    printf("\n%s",A);

    //if both upper & lower cases are present
    for (int i=0;B[i]!='\0';i++)
    {
        if (B[i]>=65 && B[i]<=90)
            B[i]=B[i]+32;
        else if (B[i]>=97 && B[i]<=122)
            B[i]=B[i]-32;
    }
    printf("\n%s",B);

    return 0;
}