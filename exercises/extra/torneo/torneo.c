#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int teamId;
    int setWon;
    int setLost;
    struct node *left;
    struct node *right;
} Node;

void getScores(Node *root, double *scores, double m)
{
    // TODO
}

int getWinner(double *scores, int n)
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

typedef struct game
{
    int teamId;
    int setWon;
    int setLost;
} game_t;

#define TOLERANCE 1e-6

static const char *RESET = "\033[0m";
static const char *BOLD = "\033[1m";
static const char *ITALIC = "\033[3m";
static const char *LIGHT_BLUE = "\033[94m";
static const char *RED = "\033[31m";
static const char *GREEN = "\033[32m";
static const char *GRAY = "\033[90m";

Node *create_node(int teamId, int setWon, int setLost);
Node *array2tree(const game_t *array, int size, int index);
void destroy_tree(Node *root);
static void print_tree(Node *root);

static result_t test(const game_t *input, const int num_teams, const int winner, const double *scores, const int mult);
static inline bool all_tests_passed(const result_t *res, const int size);

int main(void)
{
    result_t res[2];
    double scores[] = {4.5, 0.75, 0, 2.25, 0.75, 0.5, 5.75, 2.25, 0.5, 0.75, 1, 13.75, 0.25, 0.5, 0.25, 1.75};
    game_t games[] = {{11, 3, 2}, {6, 3, 1},  {11, 3, 0}, {3, 3, 2},  {6, 3, 2}, {0, 3, 0},  {11, 3, 0}, {3, 3, 1},
                      {10, 3, 2}, {4, 3, 2},  {6, 3, 2},  {7, 3, 0},  {0, 3, 1}, {11, 3, 2}, {15, 3, 1}, {2, 0, 0},
                      {3, 3, 2},  {10, 3, 1}, {1, 3, 0},  {13, 3, 1}, {4, 3, 2}, {6, 3, 2},  {5, 3, 1},  {12, 3, 2},
                      {7, 3, 0},  {0, 3, 1},  {14, 3, 2}, {11, 3, 2}, {9, 3, 0}, {8, 3, 1},  {15, 3, 0}};

    double scores2[] = {7.5, 0, 3, 0};
    game_t games2[] = {{0, 3, 2}, {2, 3, 1}, {0, 3, 0}, {3, 0, 0}, {2, 0, 0}, {1, 0, 0}, {0, 0, 0}};

    res[0] = test(games2, 4, 0, scores2, 3);
    res[1] = test(games, 16, 11, scores, 4);

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

Node *create_node(int teamId, int setWon, int setLost)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    assert(new_node != NULL);

    new_node->teamId = teamId;
    new_node->setWon = setWon;
    new_node->setLost = setLost;
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

    Node *new_node = create_node(array[index].teamId, array[index].setWon, array[index].setLost);
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

static result_t test(const game_t *input, const int num_teams, const int winner, const double *scores, const int mult)
{
    Node *root = array2tree(input, num_teams * 2 - 1, 0);
    double res_scores[num_teams];
    for (int i = 0; i < num_teams; i++)
        res_scores[i] = 0;
    getScores(root, res_scores, mult);
    int res_winner = getWinner(res_scores, num_teams);

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
            printf("%s%d%s\n", BOLD, next->teamId, RESET);
        else
            printf("%s%d%s, %s%s%d - %d%s\n", BOLD, next->teamId, RESET, ITALIC, GRAY, next->setWon, next->setLost,
                   RESET);
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
            printf("%s%d%s\n", BOLD, next->teamId, RESET);
        else
            printf("%s%d%s, %s%s%d - %d%s\n", BOLD, next->teamId, RESET, ITALIC, GRAY, next->setWon, next->setLost,
                   RESET);
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

    printf("%s%d%s, %s%s%d - %d%s\n", BOLD, root->teamId, RESET, ITALIC, GRAY, root->setWon, root->setLost, RESET);
    print_subtree(root, "");
}
