#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "types.h"
#include <stdlib.h>

typedef struct arraylist
{
    T **data;
    size_t size;
    size_t capacity;
} arraylist_t;

arraylist_t *arraylist_create(size_t capacity);
void arraylist_append(arraylist_t *list, T *value);
T *arraylist_get(const arraylist_t *list, size_t index);

#endif // ARRAYLIST_H
