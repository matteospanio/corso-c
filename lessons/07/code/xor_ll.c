// xor linked lists
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// XOR linked list implementation
// La XOR linked list è una struttura dati che utilizza l'operazione XOR per memorizzare gli indirizzi dei nodi.
// In questo modo, ogni nodo memorizza solo un indirizzo invece di due, riducendo l'uso della memoria.

typedef struct node
{
    int data;
    struct node *link;
} Node;

typedef struct xorlist
{
    Node *head;
} XorList;

/**
 * XOR function to get the address of the next node
 * @param curr Pointer to the first node
 * @param next Pointer to the second node
 * @return XOR of the two pointers
 */
Node *XOR(Node *curr, Node *next);

/**
 * Prepend a new node to the XOR linked list
 * @param list Pointer to the XOR linked list
 * @param data Data to be stored in the new node
 */
void list_prepend(XorList *list, int data);
void list_recursive_print(XorList list);
void list_delete(XorList *list);

int main()
{
    XorList list = {NULL};
    list_prepend(&list, 10);
    list_prepend(&list, 20);
    list_prepend(&list, 30);
    list_prepend(&list, 40);
    list_prepend(&list, 50);
    list_recursive_print(list);
    list_delete(&list);

    return 0;
}

void aux_rec_print(Node *prev, Node *curr)
{
    if (curr == NULL)
        return;

    printf("%d ", curr->data);
    Node *next = XOR(prev, curr->link);
    aux_rec_print(curr, next);
}

void list_recursive_print(XorList list)
{
    aux_rec_print(NULL, list.head);
    printf("\n");
}

Node *XOR(Node *a, Node *b)
{
    return (Node *)((uint64_t)a ^ (uint64_t)b);
}

void list_prepend(XorList *list, int data)
{
    Node *new_node = (Node *)calloc(1, sizeof(Node));
    new_node->data = data;
    new_node->link = XOR(list->head, NULL);
    if (list->head != NULL)
    {
        Node *next = XOR(list->head->link, NULL);
        list->head->link = XOR(new_node, next);
    }
    list->head = new_node;
}

void list_delete(XorList *list)
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
