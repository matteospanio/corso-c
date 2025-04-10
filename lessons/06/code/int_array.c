#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

typedef struct intarray
{
    int array[MAX];
    int length;
} IntArray;

int get(IntArray a, int index);
int insert(IntArray *a, int index, int value);
int remove(IntArray *a, int index);
void stampa_array(IntArray a);
int append(IntArray *a, int value);

int main(void)
{
    IntArray a;
    int err;
    a.length = 0;

    err = append(&a, 1);
    if (err)
    {
        exit(EXIT_FAILURE);
    }
    err = append(&a, 2);
    if (err)
    {
        exit(EXIT_FAILURE);
    }
    err = append(&a, 3);
    if (err)
    {
        exit(EXIT_FAILURE);
    }
    err = append(&a, 4);
    if (err)
    {
        exit(EXIT_FAILURE);
    }
    err = append(&a, 5);
    if (err)
    {
        exit(EXIT_FAILURE);
    }

    printf("Array: ");
    stampa_array(a);

    printf("Element at index 2: %d\n", get(a, 2));

    err = insert(&a, 2, 10);
    if (err)
    {
        exit(EXIT_FAILURE);
    }
    printf("After inserting 10 at index 2: ");
    stampa_array(a);

    err = remove(&a, 3);
    if (err)
    {
        exit(EXIT_FAILURE);
    }
    printf("After removing element at index 3: ");
    stampa_array(a);

    return 0;
}

void stampa_array(IntArray a)
{
    for (int i = 0; i < a.length; i++)
    {
        printf("%d ", a.array[i]);
    }
    printf("\n");
}

int append(IntArray *a, int value)
{
    if (a->length < MAX)
    {
        a->array[a->length] = value;
        a->length++;
        return 0;
    }
    return 1;
}

/**
 * Restituisce l'elemento in posizione index
 */
int get(IntArray a, int index)
{
    // TODO
}

/**
 * Inserisce l'elemento value in posizione index
 * Restituisce 0 in caso di successo, 1 in caso di errore
 */
int insert(IntArray *a, int index, int value)
{
    // TODO
    return 1;
}

/**
 * Rimuove l'elemento in posizione index
 * Restituisce 0 in caso di successo, 1 in caso di errore
 */
int remove(IntArray *a, int index)
{
    // TODO
    return 1;
}
