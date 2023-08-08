#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createCyclicLinkedList(int *elements, int n);

void print(Node *cll);

Node* insertAfter(Node *cll, int skipCount, int newElem);

int main() {
    int N;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &N);

    int *elements = (int*)malloc(N * sizeof(int));
    printf("Enter the elements: ");
    for(int i = 0; i < N; i++)
        scanf("%d", &elements[i]);

    Node *cll = createCyclicLinkedList(elements, N);

    printf("Elements of the list: ");
    print(cll);

    printf("Enter the number of elements to skip: ");
    int skip;
    scanf("%d", &skip);

    printf("Enter the new element to insert: ");
    int newElem;
    scanf("%d", &newElem);

    insertAfter(cll, skip, newElem);

    printf("Elements of the list after insertion: ");
    print(cll);

    free(elements);

    return 0;
}

Node* createCyclicLinkedList(int *elements, int n) {
    Node *head = NULL, *tail = NULL;

    for(int i = 0; i < n; i++) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = elements[i];
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    tail->next = head;

    return head;
}

void print(Node *cll) {
    Node *temp = cll;
    if (cll != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != cll);
    }
    printf("\n");
}

Node* insertAfter(Node *cll, int skipCount, int newElem) {
    Node *temp = cll;

    for(int i = 0; i < skipCount; i++)
        temp = temp->next;

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newElem;
    newNode->next = temp->next;
    temp->next = newNode;

    return newNode;
}


/*

    gcc ex_02.c -o ex_02 -Wall -Wextra


*/