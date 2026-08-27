#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

// Create Node
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert
struct Node* insert(struct Node* root, int value)
{
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find Minimum
struct Node* findMin(struct Node* root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}

// Delete
struct Node* deleteNode(struct Node* root, int value)
{
    if(root == NULL)
        return NULL;

    if(value < root->data)
        root->left = deleteNode(root->left, value);
    else if(value > root->data)
        root->right = deleteNode(root->right, value);
    else
    {
        // No child
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // One child
        else if(root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder
void inorder(struct Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder
void preorder(struct Node* root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder
void postorder(struct Node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Search
void search(struct Node* root, int key)
{
    if(root == NULL)
    {
        printf("Element not found!\n");
        return;
    }

    if(root->data == key)
    {
        printf("Element found!\n");
        return;
    }

    if(key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

// Display Tree
void displayTree(struct Node* root, int space)
{
    if(root == NULL)
        return;

    space += 5;

    displayTree(root->right, space);

    printf("\n");
    for(int i=5;i<space;i++)
        printf(" ");

    printf("%d\n", root->data);

    displayTree(root->left, space);
}

// Main
int main()
{
    struct Node* root = NULL;
    int choice, value;

    while(1)
    {
        printf("\n========== Binary Search Tree ==========\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Display Tree\n");
        printf("7. Search\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                root = insert(root,value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d",&value);
                root = deleteNode(root,value);
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("\nTree Structure:\n");
                displayTree(root,0);
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d",&value);
                search(root,value);
                break;

            case 8:
                printf("Program Ended.\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}