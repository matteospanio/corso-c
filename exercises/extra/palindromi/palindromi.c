#include "solution.h"
#include <stdio.h>

const char *RESET = "\033[0m";
const char *RED = "\033[31m";
const char *GREEN = "\033[32m";

Nodo *list_from_string(const char *str)
{
    Nodo *list = NULL;

    for (int i = 0; i < 100; i++)
    {
        if (str[i] == '\0')
            break;
        add(&list, str[i]);
    }

    return list;
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

void test(const char *parola, int expected)
{
    Nodo *lista = list_from_string(parola);

    int res = is_palindrome(lista);

    if (res == expected)
    {
        printf("%s✔️ OK ", GREEN);
        printf("Test input: \"");
        print_raw_string(parola);
        printf("\"\n");
    }
    else
    {
        printf("%s❌ FAIL ", RED);
        printf("Test input: \"%s\"\n", parola);
    }

    delete_list(lista);
}

int main(void)
{
#ifdef DEBUG
    char parola[101];
    printf("Scrivi una parola (max 100 caratteri)\n");
    scanf("%s", parola);

    Nodo *lista = NULL;

    for (int i = 0; i < 100; i++)
    {
        if (parola[i] == '\0')
            break;
        add(&lista, parola[i]);
    }

    if (is_palindrome(lista))
        printf("La parola è palindroma\n");
    else
        printf("La parola non è palindroma\n");

    delete_list(lista);
#else
    test("anna", 1);
    test("ciao", 0);
    test("abba", 1);
    test("a", 1);
    test("\n", 1);
    test("\na", 0);
    test("ab", 0);
    test("abbaabba", 1);
    test("abbaabbaa", 0);
    test("", 0);
#endif
}
