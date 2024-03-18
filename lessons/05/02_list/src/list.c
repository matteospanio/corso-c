#include "list.h"

void list_append(list_t *list, T *value)
{
    switch (list->type)
    {
    case ARRAYLIST:
        arraylist_append(&list->list.arraylist, value);
        break;
    case LINKEDLIST:
        linkedlist_append(&list->list.linkedlist, value);
        break;
    }
}

T *list_get(const list_t *list, size_t index)
{
    switch (list->type)
    {
    case ARRAYLIST:
        return arraylist_get(&list->list.arraylist, index);
    case LINKEDLIST:
        return linkedlist_get(&list->list.linkedlist, index);
    }
    return NULL;
}
