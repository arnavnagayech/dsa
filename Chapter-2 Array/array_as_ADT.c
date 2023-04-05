#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};
void createArray(struct myArray *marks,int total_size,int used_size )
{
    marks->total_size=total_size;
    marks->used_size=used_size;
    marks->ptr=(int*)malloc(total_size*sizeof(int));
}

void setVal(struct myArray *marks)
{
    int n;
    for(int i=0;i<marks->used_size;i++)
    {
        printf("\nenter element %d: ",i);
        scanf("\n%d",&n);
        (marks->ptr)[i]=n;
    }
}

void show(struct myArray *marks)
{
    for(int i=0;i<marks->used_size;i++)
       printf("\n%d",(marks->ptr)[i]);
}

int main()
{
    struct myArray marks;
    createArray(&marks,10,2);
    printf("\nwe are running setval()");
    setVal(&marks);
     printf("\nwe are running show()");
     show(&marks);

    return 0;
}