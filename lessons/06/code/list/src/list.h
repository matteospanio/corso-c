#ifndef LIST_H
#define LIST_H

#include "arraylist.h"
#include "linkedlist.h"
#include "types.h"
#include <stdlib.h>

typedef union {
    ArrayList *arraylist;
    LinkedList *linkedlist;
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
} List;

Error list_append(List *list, T *data);
Error list_prepend(List *list, T *data);
Error list_insert(List *list, T *data, size_t index);
T *list_get(const List *list, size_t index);
size_t list_size(const List *list);
void list_delete(List *list, void (*free_data)(T *));

#endif // LIST_H
