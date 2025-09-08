#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    if (!front) front = temp;
    else rear->next = temp;
    rear = temp;
    rear->next = front;
}

void dequeue() {
    if (!front) { printf("Queue Empty\n"); return; }
    if (front == rear) { free(front); front = rear = NULL; return; }
    struct Node* temp = front;
    front = front->next;
    rear->next = front;
    free(temp);
}

void display() {
    if (!front) { printf("Queue Empty\n"); return; }
    struct Node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30); enqueue(40);
    display();
    dequeue(); dequeue();
    display();
    enqueue(50); enqueue(60);
    display();
    return 0;
}
