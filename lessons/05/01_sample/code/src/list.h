#ifndef LIST_H
#define LIST_H
#include <stdlib.h>

typedef void T;

typedef struct node
{
    T *data;
    struct node *next;
} node_t;

typedef struct list
{
    node_t *head;
} list_t;

list_t *make_list(void);
void list_destroy(list_t *list);
void list_append(list_t *list, T *data);
void list_prepend(list_t *list, T *data);
void list_insert(list_t *list, T *data, size_t index);
void list_remove(list_t *list, size_t index);
T *list_get(list_t *list, size_t index);
size_t list_size(list_t *list);

#endif // LIST_H
