#include "solution.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void add(Nodo **lista, char c)
{
    if (lista == NULL)
    {
        printf("Passare per riferimento ad ADD\n");
    }
    if (*lista == NULL)
    {
        *lista = malloc(sizeof(Nodo));
        assert(*lista != NULL);
        (*lista)->value = c;
        (*lista)->next = NULL;
    }
    else
    {
        add(&(*lista)->next, c);
    }
}

void copyReversed(Nodo *src, Nodo **copy)
{
    if (copy == NULL)
    {
        printf("Passare la lista di destinazione di copia per puntatore");
    }
    if (src == NULL)
    {
        return;
    }
    copyReversed(src->next, copy);
    add(copy, src->value);
}

int compare_lists(Nodo *list_a, Nodo *list_b)
{
    if (list_a == NULL)
    {
        if (list_b == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (list_a->value != list_b->value)
    {
        return 0;
    }
    else
    {
        return compare_lists(list_a->next, list_b->next);
    }
}

void print_list(Nodo *list)
{
    if (list == NULL)
    {
        return;
    }
    printf("%c", list->value);
    print_list(list->next);
}

int is_palindrome(Nodo *lista)
{
    if (lista == NULL)
    {
        return 0;
    }
    Nodo *inv = NULL;
    copyReversed(lista, &inv);
    int result = compare_lists(lista, inv);
    delete_list(inv);
    return result;
}

void delete_list(Nodo *list)
{
    if (list == NULL)
    {
        return;
    }
    delete_list(list->next);
    free(list);
}
