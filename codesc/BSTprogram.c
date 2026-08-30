#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left, *right;
};

struct Node *newNodeCreate(int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->key = value;
    temp->left = temp->right = NULL;

    return temp;
}

struct Node *searchNode(struct Node *root, int target)
{
    if (root == NULL || root->key == target)
        return root;

    if (root->key < target)
        return searchNode(root->right, target);

    return searchNode(root->left, target);
}

struct Node *insertNode(struct Node *node, int value)
{
    if (node == NULL)
        return newNodeCreate(value);

    if (value < node->key)
        node->left = insertNode(node->left, value);

    else if (value > node->key)
        node->right = insertNode(node->right, value);

    return node;
}

void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->key);
    }
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf(" %d ", root->key);
        inOrder(root->right);
    }
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

struct Node *findMin(struct Node *root)
{
    if (root == NULL)
        return NULL;

    else if (root->left != NULL)
        return findMin(root->left);

    return root;
}

struct Node *delete(struct Node *root, int x)
{
    if (root == NULL)
        return NULL;

    if (x > root->key)
        root->right = delete(root->right, x);

    else if (x < root->key)
        root->left = delete(root->left, x);

    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        else if (root->left == NULL || root->right == NULL)
        {
            struct Node *temp;

            if (root->left == NULL)
                temp = root->right;
            else
                temp = root->left;

            free(root);
            return temp;
        }

        else
        {
            struct Node *temp = findMin(root->right);

            root->key = temp->key;

            root->right = delete(root->right, temp->key);
        }
    }

    return root;
}

int main()
{
    struct Node *root = NULL;
    int n, value, search, del;

    printf("========================================\n");
    printf("       BINARY SEARCH TREE PROGRAM\n");
    printf("========================================\n");

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("\nInorder Traversal: ");
    inOrder(root);

    printf("\nPreorder Traversal: ");
    preOrder(root);

    printf("\nPostorder Traversal: ");
    postOrder(root);

    printf("\n\nEnter value to search: ");
    scanf("%d", &search);

    if (searchNode(root, search) != NULL)
        printf("%d found in BST\n", search);
    else
        printf("%d not found in BST\n", search);

    printf("\nEnter value to delete: ");
    scanf("%d", &del);

    root = delete(root, del);

    printf("After Delete: ");
    inOrder(root);

    printf("\n");

    return 0;
}