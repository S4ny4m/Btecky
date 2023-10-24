#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int Priority;
    struct node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

Queue *create()
{
    Queue *q = malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void EnQ(Queue **q, int val, int p)
{
    Node *t = malloc(sizeof(Node));
    if (t == NULL)
    {
        printf("Q is FULL (Memory Full).\n");
        return;
    }
    t->data = val;
    t->Priority = p;
    if ((*q)->front == NULL)
    {
        t->next = NULL;
        (*q)->front = (*q)->rear = t;
    }
    else if (p < (*q)->front->Priority)
    {
        t->next = (*q)->front;
        (*q)->front = t;
    }
    else
    {
        Node *temp = (*q)->front;
        while (temp && temp->next)
        {
            if (temp->next->Priority > p)
                break;
            temp = temp->next;
        }
        t->next = temp->next;
        temp->next = t;
    }
}

int DeQ(Queue **q)
{
    if ((*q)->front == NULL)
    {
        printf("Q is Empty.\n");
        return -1;
    }
    int returnval = (*q)->front->data;
    Node *temp = (*q)->front;
    (*q)->front = (*q)->front->next;
    free(temp);
    return returnval;
}

void display(Node *t)
{
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
int main()
{
    Queue *q = create();
    EnQ(&q, 1, 1);
    EnQ(&q, 2, 2);
    EnQ(&q, 4, 3);
    EnQ(&q, 3, 2);
    EnQ(&q, 5, 0);
    display(q->front);
    DeQ(&q);
    display(q->front);
    return 0;
}