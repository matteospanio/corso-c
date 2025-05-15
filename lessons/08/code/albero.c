#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *parent;
    struct node *left;
    struct node *right;
} Node;

Node *new_node(int value, Node *parent);
Node *insert_left(Node *parent, int value);
Node *insert_right(Node *parent, int value);
void inorder_traversal(Node *node);
void preorder_traversal(Node *node);
void postorder_traversal(Node *node);
void free_tree(Node *node);

int main(void)
{
    Node *root = new_node(1, NULL);
    Node *left_child = insert_left(root, 2);
    Node *right_child = insert_right(root, 3);
    insert_left(left_child, 4);
    insert_right(left_child, 5);
    insert_left(right_child, 6);
    insert_right(right_child, 7);

    printf("Inorder Traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder_traversal(root);
    printf("\n");

    free_tree(root);
    return 0;
}

Node *new_node(int value, Node *parent)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->value = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insert_left(Node *parent, int value)
{
    Node *node = new_node(value, parent);
    parent->left = node;
    return node;
}

Node *insert_right(Node *parent, int value)
{
    Node *node = new_node(value, parent);
    parent->right = node;
    return node;
}

void inorder_traversal(Node *node)
{
    if (node == NULL)
        return;
    inorder_traversal(node->left);
    printf("%d ", node->value);
    inorder_traversal(node->right);
}

void preorder_traversal(Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->value);
    preorder_traversal(node->left);
    preorder_traversal(node->right);
}

void postorder_traversal(Node *node)
{
    if (node == NULL)
        return;
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    printf("%d ", node->value);
}

void free_tree(Node *node)
{
    if (node == NULL)
        return;
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}
