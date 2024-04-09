#include "list.h"
#include <stdio.h>
#include <string.h>

string error_message(Error error)
{
    switch (error)
    {
    case OK:
        return "No error";
    case MALLOC_ERROR:
        return "Memory allocation error";
    case REALLOC_ERROR:
        return "Memory reallocation error";
    case INDEX_ERROR:
        return "Index out of range";
    case UNKNOWN_ERROR:
        return "Unknown error";
    }
    return "Invalid error code";
}

void print_list(const List *list)
{
    for (size_t i = 0; i < list_size(list); i++)
    {
        T *result = list_get(list, i);
        if (result == NULL)
        {
            fprintf(stderr, "Error: %s\n", error_message(INDEX_ERROR));
            return;
        }
        printf("%s ", (string)result);
    }
    printf("\n");
}

int main(void)
{
    Error error;

    ArrayList *arraylist = arraylist_create(5);
    if (arraylist == NULL)
    {
        fprintf(stderr, "Error: %s\n", error_message(MALLOC_ERROR));
        exit(EXIT_FAILURE);
    }

    List list = {.list.arraylist = arraylist, .type = ARRAYLIST};

    string buffer = malloc(sizeof(char) * 6);
    if (buffer == NULL)
    {
        list_delete(&list, free);
        exit(EXIT_FAILURE);
    }
    strcpy(buffer, "Hello");
    error = list_append(&list, buffer);
    if (error != OK)
    {
        list_delete(&list, free);
        free(buffer);
        exit(EXIT_FAILURE);
    }

    buffer = malloc(sizeof(char) * 6);
    if (buffer == NULL)
    {
        list_delete(&list, free);
        exit(EXIT_FAILURE);
    }
    strcpy(buffer, "World");
    error = list_append(&list, buffer);
    if (error != OK)
    {
        list_delete(&list, free);
        free(buffer);
        exit(EXIT_FAILURE);
    }

    print_list(&list);
    list_delete(&list, free);

    exit(EXIT_SUCCESS);
}
