// Implement a stack using two queues by Method 1 (making EnQueue operation costly) and by Method 2
// (making DeQueue operation costly in terms of time).
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// Queue structure
struct Queue {
    int arr[SIZE];
    int front, rear;
};

void init(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return (q->front == -1);
}

void enqueue(struct Queue* q, int x) {
    if ((q->rear + 1) % SIZE == q->front) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % SIZE;
    q->arr[q->rear] = x;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int x = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    return x;
}

// ----------------- METHOD 1: Push costly -----------------
struct Queue q1, q2;

void push_method1(int x) {
    enqueue(&q2, x); // Step 1
    while (!isEmpty(&q1)) { // Step 2
        enqueue(&q2, dequeue(&q1));
    }
    // Step 3: swap q1 and q2
    struct Queue temp = q1;
    q1 = q2;
    q2 = temp;
    printf("Pushed %d\n", x);
}

int pop_method1() {
    if (isEmpty(&q1)) {
        printf("Stack is Empty\n");
        return -1;
    }
    return dequeue(&q1);
}

// ----------------- METHOD 2: Pop costly -----------------
struct Queue q3, q4;

void push_method2(int x) {
    enqueue(&q3, x);
    printf("Pushed %d\n", x);
}

int pop_method2() {
    if (isEmpty(&q3)) {
        printf("Stack is Empty\n");
        return -1;
    }
    while (q3.front != q3.rear) {
        enqueue(&q4, dequeue(&q3));
    }
    int popped = dequeue(&q3); // last element (top of stack)
    struct Queue temp = q3;
    q3 = q4;
    q4 = temp;
    return popped;
}

// ----------------- MAIN -----------------
int main() {
    init(&q1); init(&q2);
    init(&q3); init(&q4);

    printf("\n--- Method 1 (Push Costly) ---\n");
    push_method1(10);
    push_method1(20);
    push_method1(30);
    printf("Popped: %d\n", pop_method1());
    printf("Popped: %d\n", pop_method1());

    printf("\n--- Method 2 (Pop Costly) ---\n");
    push_method2(40);
    push_method2(50);
    push_method2(60);
    printf("Popped: %d\n", pop_method2());
    printf("Popped: %d\n", pop_method2());

    return 0;
}
