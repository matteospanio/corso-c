#include "linkedlist.h"

void linkedlist_append(linkedlist_t *list, T *value)
{
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL)
    {
        return;
    }
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
}

T *linkedlist_get(const linkedlist_t *list, size_t index)
{
    node_t *node = list->head;
    for (size_t i = 0; i < index; i++)
    {
        if (node == NULL)
        {
            return NULL;
        }
        node = node->next;
    }
    return node->data;
}
