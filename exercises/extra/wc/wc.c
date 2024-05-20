#include "solution.h"
#include <stdio.h>

const char *RESET = "\033[0m";
const char *RED = "\033[31m";
const char *GREEN = "\033[32m";

void reset_counter(Stats *counter)
{
    counter->lines = 0;
    counter->words = 0;
    counter->chars = 0;
}

void print_raw_string(const char *str)
{
    while (*str)
    {
        if (*str == '\n')
        {
            printf("\\n");
            str++;
            if (*str)
            {
                putchar(*str);
            }
        }
        else
        {
            putchar(*str);
        }
        str++;
    }
}

int stats_equal(Stats a, Stats b)
{
    return a.lines == b.lines && a.words == b.words && a.chars == b.chars;
}

void test(const char *str, Stats *counter, Stats expected)
{
    reset_counter(counter);
    wc(str, counter);

    int res = stats_equal(*counter, expected);

    if (res)
    {
        printf("%s✔️ OK ", GREEN);
        printf("Test input: \"");
        print_raw_string(str);
        printf("\"\n");
    }
    else
    {
        printf("%s❌ FAIL ", RED);
        printf("Test input: \"");
        print_raw_string(str);
        printf("\"\n");

        printf("Expected: ");
        print_stats(expected);

        printf("Got: ");
        print_stats(*counter);
    }
    printf("%s", RESET);
}

int main(void)
{
    Stats counter;

    test("Hello, World!", &counter, (Stats){1, 2, 13});
    test("Normal test with\nmany\nlines. And_spaces", &counter, (Stats){3, 6, 39});
    test("", &counter, (Stats){0, 0, 0});
    test("simple test ", &counter, (Stats){1, 2, 12});
    test(" start with blank space", &counter, (Stats){1, 4, 23});
    test("  stringa", &counter, (Stats){1, 1, 9});
    test(" \nstringa", &counter, (Stats){2, 1, 9});
    test("\n stringa", &counter, (Stats){2, 1, 9});
    test(" stringa ", &counter, (Stats){1, 1, 9});
    test("\nstringa ", &counter, (Stats){2, 1, 9});
    test("    ", &counter, (Stats){1, 0, 4});
    test("  \n  ", &counter, (Stats){2, 0, 5});
}
