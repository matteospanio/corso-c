#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "types.h"
#include <stdlib.h>

typedef struct node
{
    T *data;
    struct node *next;
} Node;

typedef struct linkedlist
{
    Node *head;
    Node *tail;
    size_t size;
} LinkedList;

/**
 * @brief Create a new linked list
 *
 * @return LinkedList* The new list or NULL if the list could not be created
 */
LinkedList *linkedlist_create();
/**
 * @brief Append a value to the list
 *
 * @note This function has O(1) time complexity
 *
 * @param list The list to append to
 * @param value The value to append
 * @return Error OK on success, error code on failure
 */
Error linkedlist_append(LinkedList *list, T *value);
/**
 * @brief Get a value from the list.
 *
 * @note This function has O(n) time complexity
 *
 * @param list The list to get the value from
 * @param index The index of the value to get
 * @return T* The value at the index, or NULL if the index is out of bounds
 */
T *linkedlist_get(const LinkedList *list, size_t index);
/**
 * @brief Delete the list
 *
 * @param list The list to delete
 * @param free_data The function to free the data, or NULL if the data should not be freed
 */
void linkedlist_delete(LinkedList *list, void (*free_data)(T *));
/**
 * @brief Prepend a value to the list
 *
 * @param list The list to prepend to
 * @param value The value to prepend
 * @return Error OK on success, error code on failure
 */
Error linkedlist_prepend(LinkedList *list, T *value);
/**
 * @brief Insert a value into the list
 *
 * @param list The list to insert into
 * @param value The value to insert
 * @param index The index to insert the value at
 * @return Error OK on success, error code on failure
 */
Error linkedlist_insert(LinkedList *list, T *value, size_t index);

#endif // LINKEDLIST_H
