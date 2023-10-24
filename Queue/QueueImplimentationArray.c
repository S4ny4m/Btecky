#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

int isEmpty(struct Queue q);
int first(struct Queue q);
void enqueue(struct Queue *q, int val);
int isFull(struct Queue q);
int dequeue(struct Queue *q);
void create(struct Queue *q);
void display(struct Queue q);
int last(struct Queue q);

int main()
{
    struct Queue q;
    create(&q);
    if (isEmpty(q))
        printf("EMPTY rn.\n");

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    if (isFull(q))
        printf("FULL rn.\n");
    display(q);

    printf("DEQUEUE : %d\n", dequeue(&q));
    printf("DEQUEUE : %d\n", dequeue(&q));
    enqueue(&q, 4);
    display(q);
    return 0;
}

void enqueue(struct Queue *q, int val)
{
    if (isFull(*q))
    {
        printf("Queue is Full. Can't insert %d\n", val);
        return;
    }
    q->rear++;
    q->Q[q->rear] = val;
}

void display(struct Queue q)
{
    printf("Queue is : ");
    for (int i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}

int dequeue(struct Queue *q)
{
    if (q->front == q->rear)
    {
        printf("Queue Empty.\n");
        return -1;
    }
    q->front++;
    return q->Q[q->front];
}

void create(struct Queue *q)
{
    int size;
    printf("Enter the size of the queue : ");
    scanf("%d", &size);
    q->size = size;
    q->rear = q->front = -1;
    q->Q = malloc(sizeof(int) * size);
    printf("Size of q is : %d\n", q->size);
}

int isEmpty(struct Queue q)
{
    if (q.front == q.rear)
        return 1;
    return 0;
}
int isFull(struct Queue q)
{
    if (q.rear == q.size - 1)
        return 1;
    return 0;
}

int last(struct Queue q)
{
    return q.Q[q.rear];
}

int first(struct Queue q)
{
    if (isEmpty(q))
    {
        printf("Queue is EMPTY.\n");
        return -1;
    }
    return q.Q[q.front];
}