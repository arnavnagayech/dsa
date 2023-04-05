#include<stdio.h>

int main()
{
    char name[10]={'j','o','h','n','\0'};
    char name1[10]={'j','o','h','n','\0'};
    char name2[]="john";
    char *name3="john";
    char name4[10];
    char name5[10];

    printf("%s\n",name); //display
    printf("%s\n",name1);
    printf("%s\n",name2);
    printf("%s\n",name3);

    //singke string input
    // scanf("%s",&name4);
    // printf("\n%s",name4);

    //singke string input
    gets(name5);
    puts(name5);

    

    return 0;
}