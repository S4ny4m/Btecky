#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *front = NULL, *rear = NULL;
void enqueue();
int dequeue();
void display();
int peek();

int main()
{

    // Node *front = NULL, *rear = NULL;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    printf("DEQUEUE : %d\n", dequeue());
    printf("DEQUEUE : %d\n", dequeue());
    enqueue(6);
    printf("PEEK : %d\n", peek());
    display();
    return 0;
}

void enqueue(int data)
{
    Node *t = malloc(sizeof(Node));
    if (t == NULL)
    {
        printf("Queue is full.\n");
        return;
    }
    t->data = data;
    t->link = NULL;
    if (front == NULL)
    {
        front = rear = t;
    }
    else
    {
        rear->link = t;
        rear = t;
    }
}

int dequeue()
{
    Node *t = front;
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int returnval = front->data;
    front = front->link;
    return returnval;
}

void display()
{
    Node *t = front;
    printf("Queue is : ");
    while (t)
    {
        printf("%d ", t->data);
        t = t->link;
    }
    printf("\n");
}

int peek()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    return front->data;
}