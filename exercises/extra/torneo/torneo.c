#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Implementare la funzione `get_scores` che riceve in input un albero binario di partite
 * e un array di double `scores` di dimensione `NUM_TEAMS` (16) e ne calcola i punteggi.
 * L'albero binario rappresenta un torneo a eliminazione diretta, in cui ogni nodo rappresenta
 * una partita e contiene le seguenti informazioni:
 * - `team_id`: l'identificativo della squadra
 * - `score`: il punteggio della squadra
 * - `opponent_score`: il punteggio dell'avversario
 *
 * La funzione deve calcolare i punteggi delle squadre partendo dalla radice dell'albero
 * e assegnare il punteggio della squadra vincente al suo identificativo nell'array `scores`.
 *
 * Esempio:
 *
 * 1. Se l'albero binario è il seguente:
 *
 *         11, 26 - 24
 *        /           \
 *     6, 25 - 22   11, 25 - 21
 *     /       \     /       \
 *  3, 40 - 38  6, 25 - 20  0, 25 - 21
 *
 * e l'array `scores` è inizializzato a 0, la funzione deve assegnare i seguenti punteggi:
 *
 * scores[0] = 0
 * scores[1] = 0
 * scores[2] = 0
 * scores[3] = 6
 * scores[4] = 2.8
 * scores[5] = 0
 * scores[6] = 16.2
 * scores[7] = 8.4
 * scores[8] = 0
 * scores[9] = 0
 * scores[10] = 2.8
 * scores[11] = 23
 * scores[12] = 0
 * scores[13] = 0
 * scores[14] = 0
 * scores[15] = 2.8
 */

typedef struct node
{
    int team_id;
    int score;
    int opponent_score;
    struct node *left;
    struct node *right;
} Node;

void get_scores(Node *root, double *scores, double multiplier)
{
    if (root == NULL)
        return;

    scores[root->team_id] += (root->score - root->opponent_score) * multiplier;

    get_scores(root->left, scores, multiplier - 0.2);
    get_scores(root->right, scores, multiplier - 0.2);
}

int get_winner(double *scores)
{
    int winner = 0;
    for (int i = 1; i < 16; i++)
        if (scores[i] > scores[winner])
            winner = i;
    return winner;
}

/**
 * NON MODIFICARE IL CODICE CHE SEGUE
 * Il codice che segue è stato scritto per testare le funzioni implementate per l'esercizio.
 * L'esercitazione consiste solamente nell'implementare le funzioni richieste nel testo,
 * per l'implementazione di una corretta soluzione non è richiesto agli studenti di
 * comprendere il funzionamento del codice seguente.
 */

typedef enum result
{
    OK,
    FAIL
} result_t;

typedef struct game
{
    int team_id;
    int score;
    int opponent_score;
} game_t;

#define TOLERANCE 1e-6

static const char *RESET = "\033[0m";
static const char *BOLD = "\033[1m";
static const char *ITALIC = "\033[3m";
static const char *LIGHT_BLUE = "\033[94m";
static const char *RED = "\033[31m";
static const char *GREEN = "\033[32m";
static const char *GRAY = "\033[90m";

Node *create_node(int team_id, int score, int opponent_score);
Node *array2tree(const game_t *array, int size, int index);
void destroy_tree(Node *root);
static void print_tree(Node *root);

static result_t test(const game_t *input, const int num_teams, const int winner, const double *scores);
static inline bool all_tests_passed(const result_t *res, const int size);

int main(void)
{
    result_t res[2];
    double scores[] = {7.6, 0, 0, 4.4, 1.4, 0, 6.6, 4.2, 0, 0, 1.4, 13.6, 0, 0, 0, 2.8};
    game_t games[] = {{11, 3, 2}, {6, 3, 1},  {11, 3, 0}, {3, 3, 2},  {6, 3, 2}, {0, 3, 0},  {11, 3, 0}, {3, 3, 1},
                      {10, 3, 2}, {4, 3, 2},  {6, 3, 2},  {7, 3, 0},  {0, 3, 1}, {11, 3, 2}, {15, 3, 1}, {2, 0, 0},
                      {3, 0, 0},  {10, 0, 0}, {1, 0, 0},  {13, 0, 0}, {4, 0, 0}, {6, 0, 0},  {5, 0, 0},  {12, 0, 0},
                      {7, 0, 0},  {0, 0, 0},  {14, 0, 0}, {11, 0, 0}, {9, 0, 0}, {8, 0, 0},  {15, 0, 0}};

    double scores2[] = {7.4, 0, 3.6, 0};
    game_t games2[] = {{0, 3, 2}, {2, 3, 1}, {0, 3, 0}, {3, 0, 0}, {2, 0, 0}, {1, 0, 0}, {0, 0, 0}};

    res[0] = test(games2, 4, 0, scores2);
    res[1] = test(games, 16, 11, scores);

    if (all_tests_passed(res, 2))
    {
        printf("%sAll tests passed! 🎉%s\n", GREEN, RESET);
    }
    else
    {
        printf("%sSome tests failed! 😞%s\n", RED, RESET);
    }
    return 0;
}

Node *create_node(int team_id, int score, int opponent_score)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    assert(new_node != NULL);

    new_node->team_id = team_id;
    new_node->score = score;
    new_node->opponent_score = opponent_score;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void destroy_tree(Node *root)
{
    if (root == NULL)
        return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}

Node *array2tree(const game_t *array, int size, int index)
{
    if (index >= size)
        return NULL;

    Node *new_node = create_node(array[index].team_id, array[index].score, array[index].opponent_score);
    new_node->left = array2tree(array, size, 2 * index + 1);
    new_node->right = array2tree(array, size, 2 * index + 2);
    return new_node;
}

static inline bool all_tests_passed(const result_t *res, const int size)
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

static inline result_t test_winner(const int input, const int expected)
{
    return input == expected ? OK : FAIL;
}

static inline result_t test_scores(const double *input, const double *expected, const int len)
{
    for (int i = 0; i < len; i++)
    {
        if (fabs(input[i] - expected[i]) > TOLERANCE)
        {
            return FAIL;
        }
    }
    return OK;
}

static inline void print_float_array(const double *arr, const int len)
{
    for (int i = 0; i < len; i++)
        printf("%2.2f ", arr[i]);
    printf("\n");
}

static inline int count_nodes(const int leafs)
{
    return leafs * 2 - 1;
}

static result_t test(const game_t *input, const int num_teams, const int winner, const double *scores)
{
    Node *root = array2tree(input, count_nodes(num_teams), 0);
    double res_scores[num_teams];
    for (int i = 0; i < num_teams; i++)
        res_scores[i] = 0;
    get_scores(root, res_scores, 2);
    int res_winner = get_winner(res_scores);

    print_tree(root);

    result_t res1 = test_winner(res_winner, winner);
    result_t res2 = test_scores(res_scores, scores, num_teams);

    if (res1 == FAIL)
    {
        printf("%s❌ FAIL\n", RED);
        printf("\tExpected winner: %d\n", winner);
        printf("\tGot winner:      %d\n", res_winner);
    }
    else
    {
        printf("%s✔️ OK - ", GREEN);
        printf("Winner: %d\n", winner);
    }
    printf("%s", RESET);

    if (res2 == FAIL)
    {
        printf("%s❌ FAIL\n", RED);
        printf("\tExpected: ");
        print_float_array(scores, num_teams);
        printf("\tGot:      ");
        print_float_array(res_scores, num_teams);
    }
    else
    {
        printf("%s✔️ OK - ", GREEN);
        printf("Scores: ");
        print_float_array(res_scores, num_teams);
    }
    printf("%s\n", RESET);

    destroy_tree(root);

    return all_tests_passed((result_t[]){res1, res2}, 2) ? OK : FAIL;
}

static void print_subtree(Node *root, const char *prefix)
{
    if (root == NULL)
    {
        return;
    }

    bool hasLeft = (root->left != NULL);
    bool hasRight = (root->right != NULL);

    if (!hasLeft && !hasRight)
    {
        return;
    }

    printf("%s", prefix);
    printf("%s", LIGHT_BLUE);
    printf((hasLeft && hasRight) ? "├── " : "");
    printf((!hasLeft && hasRight) ? "└── " : "");
    printf("%s", RESET);

    if (hasRight)
    {
        char newPrefix[128] = {0};
        Node *next = root->right;
        bool printStrand = (hasLeft && hasRight && (next->right != NULL || next->left != NULL));
        printf("%s", LIGHT_BLUE);
        sprintf(newPrefix, "%s%s%s%s", prefix, LIGHT_BLUE, (printStrand ? "│   " : "    "), RESET);
        printf("%s", RESET);
        if (next->left == NULL)
            printf("%s%d%s\n", BOLD, next->team_id, RESET);
        else
            printf("%s%d%s, %s%s%d - %d%s\n", BOLD, next->team_id, RESET, ITALIC, GRAY, next->score,
                   next->opponent_score, RESET);
        print_subtree(next, newPrefix);
    }

    if (hasLeft)
    {
        char newPrefix[128] = {0};
        Node *next = root->left;
        printf("%s", hasRight ? prefix : "");
        printf("%s", LIGHT_BLUE);
        printf("└── ");
        printf("%s", RESET);

        if (next->left == NULL)
            printf("%s%d%s\n", BOLD, next->team_id, RESET);
        else
            printf("%s%d%s, %s%s%d - %d%s\n", BOLD, next->team_id, RESET, ITALIC, GRAY, next->score,
                   next->opponent_score, RESET);
        sprintf(newPrefix, "%s%s", prefix, "    ");
        print_subtree(next, newPrefix);
    }
}

static void print_tree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%s%d%s, %s%s%d - %d%s\n", BOLD, root->team_id, RESET, ITALIC, GRAY, root->score, root->opponent_score,
           RESET);
    print_subtree(root, "");
}
