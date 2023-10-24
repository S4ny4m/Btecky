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

Queue *create()
{
    Queue *q = malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
void InsertFromFront(Queue **q, int key)
{
    Node *t = malloc(sizeof(Node));
    if (t == NULL)
    {
        printf("Queue is FULL.\n");
        return;
    }
    if ((*q)->front == NULL)
    {
        t->data = key;
        t->next = NULL;
        (*q)->front = (*q)->rear = t;
    }
    else
    {
        t->data = key;
        t->next = (*q)->front->next;
        (*q)->front->next = t;
        Node *temp = (*q)->front;
        while (temp->next)
            temp = temp->next;
        (*q)->rear = temp;
    }
}

int DeleteFromFront(Queue **q)
{
    if ((*q)->front == NULL)
    {
        printf("Queue is Empty.\n");
        return -1;
    }
    int returnval = (*q)->front->data;
    Node *t = (*q)->front;
    (*q)->front = (*q)->front->next;
    free(t);
    return returnval;
}

void InsertFromRear(Queue **q, int key)
{
    Node *t = malloc(sizeof(Node));
    if (t == NULL)
    {
        printf("Queue is FULL.\n");
        return;
    }
    if ((*q)->rear == NULL)
    {
        t->data = key;
        t->next = NULL;
        (*q)->rear = (*q)->front = t;
    }
    else
    {
        t->data = key;
        t->next = NULL;
        (*q)->rear->next = t;
        (*q)->rear = t;
    }
}
int DeleteFromRear(Queue **q)
{
    if ((*q)->rear == NULL)
    {
        printf("Can't Delete from Rear.Rear is Empty.\n");
        return -1;
    }
    /*
    3 cases :
    1 -> When there is 1 node
    {
        we delete the node.
    }
    2 -> when there are 2 and more nodes nodes
    {
        we delete the 2nd node and then we point front and rear at 1st node.
    }

    */
    int returnval;
    Node *t = (*q)->front;
    if (t->next == NULL)
    {
        returnval = t->data;
        free(t);
    }
    else
    {
        while (t->next->next) // t at 2rd last node of the linked list.
            t = t->next;
        returnval = t->next->data;
        (*q)->rear = t;
        (*q)->rear->next = NULL;
        free(t->next);
    }
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
    InsertFromFront(&q, 1);
    InsertFromFront(&q, 2);
    InsertFromFront(&q, 3);
    InsertFromFront(&q, 4);
    display(q->front); // 1 4 3 2
    InsertFromRear(&q, 5);
    InsertFromRear(&q, 6);
    InsertFromRear(&q, 7);
    display(q->front);   //--> 1 4 3 2 5 6 7
    DeleteFromFront(&q); // 4 3 2 5 6 7
    DeleteFromFront(&q); // 3 2 5 6 7
    display(q->front);   //--> 3 2 5 6 7
    DeleteFromRear(&q);  // 3 2 5 6
    DeleteFromRear(&q);  // 3 2 5
    display(q->front);   //--> 3 2 5

    return 0;
}