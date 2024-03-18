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

/**
 * @brief Create a new linked list
 *
 * @return linkedlist_t* The new list
 */
linkedlist_t *linkedlist_create();
/**
 * @brief Append a value to the list
 *
 * @param list The list to append to
 * @param value The value to append
 * @return error_t OK on success, error code on failure
 */
error_t linkedlist_append(linkedlist_t *list, T *value);
/**
 * @brief Get a value from the list.
 *
 * @note This function has O(1) time complexity
 *
 * @param list The list to get the value from
 * @param index The index of the value to get
 * @return T* The value at the index, or NULL if the index is out of bounds
 */
T *linkedlist_get(const linkedlist_t *list, size_t index);
/**
 * @brief Delete the list
 *
 * @param list The list to delete
 * @param free_data The function to free the data, or NULL if the data should not be freed
 */
void linkedlist_delete(linkedlist_t *list, void (*free_data)(T *));
error_t linkedlist_prepend(linkedlist_t *list, T *value);
error_t linkedlist_insert(linkedlist_t *list, T *value, size_t index);

#endif // LINKEDLIST_H
