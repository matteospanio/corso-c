#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "solution.h"

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
} Game;

static const int NUM_TEAMS = 16;
static const int NUM_MATCHES = (NUM_TEAMS * 2) - 1;
static const char *RESET = "\033[0m";
static const char *RED = "\033[31m";
static const char *GREEN = "\033[32m";

Node *create_node(int team_id, int score, int opponent_score);
Node *array2tree(Game *array, int size, int index);
void destroy_tree(Node *root);

static result_t test(const Game *input, const int winner, const int *scores);
static inline bool all_tests_passed(result_t *res, const int size);
static inline result_t test_winner(const int input, const int expected);
static inline result_t test_scores(const int *input, const int *expected);

int main(void)
{
    result_t res[1];
    Game games[NUM_MATCHES] = {
        {11, 26, 24}, {6, 25, 22}, {11, 25, 21}, {3, 40, 38}, {6, 25, 20}, {0, 25, 21},  {11, 25, 22}, {3, 26, 24},
        {10, 27, 25}, {4, 29, 27}, {6, 25, 23},  {7, 25, 19}, {0, 25, 18}, {11, 25, 20}, {15, 27, 25}, {2, 0, 0},
        {3, 0, 0},    {10, 0, 0},  {1, 0, 0},    {13, 0, 0},  {4, 0, 0},   {6, 0, 0},    {5, 0, 0},    {12, 0, 0},
        {7, 0, 0},    {0, 0, 0},   {14, 0, 0},   {11, 0, 0},  {9, 0, 0},   {8, 0, 0},    {15, 0, 0}};

    res[0] = test();


    if (all_tests_passed(res, 1))
    {
        printf("%sAll tests passed! 🎉%s\n", GREEN, RESET);
    }
    else
    {
        printf("%sSome tests failed! 😞%s\n", RED, RESET);
    }

    Node *root = array2tree(games, NUM_MATCHES, 0);

    double scores[NUM_TEAMS] = {0};
    get_scores(root, scores, 2);
    print_scores(scores);

    destroy_tree(root);
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

Node *array2tree(Game *array, int size, int index)
{
    if (index >= size)
        return NULL;

    Node *new_node = create_node(array[index].team_id, array[index].score, array[index].opponent_score);
    new_node->left = array2tree(array, size, 2 * index + 1);
    new_node->right = array2tree(array, size, 2 * index + 2);
    return new_node;
}

static inline bool all_tests_passed(result_t *res, const int size)
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

static inline result_t test_winner(const int input, const int expected) {
    return input == expected ? OK : FAIL;
}

static inline result_t test_scores(const int *input, const int *expected) {
    for (int i = 0; i < NUM_TEAMS; i++) {
        if (input[i] != expected[i]) {
            return FAIL;
        }
    }
    return OK;
}

static result_t test(const Game *input, const int winner, const int *scores)
{
    Node *root = array2tree(input, NUM_MATCHES, 0);
    int res_winner = get_winner(root);
    int res_scores[NUM_TEAMS] = {0};
    get_scores(root, res_scores, 2);

    result_t res1 = test_winner(res_winner, winner);
    result_t res2 = test_scores(res_scores, scores);

    if (res1 == FAIL)
    {
        printf("%s❌ FAIL\n", RED);
        printf("Test input: ");
        for (int i = 0; i < NUM_MATCHES; i++)
        {
            printf("{%d, %d, %d}, ", input[i].team_id, input[i].score, input[i].opponent_score);
        }
        printf("\n");
        printf("\tExpected winner: %d\n", winner);
        printf("\tGot winner:      %d\n", res_winner);
    } else {
        printf("%s✔️ OK\n", GREEN);
        printf("\tWinner: %d\n", winner);
    }
    printf("%s", RESET);

    if (res2 == FAIL)
    {
        printf("%s❌ FAIL\n", RED);
        printf("Test input: ");
        for (int i = 0; i < NUM_MATCHES; i++)
        {
            printf("{%d, %d, %d}, ", input[i].team_id, input[i].score, input[i].opponent_score);
        }
        printf("\n");
        printf("\tScores:\n");
        printf("\tExpected\tActual");
    } else {
        printf("%s✔️ OK\n", GREEN);
        printf("\tScores: ");
        for (int i = 0; i < NUM_TEAMS; i++)
        {
            printf("%d, ", scores[i]);
        }
        printf("\n");
    }
    printf("%s", RESET);

    destroy_tree(root);

    return res == 0 ? OK : FAIL;
}
