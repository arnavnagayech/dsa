#include <stdio.h>

void duplicate(char *s)
{
   long int H = 0;
    
    for (int i = 0; s[i] != '\0'; i++)
    {
        long int x = 1;
        
        x = x << (s[i] - 97); 
        if (H & x) // if H AND x is greater than 0.
            printf("%c is a duplicate\n",s[i]);
        // Else, Merge
        else
            H = H | x;
    }
}

int main() {

    char s[] = "finding";
    duplicate(s);
    
    return 0;
}