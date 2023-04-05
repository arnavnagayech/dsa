#include<stdio.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void Perm(char s[], int l, int h)
{
    if (l == h)
        printf("\n%s", s);
    else
    {
        for (int i = l; i <= h; i++) {
            swap (&s[l],&s[i]);
            Perm(s, l+1, h);
            swap (&s[l],&s[i]);
        }
    }
}

int main() {
    
    char s[] = "ABC";
    Perm(s, 0, 2);
    
    return 0;
}