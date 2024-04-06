#include "list.h"

Error list_append(List *list, T *value)
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

T *list_get(const List *list, size_t index)
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

void list_delete(List *list, void (*free_data)(T *))
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

size_t list_size(const List *list)
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

Error list_prepend(List *list, T *value)
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

Error list_insert(List *list, T *value, size_t index)
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
