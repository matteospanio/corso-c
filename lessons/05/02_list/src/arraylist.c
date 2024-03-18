#include "arraylist.h"
#include "types.h"
#include <stdlib.h>

arraylist_t *arraylist_create(size_t capacity)
{
    arraylist_t *list = malloc(sizeof(arraylist_t));
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
 * @return error_t OK on success, error code on failure
 */
static inline error_t arraylist_resize(arraylist_t *list, float factor)
{
    list->capacity *= factor;
    list->data = realloc(list->data, list->capacity * sizeof(T *));
    if (list->data == NULL)
    {
        return REALLOC_ERROR;
    }
    return OK;
}

error_t arraylist_append(arraylist_t *list, T *value)
{
    error_t res = OK;
    if (list->size == list->capacity)
    {
        res = arraylist_resize(list, 2);
    }

    int i = list->size++;
    list->data[i] = value;
    return res;
}

T *arraylist_get(const arraylist_t *list, size_t index)
{
    if (index >= list->size)
    {
        return NULL;
    }
    return list->data[index];
}

void arraylist_delete(arraylist_t *list, void (*free_data)(T *))
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
