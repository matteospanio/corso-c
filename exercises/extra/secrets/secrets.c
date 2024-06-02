#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char value;
    struct node *next;
} Node;

// Verifica se un carattere è stampabile.
int isPrintable(const char c)
{
    return c >= 32 && c <= 126;
}

// Calcola la lunghezza di una stringa.
int len(const char *str)
{
    unsigned int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

// Stampa la lista di caratteri.
// Può essere utile per il debug del codice.
// Se necessario si può modificare la funzione.
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

char charEncodec(const char c, const char key)
{
    // TODO
}

void listEncodec(Node *list, const char *key, const int seed)
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

typedef enum result
{
    OK,
    FAIL
} result_t;

static const char *TEST1 = "'AyRGo rVlaKTQnWGe]j_y thVTSrZsi@Z ^ &s[lUiThRqrYl_ia]t";
static const char *TEST2 = "zGhRvUS]evVr lVtR^y sPho\\lYnTGi]tUrUerVTGiGhR^y eWucRtYo]IR-T}aAkRgwQi]";
static const char *TEST4 = "&Ay t\\GrVlQx anWTUnYoy tXe crZsYs.G_ 5Ch_eiTh 1Ail_iQnG";
static const char *EXPECTED_TEST1 = "Try to relax and enjoy the crisis. - Ashleigh Brilliant";
static const char *EXPECTED_TEST2 = "I have never let my schooling interfere with my education. - Mark Twain";
static const char *RESET = "\033[0m";
static const char *RED = "\033[31m";
static const char *GREEN = "\033[32m";

static void add(Node **lista, const char info);
static void delete_list(Node *list);
static char *list2string(Node *list);
static Node *string2list(const char *string);
static unsigned int test(const char *str, const char *expected, const char *key, const int seed);
static bool all_tests_passed(result_t *res, const int size);

int main(void)
{
    const char *key = "s3gr3t0";

    result_t res[4];

    res[0] = test(TEST1, EXPECTED_TEST1, key, 0);
    res[1] = test(TEST2, EXPECTED_TEST2, key, 1);
    res[2] = test(TEST4, EXPECTED_TEST1, key, 3);
    res[3] = test("", "", key, 2);

    if (all_tests_passed(res, 4))
    {
        printf("%sAll tests passed! 🎉%s\n", GREEN, RESET);
    }
    else
    {
        printf("%sSome tests failed! 😞%s\n", RED, RESET);
    }
}

static bool all_tests_passed(result_t *res, const int size)
{
    for (int i = 0; i < size; i++)
    {
        if (res[i] == FAIL)
        {
            return false;
        }
    }
    return true;
}

static result_t test(const char *input, const char *expected, const char *key, const int seed)
{
    Node *msg = string2list(input);
    listEncodec(msg, key, seed);

    char *out = list2string(msg);
    int res = strcmp(out, expected);

    if (res == 0)
    {
        printf("%s✔️ OK\n", GREEN);
        printf("\tsecret: \"%s\"\n", input);
        printf("\toutput: \"%s\"\n", expected);
    }
    else
    {
        printf("%s❌ FAIL\n", RED);
        printf("Test input: \"%s\"\n", input);
        printf("\tExpected: \"%s\"\n", expected);
        printf("\tGot:      \"%s\"\n", out);
    }
    printf("%s", RESET);

    delete_list(msg);
    free(out);

    return res == 0 ? OK : FAIL;
}

static void add(Node **lista, const char info)
{
    if (lista == NULL)
    {
        printf("Passare per riferimento ad ADD\n");
    }
    if (*lista == NULL)
    {
        *lista = malloc(sizeof(Node));
        assert(*lista != NULL);
        (*lista)->value = info;
        (*lista)->next = NULL;
    }
    else
    {
        add(&(*lista)->next, info);
    }
}

static void delete_list(Node *list)
{
    if (list == NULL)
    {
        return;
    }
    delete_list(list->next);
    free(list);
}

static Node *string2list(const char *string)
{
    Node *enc_msg = NULL;
    for (int i = 0; i < len(string); i++)
    {
        add(&enc_msg, string[i]);
    }
    return enc_msg;
}

static char *list2string(Node *list)
{
    char *result = calloc(128, sizeof(char));
    assert(result != NULL);

    Node *current = list;
    int i = 0;

    while (current != NULL)
    {
        result[i++] = current->value;
        current = current->next;
    }

    return result;
}
