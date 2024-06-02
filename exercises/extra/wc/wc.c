#include <stdio.h>

typedef struct
{
    int lines;
    int words;
    int chars;
} Stats;

// 1. Implementa la funzione wc che conta il numero di righe, parole e caratteri nella stringa data e
//    memorizza il risultato nella struttura counter.
// 2. Implementa la funzione print_stats che stampa in modo carino il numero di righe, parole e caratteri nella
//    struttura counter data.

// Verifica se un carattere è uno spazio o un carattere di newline.
int is_empty(char c)
{
    return c == ' ' || c == '\n';
}

void wc(const char *str, Stats *counter)
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

void print_stats(Stats counter)
{
    printf("Lines: %d ", counter.lines);
    printf("Words: %d ", counter.words);
    printf("Chars: %d\n", counter.chars);
}

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

        printf("\tExpected: ");
        print_stats(expected);

        printf("\tGot:      ");
        print_stats(*counter);
    }
    printf("%s", RESET);
}

int main(void)
{
    Stats counter;

    test("ciao mondo\nhello world", &counter, (Stats){2, 4, 22});
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
