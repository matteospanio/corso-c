#ifndef LIST_H
#define LIST_H

#include "arraylist.h"
#include "linkedlist.h"
#include "types.h"
#include <stdlib.h>

typedef union {
    arraylist_t *arraylist;
    linkedlist_t *linkedlist;
} list_u;

typedef enum list_enum
{
    ARRAYLIST,
    LINKEDLIST
} list_type;

typedef struct
{
    list_u list;
    list_type type;
} list_t;

error_t list_append(list_t *list, T *data);
error_t list_prepend(list_t *list, T *data);
error_t list_insert(list_t *list, T *data, size_t index);
T *list_get(const list_t *list, size_t index);
size_t list_size(const list_t *list);
void list_delete(list_t *list, void (*free_data)(T *));

#endif // LIST_H
