#include "linkedlist.h"

LinkedList *linkedlist_create()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

Error linkedlist_append(LinkedList *list, T *value)
{
    Node *node = malloc(sizeof(Node));
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

T *linkedlist_get(const LinkedList *list, size_t index)
{
    Node *node = list->head;
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

void linkedlist_delete(LinkedList *list, void (*free_data)(T *))
{
    Node *node = list->head;
    while (node != NULL)
    {
        Node *next = node->next;
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
