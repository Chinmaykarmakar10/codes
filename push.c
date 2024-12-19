#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the stack

// Global variables for the stack
int stack[MAX];
int top = -1; // Stack is initially empty

// Function to check if the stack is full
int isFull() {
    return top == MAX - 1; // Return 1 (true) if full, otherwise 0 (false)
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1; // Return 1 (true) if empty, otherwise 0 (false)
}

// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d onto stack.\n", value);
    } else {
        stack[++top] = value; // Increment top and add value
        printf("Pushed %d onto stack.\n", value);
    }
}

// Function to display the stack contents
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack contents: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main function to demonstrate stack operations
int main() {
    // Example push operations
    push(10);
    push(20);
    push(30);
    display(); // Display stack contents

    // Attempt to push more elements
    for (int i = 40; i < 150; i += 10) {
        push(i);
    }

    display(); // Display stack contents again

    return 0;
}