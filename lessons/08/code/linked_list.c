#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;
} Node;

typedef struct list
{
    Node *head;
    Node *tail;
    int size;
} List;

Node *new_node(int value);
List *new_list(void);
void free_list(List *list);
void append(List *list, int value);
void prepend(List *list, int value);
void insert(List *list, int index, int value);
void print_list(List *list);

int main(void)
{
    List *list = new_list();
    append(list, 10);
    append(list, 20);
    prepend(list, 5);
    insert(list, 1, 15);
    print_list(list);
    free_list(list);
    return 0;
}

Node *new_node(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

List *new_list(void)
{
    List *list = (List *)malloc(sizeof(List));
    if (list == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void free_list(List *list)
{
    Node *current = list->head;
    Node *next_node;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(list);
}

void append(List *list, int value)
{
    Node *node = new_node(value);
    if (list->tail == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
    list->size++;
}

void prepend(List *list, int value)
{
    Node *node = new_node(value);
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
    list->size++;
}

void insert(List *list, int index, int value)
{
    if (index < 0 || index > list->size)
    {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }
    if (index == 0)
    {
        prepend(list, value);
        return;
    }
    if (index == list->size)
    {
        append(list, value);
        return;
    }
    Node *node = new_node(value);
    Node *current = list->head;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }
    node->next = current->next;
    node->prev = current;
    current->next->prev = node;
    current->next = node;
    list->size++;
}

void print_list(List *list)
{
    Node *current = list->head;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
