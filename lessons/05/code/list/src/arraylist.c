#include "arraylist.h"
#include "types.h"
#include <stdlib.h>

ArrayList *arraylist_create(size_t capacity)
{
    ArrayList *list = malloc(sizeof(ArrayList));
    if (list == NULL)
    {
        return NULL;
    }
    list->size = 0;
    list->capacity = capacity;
    list->data = malloc(list->capacity * sizeof(T *));
    if (list->data == NULL)
    {
        free(list);
        return NULL;
    }
    return list;
}

/**
 * @brief Resize the capacity of the list by a factor
 *
 * @param list The list to resize
 * @param factor The factor to resize the list by
 * @return Error OK on success, error code on failure
 */
static inline Error arraylist_resize(ArrayList *list, float factor)
{
    list->capacity *= factor;
    list->data = realloc(list->data, list->capacity * sizeof(T *));
    if (list->data == NULL)
    {
        return REALLOC_ERROR;
    }
    return OK;
}

Error arraylist_append(ArrayList *list, T *value)
{
    Error res = OK;
    if (list->size == list->capacity)
    {
        res = arraylist_resize(list, 2);
    }

    int i = list->size++;
    list->data[i] = value;
    return res;
}

T *arraylist_get(const ArrayList *list, size_t index)
{
    if (index >= list->size)
    {
        return NULL;
    }
    return list->data[index];
}

void arraylist_delete(ArrayList *list, void (*free_data)(T *))
{
    if (free_data != NULL)
    {
        for (size_t i = 0; i < list->size; i++)
        {
            free_data(list->data[i]);
        }
    }
    free(list->data);
    free(list);
}
