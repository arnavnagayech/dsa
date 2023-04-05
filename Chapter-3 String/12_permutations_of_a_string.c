#include<stdio.h>

void perm(char s[],int k)
{
    static int A[10]={0};
    static char res[10];
    int i;

    if (s[k]=='\0')
    {
        res[k]='\0';
        printf("\n%s",res);
    }
    else
    {
        for (i=0;s[i]!='\0';i++)
        {
            if (A[i]==0)
            {
                res[k]=s[i];
                A[i]=1;
                perm(s,k+1);
                A[i]=0;
            }
        }
    }
}

int main()
{
    char s[]="ABC";
    perm(s,0);

    return 0;
}