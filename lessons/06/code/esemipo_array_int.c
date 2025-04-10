#include <stdio.h>
#include <stdlib.h>

typedef struct intarray
{
    int *array;
    int capacity;
    int size;
} IntArray;

int new_array(IntArray *arr, int capacity);
void free_array(IntArray *arr);

int main(void)
{
    int *a;
    a = malloc(sizeof(int) * 10);
    free(a);
    a = NULL;
    a = calloc(sizeof(int), 10);
    if (a == NULL)
        exit(EXIT_FAILURE);

    a[0] = 1;
    a[5] = 2;

    printf("%d\n", a[1]);

    free(a);
    a = NULL;

    IntArray arr;
    int error;
    error = new_array(&arr, 10);

    if (error)
        exit(EXIT_FAILURE);
    arr.array[arr.size++] = 1;
    free_array(&arr);
}

int new_array(IntArray *arr, int capacity)
{
    arr->size = 0;
    arr->capacity = capacity;
    arr->array = calloc(sizeof(int), capacity);
    if (arr->array == NULL)
        return 1;
    return 0;
}

void free_array(IntArray *arr)
{
    free(arr->array);
    arr->array = NULL;
    arr->size = 0;
    arr->capacity = 0;
}
