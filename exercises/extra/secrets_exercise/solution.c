#include "solution.h"
#include <stdio.h>
#include <stdlib.h>

char charEncodec(const char c, const char key)
{
    char result = c ^ key;
    if (!isPrintable(result))
        result = c;
    return result;
}

void listEncodec(Node *list, const char *key, const int seed)
{
    if (list == NULL)
        return;
    list->value = charEncodec(list->value, key[seed % len(key)]);
    listEncodec(list->next, key, seed + 1);
}

void printMessage(const Node *list)
{
    if (list == NULL)
    {
        printf("\n");
        return;
    }
    printf("%c", list->value);
    printMessage(list->next);
}

int isPrintable(const char c)
{
    return c >= 32 && c <= 126;
}

unsigned int len(const char *str)
{
    unsigned int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
