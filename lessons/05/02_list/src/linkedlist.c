#include "linkedlist.h"

linkedlist_t *linkedlist_create()
{
    linkedlist_t *list = malloc(sizeof(linkedlist_t));
    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

error_t linkedlist_append(linkedlist_t *list, T *value)
{
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL)
        return MALLOC_ERROR;

    node->data = value;
    node->next = NULL;
    if (list->head == NULL)
    {
        list->head = node;
    }
    else
    {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;

    return OK;
}

T *linkedlist_get(const linkedlist_t *list, size_t index)
{
    node_t *node = list->head;
    if (index >= list->size)
        return NULL;

    for (size_t i = 0; i < index; i++)
    {
        if (node == NULL)
            return NULL;

        node = node->next;
    }
    return node->data;
}

void linkedlist_delete(linkedlist_t *list, void (*free_data)(T *))
{
    node_t *node = list->head;
    while (node != NULL)
    {
        node_t *next = node->next;
        if (free_data != NULL)
            free_data(node->data);
        free(node);
        node = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    free(list);
}
