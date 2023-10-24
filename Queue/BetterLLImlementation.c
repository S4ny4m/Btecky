#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct queue
{
    Node *front;
    Node *rear;
} Queue;

Queue *create();
void enqueue(Queue **q, int val);
int dequeue(Queue **q);
int isEmpty(Queue *q);
void display(Node *t);
int peek(Node *front);

int main()
{
    Queue *q = create();
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    display(q->front);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    printf("Front == %d \n", peek(q->front));
    dequeue(&q);
    display(q->front);
    return 0;
}

Queue *create()
{
    Queue *q = malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue **q, int val)
{
    if ((*q)->front == NULL)
    {
        Node *t = malloc(sizeof(Node));
        t->data = val;
        t->next = NULL;
        (*q)->front = (*q)->rear = t;
        return;
    }
    Node *t = malloc(sizeof(Node));
    if (t == NULL)
    {
        printf("Memory Overflow.\n");
        return;
    }
    t->data = val;
    t->next = NULL;
    (*q)->rear->next = t;
    (*q)->rear = t;
}

int dequeue(Queue **q)
{
    if ((*q)->front == NULL)
    {
        printf("Queue already Empty.\n");
        return -1;
    }
    int returnval;
    returnval = (*q)->front->data;
    Node *del = (*q)->front;
    (*q)->front = (*q)->front->next;
    free(del);
    return returnval;
}

int isEmpty(Queue *q)
{
    if (q->front)
        return 1;
    else
        return 0;
}

// void display(Queue *q)
// {

//     printf("Printing from Front to Rear: ");
//     while (q->front)
//     {
//         printf("%d ", q->front->data);
//         q->front = q->front->next;
//     }
//     printf("\n");
// }

void display(Node *t)
{
    // Node *t = q->front;
    if (t == NULL)
    {
        printf("Queue Empty.\n");
        return;
    }
    printf("Printing from Front to Rear: ");
    while (t)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int peek(Node *front)
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    return front->data;
}