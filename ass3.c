#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Contact
{
    char name[50];
    double phone;
    struct Contact *next;
};
void InsertContactAtfront(struct Contact **head, char *name, double phone)
{
    struct Contact *newnode = (struct Contact *)malloc(sizeof(struct Contact));
    if (newnode == NULL)
    {
        printf("memory allocation failed");
        return;
    }
    strcpy(newnode->name, name);
    newnode->phone = phone;
    newnode->next = *head;
    *head = newnode;
}
void InsertEndOfList(struct Contact **head, char *name, double phone)
{
    struct Contact *newnode = (struct Contact *)malloc(sizeof(struct Contact));
    struct Contact *lastnode = *head;
    if (newnode == NULL)
    {
        printf("memory allocation failed");
        return;
    }
    strcpy(newnode->name, name);
    newnode->phone = phone;
    newnode->next = NULL;
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    while (lastnode->next != NULL)
    {
        lastnode = lastnode->next;
    }
    lastnode->next = newnode;
}
void deleteContact(struct Contact **head, char *target)
{
    struct Contact *temp = *head;
    struct Contact *prev = NULL;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        if (strcmp(temp->name, target) == 0)
        {
            if (prev == NULL)
            {
                *head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("Contact deleted successfully\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Contact not found\n");
}
void search(struct Contact *node, char *target)
{
    int size = 1;
    while (node->next != NULL)
    {
        node = node->next;
        size++;
        if (strcmp(node->name, target) == 0)
        {
            printf("found at pos : %d\n", size);
            printf("name : %s\n", node->name);
            printf("phone : %.0f\n", node->phone);
            return;
        }
    }
}
void display(struct Contact *node)
{
    while (node != NULL)
    {
        printf("%s,%.0f-> ", node->name, node->phone);
        node = node->next;
    }
    printf("NULL\n");
    printf("\n");
}
int main()
{
    struct Contact *head = NULL;
    InsertEndOfList(&head, "Omkar", 5645348756);
    InsertEndOfList(&head, "Piyush", 9987654321);
    InsertEndOfList(&head, "om", 9876543210);
    InsertEndOfList(&head, "kartik", 9876543210);
    InsertEndOfList(&head, "krishna", 9876543210);
    InsertEndOfList(&head, "ashish", 9876543210);

    display(head);
    search(head, "kartik");
}