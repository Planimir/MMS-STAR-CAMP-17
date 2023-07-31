#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int count = 0;

typedef struct Stack {
    int items[SIZE];
    int top;
} Stack;


int push(Stack *s, int newItem);

int pop(Stack *s);

int peek(Stack *s, int arr[]);

int createEmptyStack(Stack *s);

void printStack(Stack *s);

int isEmpty(Stack *s);


int main(int argc, char *argv[]) {

    Stack *s = (Stack*)malloc(sizeof(Stack));

    createEmptyStack(s);


    createEmptyStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s);

    pop(s);

    printf("\nAfter popping out\n");
    printStack(s);

    free(s);

    return 0;
}

int createEmptyStack(Stack *s) {
    s->top = -1;
}


int push(Stack *s, int newItem) {
    if(s->top > SIZE - 1) {
        printf("Stack is full!");
    } else {
        s->top++;
        s->items[s->top] = newItem;
    }

    count++;

}

int pop(Stack *s) {
    if(s->top == -1) {
        printf("Stack has no elements!");
    } else {
        printf("Item : | %d | has been popped.", s->items[s->top]);
        s->top--;
    }
    count--;
}

int peek(Stack *s, int arr[]) {

    if(s->top == 0) {
        printf("The stack is empty");
    } else {
        printf("The top element is : %d", s->items[s->top]);
    }
}

void printStack(Stack *s) {
    int i = 0;
    printf("\nStack : \n"); 

        for(i = 0; i < count; i++) {
            printf("%d ", s->items[i]);
        }

      printf("\n");
}

int isEmpty(Stack *s) {
    if(s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(Stack *s) {
    if(s->top == SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}
