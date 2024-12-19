#include <stdio.h>
#define MAX 5 // Maximum size of the queue

int queue[MAX];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() {
    return (rear + 1) % MAX == front;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to add an element to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty()) {
        front = 0; // Initialize front when the first element is added
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Indicate that the queue is empty
    }
    int value = queue[front];
    if (front == rear) { // Queue has only one element
        front = rear = -1; // Reset the queue
    } else {
        front = (front + 1) % MAX;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    enqueue(40);
    enqueue(50);
    enqueue(60); // This will show that the queue is full
    display();
    return 0;
}