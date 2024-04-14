#include <stdio.h>
#include <stdlib.h>

typedef struct array
{
    int *data;
    int len;
    int capacity;
} Array;

Array *array_create(int capacity);
void array_delete(Array *a);
int array_append(Array *a, int value);
void print_array(const Array *a);

int main(void)
{
    Array *a = array_create(5);
    if (a == NULL)
    {
        return 1;
    }

    array_append(a, 1);
    array_append(a, 2);
    array_append(a, 3);
    array_append(a, 4);
    array_append(a, 5);

    print_array(a);

    array_delete(a);

    return 0;
}

int array_resize(Array *a, int new_capacity)
{
    int *data = realloc(a->data, sizeof(int) * new_capacity);
    if (data == NULL)
    {
        return 1;
    }

    a->data = data;
    a->capacity = new_capacity;

    return 0;
}

int array_append(Array *a, int value)
{
    if (a->len == a->capacity)
    {
        int err = array_resize(a, a->capacity * 2);
        if (err != 0)
        {
            return 1;
        }
    }

    a->data[a->len] = value;
    a->len++;

    return 0;
}

void print_array(const Array *a)
{
    for (int i = 0; i < a->len; i++)
    {
        printf("%d ", a->data[i]);
    }
    printf("\n");
}

Array *array_create(int capacity)
{
    Array *a = malloc(sizeof(Array));
    if (a == NULL)
    {
        return NULL;
    }

    a->data = malloc(sizeof(int) * capacity);
    if (a->data == NULL)
    {
        free(a);
        return NULL;
    }

    a->len = 0;
    a->capacity = capacity;

    return a;
}

void array_delete(Array *a)
{
    free(a->data);
    free(a);
}
