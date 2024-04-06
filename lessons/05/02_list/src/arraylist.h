#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "types.h"
#include <stdlib.h>

typedef struct arraylist
{
    T **data;
    size_t size;
    size_t capacity;
} ArrayList;

/**
 * @brief Create a new arraylist
 *
 * @param capacity The initial capacity of the list
 * @return ArrayList* The new list or NULL if the list could not be created
 */
ArrayList *arraylist_create(size_t capacity);
/**
 * @brief Append a value to the list
 *
 * @note This function has O(1) time complexity
 *
 * @param list The list to append to
 * @param value The value to append
 * @return Error OK on success, error code on failure
 */
Error arraylist_append(ArrayList *list, T *value);
/**
 * @brief Get a value from the list
 *
 * @note This function has O(1) time complexity
 *
 * @param list The list to get the value from
 * @param index The index of the value to get
 * @return T* The value at the index, or NULL if the index is out of bounds
 */
T *arraylist_get(const ArrayList *list, size_t index);
/**
 * @brief Delete the list
 *
 * @param list The list to delete
 * @param free_data The function to free the data, or NULL if the data should not be freed
 */
void arraylist_delete(ArrayList *list, void (*free_data)(T *));
/**
 * @brief Prepend a value to the list
 *
 * @param list The list to prepend to
 * @param value The value to prepend
 * @return Error OK on success, error code on failure
 */
Error arraylist_prepend(ArrayList *list, T *value);
/**
 * @brief Insert a value into the list
 *
 * @param list The list to insert into
 * @param value The value to insert
 * @param index The index to insert the value at
 * @return Error OK on success, error code on failure
 */
Error arraylist_insert(ArrayList *list, T *value, size_t index);

#endif // ARRAYLIST_H
