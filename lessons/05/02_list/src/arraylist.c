#include "arraylist.h"
#include "types.h"
#include <stdlib.h>

arraylist_t *arraylist_create(size_t capacity)
{
    arraylist_t *list = malloc(sizeof(arraylist_t));
    list->size = 0;
    list->capacity = capacity;
    list->data = malloc(list->capacity * sizeof(T *));
    return list;
}

/**
 * @brief Doubles the capacity of the list
 *
 * @param list The list to resize
 */
static void arraylist_resize(arraylist_t *list)
{
    list->capacity *= 2;
    list->data = realloc(list->data, list->capacity * sizeof(T *));
}

void arraylist_append(arraylist_t *list, T *value)
{
    if (list->size == list->capacity)
    {
        arraylist_resize(list);
    }
    int i = list->size++;
    list->data[i] = value;
}

T *arraylist_get(const arraylist_t *list, size_t index)
{
    if (index >= list->size)
    {
        return NULL;
    }
    return list->data[index];
}
