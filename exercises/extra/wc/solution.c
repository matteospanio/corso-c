#include "solution.h"
#include <stdio.h>

int is_empty(char c)
{
    return c == ' ' || c == '\n';
}

void wc(const char *str, Stats *counter)
{
    if (*str == '\0')
    {
        return;
    }

    char prev = ' ';

    counter->lines++;

    while (*str != '\0')
    {
        counter->chars++;
        if (*str == '\n')
        {
            counter->lines++;
        }
        if (is_empty(*str) && !is_empty(prev))
        {
            counter->words++;
        }
        prev = *str;
        str++;
    }

    // alternativa
    // for (char c = *str; c != '\0'; c = *(str++))
    // {
    //     counter->chars++;
    //     if (c == '\n') {
    //         counter->lines++;
    //     }
    //     if (is_empty(c) && !is_empty(prev)) {
    //         counter->words++;
    //     }
    //     prev = c;
    // }

    if (!is_empty(prev))
    {
        counter->words++;
    }
}

void print_stats(Stats counter)
{
    printf("Lines: %d ", counter.lines);
    printf("Words: %d ", counter.words);
    printf("Chars: %d\n", counter.chars);
}
