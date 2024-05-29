#include "solution.h"
#include <stdio.h>
#include <stdlib.h>

void get_scores(Node *root, double *scores, double multiplier)
{
    if (root == NULL)
        return;

    scores[root->team_id] += (root->score - root->opponent_score) * multiplier;

    get_scores(root->left, scores, multiplier - 0.2);
    get_scores(root->right, scores, multiplier - 0.2);
}

void print_scores(double *scores)
{
    for (int i = 0; i < 16; i++)
        printf("Team %d: %.2lf\n", i, scores[i]);
}

int get_winner(double *scores)
{
    int winner = 0;
    for (int i = 1; i < 16; i++)
        if (scores[i] > scores[winner])
            winner = i;
    return winner;
}
