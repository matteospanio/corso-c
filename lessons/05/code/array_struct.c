#include <stdio.h>
#define MAX_LEN 100

typedef struct array
{
    int data[MAX_LEN];
    int len;
} Array;

void print_array(Array a);
int append(Array *a, int value);

int main(void)
{
    Array a = {.data = {1, 2, 3, 4, 5}, .len = 5};

    append(&a, 6);
    append(&a, 118);

    print_array(a);
}

int append(Array *a, int value)
{
    if (a->len < MAX_LEN)
    {
        a->data[a->len] = value;
        a->len++;
        return 0;
    }
    return 1;
}

void print_array(Array a)
{
    for (int i = 0; i < a.len; i++)
    {
        printf("%d ", a.data[i]);
    }
    printf("\n");
}
