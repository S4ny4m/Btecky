#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int rear;
    int front;
    int *Q;
};

void create(struct Queue *q);
void display(struct Queue q);
void enqueue(struct Queue *q, int val);
int dequeue(struct Queue *q);
int isEmpty(struct Queue q);
int isFull(struct Queue q);

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
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 9);
    display(q);
    return 0;
    return 0;
}

void create(struct Queue *q)
{
    int size;
    printf("Enter the size : ");
    scanf("%d", &size);
    q->size = size;
    q->Q = malloc(sizeof(int) * q->size);
    q->front = q->rear = 0;
}

void display(struct Queue q)
{
    printf("QUEUE is : ");
    // for (int i = q.front+1; i != q.rear; i = (i + 1) % q.size)
    //     printf("%d ", q.Q[i]);
    int i = q.front;
    do
    {
        i = (i + 1) % q.size;
        printf("%d ", q.Q[i]);
    } while (i != q.rear);
    printf("\n");
}
void enqueue(struct Queue *q, int val)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is full.Can't insert %d.\n", val);
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = val;
}

int dequeue(struct Queue *q)
{
    if (isEmpty(*q))
    {
        printf("The queue is empty.\n");
        return -1;
    }
    q->front = (q->front + 1) % q->size;
    return q->Q[q->front];
}

int isEmpty(struct Queue q)
{
    if (q.front == q.rear)
        return 1;
    return 0;
}
int isFull(struct Queue q)
{
    if ((q.rear + 1) % q.size == q.front)
        return 1;
    return 0;
}
