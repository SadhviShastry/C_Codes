#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

// Check if stack is empty
bool isEmpty() {
    return top == -1;
}

// Check if stack is full
bool isFull() {
    return top == MAX_SIZE - 1;
}

// Push element
void push(int item) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
    printf("%d pushed successfully\n", item);
}

// Pop element
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Peek element
int peek() {
    if (isEmpty()) {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack[top];
}

// Show stack
void show() {
    if (isEmpty()) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

// Main
int main() {
    int ch, data;
    printf("===========================\n");
    printf("Stack Operationsusing an array\n");

    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Show\n5. Exit");
        printf("\nEnter your choice: ");

        if (scanf("%d", &ch) != 1) {
            printf("Invalid input!\n");
            return 0;
        }

        switch (ch) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                data = pop();
                if (data != -1)
                    printf("Popped: %d\n", data);
                break;

            case 3:
                data = peek();
                if (data != -1)
                    printf("Top element: %d\n", data);
                break;

            case 4:
                show();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Enter valid choice\n");
        }

    } while (ch != 5);
    printf("===========================\n");

    return 0;
}

