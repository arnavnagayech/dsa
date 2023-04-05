#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	int p[n] , s[n] , flag , temp;
    for (int i = 0; i < n; i++)
    {
        p[i]=(tr[i].a+tr[i].b+tr[i].c)/2;
        s[i]=(p[i]*(p[i]-tr[i].a)*(p[i]-tr[i].b)*(p[i]-tr[i].c);
    }
    for (int i = 0; i < n-1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j] > s[j + 1])
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;

                temp=tr[j].a;
                tr[j].a=tr[j+1].a;
                tr[j+1].a=temp;

                temp=tr[j].b;
                tr[j].b=tr[j+1].b;
                tr[j+1].b=temp;

                temp=tr[j].c;
                tr[j].c=tr[j+1].c;
                tr[j+1].c=temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}