#include "solution.h"
#include <stdio.h>
#include <string.h>
#define SECRET "?R vZta è u] bZsc\\tDo, mR sV pZovV sZ sPioTlYe!"

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

Nodo *setup()
{
    Nodo *enc_msg = NULL;
    char str[sizeof(SECRET)];
    strcpy(str, SECRET);

    char *token = strtok(str, " ");
    while (token != NULL)
    {
        // char dst[sizeof(token)];
        // encodec(token, "s3gr3t0", dst);
        add(&enc_msg, token);

        token = strtok(NULL, " ");
    }

    return enc_msg;
}

int main(void)
{
    Nodo *enc_msg = setup();

    printf("Encoded message:\n");
    print_list(enc_msg);
    printf("\n");

    encodec_list(enc_msg, "s3gr3t0");

    printf("Decoded message:\n");
    print_list(enc_msg);
    printf("\n");
    delete_list(enc_msg);
}
