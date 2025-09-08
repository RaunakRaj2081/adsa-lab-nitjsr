// Implement a queue using two stacks by Methods-1 (making Push operation costly in terms of time) and
// by Method-2 (making Pop operation costly).
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// Stack structure
struct Stack {
    int arr[SIZE];
    int top;
};

void init(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return (s->top == -1);
}

void push(struct Stack* s, int value) {
    if (s->top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = value;
}

int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

int peek(struct Stack* s) {
    if (isEmpty(s)) return -1;
    return s->arr[s->top];
}

// ----------------- METHOD 1: Push costly -----------------
struct Stack s1, s2;

void enqueue_method1(int x) {
    // Move all elements from s1 to s2
    while (!isEmpty(&s1)) {
        push(&s2, pop(&s1));
    }
    // Push new element into s1
    push(&s1, x);
    // Move everything back to s1
    while (!isEmpty(&s2)) {
        push(&s1, pop(&s2));
    }
    printf("Enqueued %d\n", x);
}

int dequeue_method1() {
    if (isEmpty(&s1)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return pop(&s1);
}

// ----------------- METHOD 2: Pop costly -----------------
struct Stack s3, s4;

void enqueue_method2(int x) {
    push(&s3, x);
    printf("Enqueued %d\n", x);
}

int dequeue_method2() {
    if (isEmpty(&s3) && isEmpty(&s4)) {
        printf("Queue is Empty\n");
        return -1;
    }
    if (isEmpty(&s4)) {
        // Move all from s3 to s4
        while (!isEmpty(&s3)) {
            push(&s4, pop(&s3));
        }
    }
    return pop(&s4);
}

// ----------------- MAIN -----------------
int main() {
    init(&s1); init(&s2);
    init(&s3); init(&s4);

    printf("\n--- Method 1 (Push Costly) ---\n");
    enqueue_method1(10);
    enqueue_method1(20);
    enqueue_method1(30);
    printf("Dequeued: %d\n", dequeue_method1());
    printf("Dequeued: %d\n", dequeue_method1());

    printf("\n--- Method 2 (Pop Costly) ---\n");
    enqueue_method2(40);
    enqueue_method2(50);
    enqueue_method2(60);
    printf("Dequeued: %d\n", dequeue_method2());
    printf("Dequeued: %d\n", dequeue_method2());

    return 0;
}
