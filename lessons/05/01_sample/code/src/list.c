#include "list.h"
#include <stdlib.h>

list_t *make_list(void)
{
    list_t *list = malloc(sizeof(list_t));
    if (list == NULL)
    {
        return NULL;
    }
    list->head = NULL;
    return list;
}

static void node_destroy(node_t *node)
{
    if (node == NULL)
    {
        return;
    }
    node_destroy(node->next);
    free(node);
}

void list_destroy(list_t *list)
{
    if (list == NULL)
    {
        return;
    }
    node_destroy(list->head);
    free(list);
}

void list_append(list_t *list, T *data)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
    {
        return;
    }
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL)
    {
        list->head = new_node;
    }
    else
    {
        node_t *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

void list_prepend(list_t *list, T *data)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
    {
        return;
    }
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

void list_insert(list_t *list, T *data, size_t index)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
    {
        return;
    }
    new_node->data = data;

    if (index == 0)
    {
        new_node->next = list->head;
        list->head = new_node;
    }
    else
    {
        node_t *current = list->head;
        for (size_t i = 0; i < index - 1; i++)
        {
            if (current == NULL)
            {
                free(new_node);
                return;
            }
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void list_remove(list_t *list, size_t index)
{
    if (index == 0)
    {
        node_t *temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    else
    {
        node_t *current = list->head;
        for (size_t i = 0; i < index - 1; i++)
        {
            if (current == NULL)
            {
                return;
            }
            current = current->next;
        }
        if (current->next == NULL)
        {
            return;
        }
        node_t *temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

T *list_get(list_t *list, size_t index)
{
    node_t *current = list->head;
    for (size_t i = 0; i < index; i++)
    {
        if (current == NULL)
        {
            return NULL;
        }
        current = current->next;
    }
    return current->data;
}

size_t list_size(list_t *list)
{
    size_t size = 0;
    for (node_t *current = list->head; current != NULL; current = current->next)
    {
        size++;
    }
    return size;
}
