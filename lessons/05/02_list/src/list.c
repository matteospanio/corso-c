#include "list.h"

error_t list_append(list_t *list, T *value)
{
    switch (list->type)
    {
    case ARRAYLIST:
        return arraylist_append(list->list.arraylist, value);
    case LINKEDLIST:
        return linkedlist_append(list->list.linkedlist, value);
    }
    return UNKNOWN_ERROR;
}

T *list_get(const list_t *list, size_t index)
{
    switch (list->type)
    {
    case ARRAYLIST:
        return arraylist_get(list->list.arraylist, index);
    case LINKEDLIST:
        return linkedlist_get(list->list.linkedlist, index);
    }
    return NULL;
}

void list_delete(list_t *list, void (*free_data)(T *))
{
    switch (list->type)
    {
    case ARRAYLIST:
        arraylist_delete(list->list.arraylist, free_data);
        break;
    case LINKEDLIST:
        linkedlist_delete(list->list.linkedlist, free_data);
        break;
    }
}

size_t list_size(const list_t *list)
{
    switch (list->type)
    {
    case ARRAYLIST:
        return list->list.arraylist->size;
    case LINKEDLIST:
        return list->list.linkedlist->size;
    }
    return 0;
}

error_t list_prepend(list_t *list, T *value)
{
    switch (list->type)
    {
    case ARRAYLIST:
        return arraylist_prepend(list->list.arraylist, value);
    case LINKEDLIST:
        return linkedlist_prepend(list->list.linkedlist, value);
    }
    return UNKNOWN_ERROR;
}

error_t list_insert(list_t *list, T *value, size_t index)
{
    switch (list->type)
    {
    case ARRAYLIST:
        return arraylist_insert(list->list.arraylist, value, index);
    case LINKEDLIST:
        return linkedlist_insert(list->list.linkedlist, value, index);
    }
    return UNKNOWN_ERROR;
}
