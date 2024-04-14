// xor linked lists
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

typedef struct xorlist
{
    Node *head;
} XorList;

Node *XOR(Node *a, Node *b)
{
    return (Node *)((uint64_t)a ^ (uint64_t)b);
}

void insert(XorList *list, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->link = XOR(list->head, NULL);
    if (list->head != NULL)
    {
        Node *next = XOR(list->head->link, NULL);
        list->head->link = XOR(new_node, next);
    }
    list->head = new_node;
}

void print(XorList list)
{
    Node *prev = NULL;
    Node *curr = list.head;
    Node *next;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        next = XOR(prev, curr->link);
        prev = curr;
        curr = next;
    }
    printf("\n");
}

void delete_list(XorList *list)
{
    Node *prev = NULL;
    Node *curr = list->head;
    Node *next;
    while (curr != NULL)
    {
        next = XOR(prev, curr->link);
        free(curr);
        prev = curr;
        curr = next;
    }
    list->head = NULL;
}

int main()
{
    XorList list = {NULL};
    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 30);
    insert(&list, 40);
    insert(&list, 50);
    print(list);
    delete_list(&list);

    return 0;
}
