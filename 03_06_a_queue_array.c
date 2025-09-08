#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

int isFull() { return (front == (rear + 1) % SIZE); }
int isEmpty() { return (front == -1); }

void enqueue(int x) {
    if (isFull()) { printf("Queue Full\n"); return; }
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = x;
}

void dequeue() {
    if (isEmpty()) { printf("Queue Empty\n"); return; }
    if (front == rear) front = rear = -1;
    else front = (front + 1) % SIZE;
}

void display() {
    if (isEmpty()) { printf("Queue Empty\n"); return; }
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30); enqueue(40); enqueue(50);
    display();
    dequeue(); dequeue();
    display();
    enqueue(60); enqueue(70);
    display();
    return 0;
}
