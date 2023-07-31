#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int value;
} Item;

typedef struct {
    Item items[SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue();
void enQueue(Queue* q, int value);
void deQueue(Queue* q);
void peek(Queue* q);

int main(int argc, char *argv[]) {
    Queue* queue1 = createQueue();
    Queue* queue2 = createQueue();

    printf("\nQueue 1:\n");


    enQueue(queue1, 1);
    deQueue(queue1);
    enQueue(queue1, 2);
    deQueue(queue1);
    enQueue(queue1, 3);
    deQueue(queue1);
    enQueue(queue1, 4);
    deQueue(queue1);
    enQueue(queue1, 5);
    deQueue(queue1);
    enQueue(queue1, 6);
    deQueue(queue1);
    enQueue(queue1, 7);
    deQueue(queue1);
    enQueue(queue1, 8);
    deQueue(queue1);
    enQueue(queue1, 9);
    deQueue(queue1);
    enQueue(queue1, 10);
    deQueue(queue1);



    printf("\n");
    peek(queue1);
    deQueue(queue1);
    peek(queue1);

    printf("\n\nQueue 2:\n");

    enQueue(queue2, 5);
    enQueue(queue2, 6);
    enQueue(queue2, 7);
    enQueue(queue2, 8);
    enQueue(queue2, 9);

    printf("\n");
    peek(queue2);
    deQueue(queue2);
    peek(queue2);

    free(queue1);
    free(queue2);

    return 0;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enQueue(Queue* q, int value) {
    if (q->rear == SIZE - 1) {
        printf("\nQueue is Full!!");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear].value = value;
        printf("\nInserted -> %d", value);
    }
}

void deQueue(Queue* q) {
    if (q->front == -1) {
        printf("\nThe Queue is empty!");
    } else {
        printf("\nRemoved item: %d", q->items[q->front].value);
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
}

void peek(Queue* q) {
    if (q->rear == -1) {
        printf("\nQueue is Empty!!!");
    } else {
        printf("\nQueue elements are:\n");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d  ", q->items[i].value);
        }
    }
    printf("\n");
}