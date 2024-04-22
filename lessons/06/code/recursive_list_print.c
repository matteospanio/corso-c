#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} Node;

// Implement recursive_list_print and recursive_list_delete
void recursive_list_print(Node *head);
void recursive_list_delete(Node *head);

int list_prepend(Node **head, int value);

int main(void)
{
    Node *head = NULL;
    list_prepend(&head, 1);
    list_prepend(&head, 2);
    list_prepend(&head, 3);
    list_prepend(&head, 4);
    list_prepend(&head, 5);
    recursive_list_print(head);
    recursive_list_delete(head);
    return 0;
}

void recursive_list_print(Node *head)
{
    // TODO
}

void recursive_list_delete(Node *head)
{
    // TODO
}

int list_prepend(Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        return -1;
    }
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
    return 0;
}
