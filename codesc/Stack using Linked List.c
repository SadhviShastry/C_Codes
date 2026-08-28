#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void push(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Heap Overflow\n");
        return;
    }

    newNode->data = val;
    newNode->next = head;
    head = newNode;

    printf("Element %d pushed successfully\n", val);
}

void pop()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Popped element = %d\n", head->data);

    temp = head;
    head = head->next;

    free(temp);
}

void printList()
{
    struct node *temp = head;

    if (temp == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements:\n");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice, val;

    do
    {
        printf("\n------------------------------\n");
        printf("Stack using Linked List\n");
        printf("------------------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                printList();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Enter valid choice\n");
        }

    } while (choice != 4);

    return 0;
}