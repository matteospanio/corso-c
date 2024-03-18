#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "types.h"
#include <stdlib.h>

typedef struct node
{
    T *data;
    struct node *next;
} node_t;

typedef struct linkedlist
{
    node_t *head;
    node_t *tail;
    size_t size;
} linkedlist_t;

void linkedlist_append(linkedlist_t *list, T *value);
T *linkedlist_get(const linkedlist_t *list, size_t index);

#endif // LINKEDLIST_H
