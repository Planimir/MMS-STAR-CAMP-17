#include <stdio.h>

#define SIZE 5

int items[SIZE], front = -1, rear = -1, count = 0;

void enQueue(int value);
void deQueue();
void peek();

int main(int argc, char *argv) {

    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);

    peek();

    deQueue();

    peek();


    return 0;
}

void enQueue(int value) {

  if (rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (front == -1)
      front = 0;
    rear++;
    items[rear] = value;
    printf("\nInserted -> %d", value);
  }
}

void deQueue() {
    if( front == -1) {
        printf("\nThe Queue is empty!");
    } else {
        printf("\nRemoved item: %d", items[front]);
        front++;

        if(front > rear) {
            front = rear = -1;
        }
    }
    
}

void peek() {
    if (rear == -1){
        printf("\nQueue is Empty!!!");

    }
    else {
        int i;
        printf("\nQueue elements are:\n");

        for (i = front; i <= rear; i++){
            printf("%d  ", items[i]);

        }

    }

  printf("\n");
}
