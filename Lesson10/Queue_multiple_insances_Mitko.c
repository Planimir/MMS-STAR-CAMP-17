#include <stdio.n>
#include <stdlib.h>

typedef struct A {
    int data;
} A;

typedef struct Queue {
    A *arr;
    size_t capacity;
    size_t cur_elem_count;
} Queue;

Queue init_queue(size_t capacity) {

}

int enQueue(Queue *q, A new_elem) {

}

int deQueue(Queue *q, A *res) {
    
}