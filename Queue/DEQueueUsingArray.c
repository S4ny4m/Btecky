#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
} Qwe;

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

void InsertUsingRear(Qwe *q, int val)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is full.\n");
        return;
    }
    q->Q[++(q->rear)] = val;
}

int DeleteUsingRear(Qwe *q)
{
    if (q->rear - q->front <= 0)
    {
        printf("Queue EMPTY.\n");
        return -1;
    }
    return q->Q[q->rear--];
}

int DeleteUsingFront(Qwe *q)
{
    if (q->front == q->rear)
    {
        printf("Queue is Empty.\n");
        return -1;
    }
    return q->Q[++q->front];
}

void InsertUsingFront(Qwe *q, int val)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is full.\n");
        return;
    }
    for (int i = q->rear + 1; i > q->front + 2; i--)
        q->Q[i] = q->Q[i - 1];

    q->Q[(q->front) + 2] = val;
    q->rear++;
}

void display(struct Queue q)
{
    printf("Queue is : ");
    for (int i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}
int main()
{
    Qwe q;
    create(&q);
    InsertUsingRear(&q, 1);
    InsertUsingRear(&q, 2);
    InsertUsingRear(&q, 3);
    InsertUsingRear(&q, 4);
    display(q);
    printf("DEQUEUE : %d\n", DeleteUsingFront(&q));
    printf("DEQUEUE : %d\n", DeleteUsingFront(&q));
    display(q);
    InsertUsingFront(&q, 5);
    InsertUsingFront(&q, 6); // 3 6 5 4
    DeleteUsingRear(&q);     // 3 6 5
    display(q);
    return 0;
}