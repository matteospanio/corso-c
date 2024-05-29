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
void print_tree(Node *root);
static bool all_tests_passed(result_t *res, const int size);
static result_t test(const char *input, const char *expected, const char *key, const int seed);

int main(void)
{
    result_t res[4];
    Game games[NUM_MATCHES] = {
        {11, 26, 24}, {6, 25, 22}, {11, 25, 21}, {3, 40, 38}, {6, 25, 20}, {0, 25, 21},  {11, 25, 22}, {3, 26, 24},
        {10, 27, 25}, {4, 29, 27}, {6, 25, 23},  {7, 25, 19}, {0, 25, 18}, {11, 25, 20}, {15, 27, 25}, {2, 0, 0},
        {3, 0, 0},    {10, 0, 0},  {1, 0, 0},    {13, 0, 0},  {4, 0, 0},   {6, 0, 0},    {5, 0, 0},    {12, 0, 0},
        {7, 0, 0},    {0, 0, 0},   {14, 0, 0},   {11, 0, 0},  {9, 0, 0},   {8, 0, 0},    {15, 0, 0}};

    res[0] = test(TEST1, EXPECTED_TEST1, key, 0);
    res[1] = test(TEST2, EXPECTED_TEST2, key, 1);
    res[2] = test(TEST4, EXPECTED_TEST1, key, 3);

    if (all_tests_passed(res, 4))
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

static result_t test_winner();
static result_t test_scores();

static result_t test(const Game *input, const int expected)
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
