#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TABLE_SIZE 10
typedef struct
{
    int bookID;
    bool isOccupied;
    bool isDeleted;
} HashNode;
HashNode hashTable[TABLE_SIZE];
void initTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i].bookID = -1;
        hashTable[i].isOccupied = false;
        hashTable[i].isDeleted = false;
    }
}
int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void insertBook(int bookID)
{
    int hashIndex = hashFunction(bookID);
    int originalIndex = hashIndex;
    int i = 0;
    while (hashTable[hashIndex].isOccupied && hashTable[hashIndex].bookID != bookID)
    {
        i++;
        hashIndex = (originalIndex + i) % TABLE_SIZE;

        if (hashIndex == originalIndex)
        {
            printf("Error: Hash table is full. Could not insert Book ID %d.\n", bookID);
            return;
        }
    }
    hashTable[hashIndex].bookID = bookID;
    hashTable[hashIndex].isOccupied = true;
    hashTable[hashIndex].isDeleted = false;
    printf("Inserted Book ID %d at index %d.\n", bookID, hashIndex);
}

int searchBook(int bookID)
{
    int hashIndex = hashFunction(bookID);
    int originalIndex = hashIndex;
    int i = 0;
    while (hashTable[hashIndex].isOccupied || hashTable[hashIndex].isDeleted)
    {
        if (hashTable[hashIndex].isOccupied && hashTable[hashIndex].bookID == bookID)
        {
            return hashIndex;
        }
        i++;
        hashIndex = (originalIndex + i) % TABLE_SIZE;
        if (hashIndex == originalIndex)
        {
            break;
        }
    }
    return -1;
}

void displayTable()
{
    printf("\n— Library Hash Table —\n");
    printf("Index\tBook ID\t\tStatus\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("%d\t", i);
        if (hashTable[i].isOccupied)
        {
            printf("%d\t\tOccupied\n", hashTable[i].bookID);
        }
        else if (hashTable[i].isDeleted)
        {
            printf("-\t\tDeleted\n");
        }
        else
        {
            printf("-\t\tEmpty\n");
        }
    }
    printf("--------------------------\n");
}

int main()
{
    initTable();
    insertBook(101);
    insertBook(111);
    insertBook(203);
    insertBook(55);
    insertBook(45);
    displayTable();

    int searchID = 111;
    int pos = searchBook(searchID);
    if (pos != -1)
    {
        printf("\nBook ID %d found at index %d.\n", searchID, pos);
    }
    else
    {
        printf("\nBook ID %d not found in the library.\n", searchID);
    }

    searchID = 999;
    pos = searchBook(searchID);
    if (pos != -1)
    {
        printf("Book ID %d found at index %d.\n", searchID, pos);
    }
    else
    {
        printf("Book ID %d not found in the library.\n", searchID);
    }
    return 0;
}