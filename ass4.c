#include <stdio.h>
#include <string.h>
#define MAX 50
#define SIZE 100
int main()
{
    char backstack[MAX][SIZE];
    char forwardstack[MAX][SIZE];
    int BackTop = -1;
    int FrontTop = -1;
    char currentPage[SIZE] = "HOME";
    char newPage[SIZE];
    int choice;
    do
    {
        printf("\n ==== Browser Navigaton ====\n");
        printf("1.visit new page\n");
        printf("2.Back\n");
        printf("3.Forward\n");
        printf("4.Dispplay Current page\n");
        printf("5.Exit\n");
        printf("enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter page name : ");
            scanf("%s", newPage);
            if (BackTop < MAX - 1)
            {
                BackTop++;
                strcpy(backstack[BackTop], currentPage);
            }
            strcpy(currentPage, newPage);
            FrontTop = -1;
            printf("currenr page is : %s\n", currentPage);
            break;
        case 2:
            printf("===== back is working..... =======\n");
            if (BackTop == -1)
            {
                printf("no previous page is availabl\n");
            }
            else
            {
                if (FrontTop < MAX - 1)
                {
                    FrontTop++;

                    strcpy(forwardstack[FrontTop], currentPage);
                }
                strcpy(currentPage, backstack[BackTop]);
                BackTop--;
                printf("currenr page is : %s\n", currentPage);
            }
            break;
        case 3:
            printf("===== front is working..... =======\n");
            if (FrontTop == -1)
            {
                printf("no forward page is availabl\n");
            }
            else
            {
                if (BackTop < MAX - 1)
                {
                    BackTop++;
                    strcpy(backstack[BackTop], currentPage);
                }
                strcpy(currentPage, forwardstack[FrontTop]);
                FrontTop--;
                printf("currenr page is : %s\n", currentPage);
            }
            break;
        case 4:
            printf("===== showing current page =======\n");
            printf("currenr page is : %s\n", currentPage);
            break;
        case 5:
            printf("Existing...\n");
            break;
        default:
            printf("Invalid Choice\n");
        }
    } while (choice != 5);
    return 0;
}