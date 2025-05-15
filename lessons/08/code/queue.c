#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} Node;

typedef struct queue
{
    Node *front;
    Node *rear;
} Queue;

Node *new_node(int value);
Queue *new_queue(void);
void free_queue(Queue *queue);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
int is_empty(Queue *queue);
void print_queue(Queue *queue);

int main(void)
{
    Queue *queue = new_queue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    print_queue(queue);
    printf("Dequeued: %d\n", dequeue(queue));
    print_queue(queue);
    free_queue(queue);
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

Queue *new_queue(void)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void free_queue(Queue *queue)
{
    Node *current = queue->front;
    Node *next_node;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(queue);
}

void enqueue(Queue *queue, int value)
{
    Node *node = new_node(value);
    if (queue->rear == NULL)
    {
        queue->front = node;
        queue->rear = node;
    }
    else
    {
        queue->rear->next = node;
        queue->rear = node;
    }
}

int dequeue(Queue *queue)
{
    if (is_empty(queue))
    {
        fprintf(stderr, "Queue underflow\n");
        exit(EXIT_FAILURE);
    }
    Node *node = queue->front;
    int value = node->value;
    queue->front = node->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(node);
    return value;
}

int is_empty(Queue *queue)
{
    return queue->front == NULL;
}

void print_queue(Queue *queue)
{
    Node *current = queue->front;
    printf("Queue: ");
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
