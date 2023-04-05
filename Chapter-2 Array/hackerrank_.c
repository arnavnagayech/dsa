#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') 
    { 
        exit(EXIT_FAILURE); 
    }
    else 
    {
            if (*n_endptr==1)
            printf("one\n");
            // if (*n_str==2)
            // printf("two\n");
            // if (*n_str==3)
            // printf("three\n");
            // if (*n_str==4)
            // printf("four\n");
            // if (*n_str==5)
            // printf("five\n");
            // if (*n_str==6)
            // printf("six\n");
            // if (*n_str==7)
            // printf("seven\n");
            // if (*n_str==8)
            // printf("eight\n");
            // if (*n_str==9)
            // printf("nine\n");
            // if (*n_str>9)
            //    printf("greater than 9");
        }
    
    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}