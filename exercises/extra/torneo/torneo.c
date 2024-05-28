#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "solution.h"

Node *create_node(int team_id, int score, int opponent_score);
Node *make_tree(void);
void destroy_tree(Node *root);

int main()
{
    Node *root = make_tree();

    double scores[16] = {0};
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

Node *make_tree(void)
{
    Node *root = create_node(11, 26, 24);
    root->left = create_node(6, 25, 22);
    root->right = create_node(11, 25, 21);

    root->left->left = create_node(3, 40, 38);
    root->left->right = create_node(6, 25, 20);
    root->right->left = create_node(0, 25, 21);
    root->right->right = create_node(11, 25, 22);

    root->left->left->left = create_node(3, 26, 24);
    root->left->left->right = create_node(10, 27, 25);
    root->left->right->left = create_node(4, 29, 27);
    root->left->right->right = create_node(6, 25, 23);
    root->right->left->left = create_node(7, 25, 19);
    root->right->left->right = create_node(0, 25, 18);
    root->right->right->left = create_node(11, 25, 20);
    root->right->right->right = create_node(15, 27, 25);

    root->left->left->left->left = create_node(2, 0, 0);
    root->left->left->left->right = create_node(3, 0, 0);
    root->left->left->right->left = create_node(10, 0, 0);
    root->left->left->right->right = create_node(1, 0, 0);
    root->left->right->left->left = create_node(13, 0, 0);
    root->left->right->left->right = create_node(4, 0, 0);
    root->left->right->right->left = create_node(6, 0, 0);
    root->left->right->right->right = create_node(5, 0, 0);
    root->right->left->left->left = create_node(12, 0, 0);
    root->right->left->left->right = create_node(7, 0, 0);
    root->right->left->right->left = create_node(0, 0, 0);
    root->right->left->right->right = create_node(14, 0, 0);
    root->right->right->left->left = create_node(11, 0, 0);
    root->right->right->left->right = create_node(9, 0, 0);
    root->right->right->right->left = create_node(8, 0, 0);
    root->right->right->right->right = create_node(15, 0, 0);

    return root;
}
