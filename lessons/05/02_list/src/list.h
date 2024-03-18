#ifndef LIST_H
#define LIST_H

#include "arraylist.h"
#include "linkedlist.h"
#include "types.h"
#include <stdlib.h>

typedef union {
    arraylist_t arraylist;
    linkedlist_t linkedlist;
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

void list_append(list_t *list, T *data);
T *list_get(const list_t *list, size_t index);

#endif // LIST_H
