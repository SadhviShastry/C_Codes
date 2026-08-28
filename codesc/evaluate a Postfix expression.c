#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int top;
    int arr[MAX];
} Stack;

void push(Stack *s, int val) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = val;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    return s->arr[s->top--];
}

bool isOperator(char *token) {
    return strcmp(token, "+") == 0 ||
           strcmp(token, "-") == 0 ||
           strcmp(token, "*") == 0 ||
           strcmp(token, "/") == 0 ||
           strcmp(token, "^") == 0;
}

int floorDiv(int a, int b) {
    if (a * b < 0 && a % b != 0)
        return (a / b) - 1;

    return a / b;
}

int evaluatePostfix(char **arr, int n) {

    Stack s = {-1};

    for (int i = 0; i < n; i++) {

        if (isdigit(arr[i][0]) ||
            (strlen(arr[i]) > 1 && arr[i][0] == '-')) {

            push(&s, atoi(arr[i]));
        }

        else if (isOperator(arr[i])) {

            int val1 = pop(&s);
            int val2 = pop(&s);

            if (strcmp(arr[i], "+") == 0)
                push(&s, val2 + val1);

            else if (strcmp(arr[i], "-") == 0)
                push(&s, val2 - val1);

            else if (strcmp(arr[i], "*") == 0)
                push(&s, val2 * val1);

            else if (strcmp(arr[i], "/") == 0)
                push(&s, floorDiv(val2, val1));

            else if (strcmp(arr[i], "^") == 0)
                push(&s, (int)pow(val2, val1));
        }
    }

    return pop(&s);
}

int main() {

    char input[MAX];
    char *arr[MAX];
    int n = 0;
    printf("================\n");
    printf("Evaluate a Postfix expression\n");
    printf("Enter postfix expression: ");
    fgets(input, MAX, stdin);

    char *token = strtok(input, " \n");

    while (token != NULL) {
        arr[n++] = token;
        token = strtok(NULL, " \n");
    }

    printf("Result: %d\n", evaluatePostfix(arr, n));
    printf("================\n");
    return 0;
}