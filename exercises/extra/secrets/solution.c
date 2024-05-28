#include "solution.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * TODO: implement encodec and encodec_list functions
 */

void add(Nodo **lista, char *str)
{
    if (lista == NULL)
    {
        printf("Passare per riferimento ad ADD\n");
    }
    if (*lista == NULL)
    {
        *lista = malloc(sizeof(Nodo));
        assert(*lista != NULL);
        strcpy((*lista)->value, str);
        (*lista)->next = NULL;
    }
    else
    {
        add(&(*lista)->next, str);
    }
}

void print_list(Nodo *list)
{
    if (list == NULL)
    {
        return;
    }
    printf("%s ", list->value);
    print_list(list->next);
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

void encodec(char *msg, char *key, char *dst)
{
    for (size_t i = 0; i < strlen(msg); i++)
    {
        dst[i] = msg[i] ^ key[i % strlen(key)];
        if (!is_printable(dst[i]))
        {
            dst[i] = msg[i];
        }
    }
    dst[strlen(msg)] = '\0';
}

void encodec_list(Nodo *list, char *key)
{
    if (list == NULL)
        return;

    char tmp[sizeof(list->value)] = {0};
    encodec(list->value, key, tmp);
    strcpy(list->value, tmp);

    encodec_list(list->next, key);
}

/**
 * Verifica se un carattere è stampabile.
 *
 * Un carattere è stampabile se il suo codice ASCII è compreso tra 32 e 126.
 *
 * @param c il carattere da controllare
 * @return int 1 se il carattere è stampabile, 0 altrimenti
 */
int is_printable(char c)
{
    return c >= 32 && c <= 126;
}
