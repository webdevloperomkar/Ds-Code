#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int roll;
    struct Node *left;
    struct Node *right;
};
// Create New Node
struct Node *createNode(int roll)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newnode->roll = roll;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
// Insert Student Record
struct Node *insert(struct Node *root, int roll)
{
    if (root == NULL)
    {
        return createNode(roll);
    }
    if (roll < root->roll)
    {
        root->left = insert(root->left, roll);
    }
    else if (roll > root->roll)
    {
        root->right = insert(root->right, roll);
    }
    else
    {
        printf("Roll number already exists!\n");
    }
    return root;
}
// Search Student Record
void search(struct Node *root, int roll)
{

    if (root == NULL)
    {
        printf("Student record not found!\n");
        return;
    }
    if (root->roll == roll)
    {
        printf("Student found!\n");
        printf("Roll Number: %d\n", root->roll);
    }
    else if (roll < root->roll)
    {
        search(root->left, roll);
    }
    else
    {
        search(root->right, roll);
    }
}
// Find Minimum Value
struct Node *findMin(struct Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
// Delete Student Record
struct Node *deleteNode(struct Node *root, int roll, int *deleted)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (roll < root->roll)
    {
        root->left = deleteNode(root->left, roll, deleted);
    }
    else if (roll > root->roll)
    {
        root->right = deleteNode(root->right, roll, deleted);
    }
    else
    {
        *deleted = 1;
        // Case 1: No Child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // Case 2: One Child
        else if (root->left == NULL)
        {
            struct Node *temp = root->right;

            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two Children
        struct Node *temp = findMin(root->right);
        root->roll = temp->roll;
        int dummy = 0;
        root->right = deleteNode(root->right, temp->roll, &dummy);
    }
    return root;
}
// Inorder Traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->roll);
        inorder(root->right);
    }
}
// Preorder Traversal
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->roll);
        preorder(root->left);
        preorder(root->right);
    }
}
// Postorder Traversal
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);

        printf("%d\t", root->roll);
    }
}
// Free Memory
void freeTree(struct Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
// Main Function
int main()
{
    struct Node *root = NULL;
    int choice, roll;
    do
    {
        printf("\n===== BINARY SEARCH TREE MENU =====\n");
        printf("1. Add Student Record\n");
        printf("2. Delete Student Record\n");
        printf("3. Search Student Record\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter Roll Number: ");
            scanf("%d", &roll);
            root = insert(root, roll);
            break;
        }
        case 2:
        {
            int deleted = 0;
            printf("Enter Roll Number to Delete: ");
            scanf("%d", &roll);

            root = deleteNode(root, roll, &deleted);
            if (deleted)
            {
                printf("Student record deleted successfully!\n");
            }
            else
            {
                printf("Student record not found!\n");
            }
            break;
        }
        case 3:
        {
            printf("Enter Roll Number to Search: ");
            scanf("%d", &roll);
            search(root, roll);
            break;
        }
        case 4:
        {
            printf("Inorder Traversal:\n");
            inorder(root);
            printf("\n");
            break;
        }
        case 5:
        {
            printf("Preorder Traversal:\n");
            preorder(root);
            printf("\n");
            break;
        }
        case 6:
        {
            printf("Postorder Traversal:\n");
            postorder(root);
            printf("\n");
            break;
        }
        case 7:
            printf("Exiting Program...\n");
            break;
        default:

            printf("Invalid Choice!\n");
        }
    } while (choice != 7);
    freeTree(root);
    return 0;
}