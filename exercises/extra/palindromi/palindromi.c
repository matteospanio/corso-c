#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    char value;
    struct nodo *next;
} Nodo;

void printList(Nodo *list)
{
    if (list == NULL)
    {
        return;
    }
    printf("%c", list->value);
    printList(list->next);
}

void deleteList(Nodo *list)
{
    if (list == NULL)
    {
        return;
    }
    deleteList(list->next);
    free(list);
}

void add(Nodo **lista, char c)
{
    if (lista == NULL)
    {
        printf("Passare per riferimento ad ADD\n");
    }
    // TODO
}

void copyReversed(Nodo *lis, Nodo **copy)
{
    if (copy == NULL)
    {
        printf("Passare la lista di destinazione di copia per puntatore");
    }
    // TODO
}

int compareLists(Nodo *lis, Nodo *comp)
{
    // TODO
}

int checkPalindrome(Nodo *lista)
{
    // TODO
}

/**
 * NON MODIFICARE IL CODICE CHE SEGUE!!!
 *
 * Il codice che segue è stato scritto per testare le funzioni implementate per l'esercizio.
 * L'esercitazione consiste solamente nell'implementare le funzioni richieste nel testo.
 * Per l'implementazione di una corretta soluzione non è richiesto agli studenti di
 * comprendere il funzionamento del codice seguente.
 */

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

    int res = checkPalindrome(lista);

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

    deleteList(lista);
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

    if (checkPalindrome(lista))
        printf("La parola è palindroma\n");
    else
        printf("La parola non è palindroma\n");

    deleteList(lista);
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
