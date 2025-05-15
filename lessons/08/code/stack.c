#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} Node;
typedef struct stack
{
    Node *top;
} Stack;

Node *new_node(int value);
Stack *new_stack(void);
void free_stack(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int is_empty(Stack *stack);
void print_stack(Stack *stack);

int main(void)
{
    Stack *stack = new_stack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    print_stack(stack);
    printf("Popped: %d\n", pop(stack));
    print_stack(stack);
    free_stack(stack);
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
    return node;
}

Stack *new_stack(void)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

void free_stack(Stack *stack)
{
    Node *current = stack->top;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

void push(Stack *stack, int value)
{
    Node *node = new_node(value);
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack)
{
    if (is_empty(stack))
    {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    Node *node = stack->top;
    int value = node->value;
    stack->top = node->next;
    free(node);
    return value;
}

int is_empty(Stack *stack)
{
    return stack->top == NULL;
}

void print_stack(Stack *stack)
{
    Node *current = stack->top;
    printf("Stack: ");
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
