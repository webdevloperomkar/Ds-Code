#include <stdio.h>
#include <stdbool.h>
int main()
{
    int arr[100];
    int n = 0;
    int mid;
    int pos;
    int choice;
    int val;
    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Insert Marks\n");
        printf("2. Delete Mark\n");
        printf("3. Display Marks\n");
        printf("4. Linear Search\n");
        printf("5. Sort and Binary Search\n");
        printf("6. Exit\n");

        printf("enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number of student : ");
            scanf("%d", &n);
            printf("Enter marks of student : \n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            break;
        case 2:
            printf("Enter position to delete : ");
            scanf("%d", &pos);
            if (pos < 1 || pos > n)
            {
                printf("invalid Position");
            }
            for (int i = pos - 1; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            n--;
            printf("======== deletation successfully =======");
            break;
        case 3:
            if (n == 0)
            {
                printf("====== No Record Found! =====");
            }

            else
            {
                printf("====== marks displayed ======\n");
                for (int i = 0; i < n; i++)
                {
                    printf("%d\t", arr[i]);
                }
            }
            break;
        case 4:

            printf("Enter Marks to Serch : ");
            scanf("%d", &val);
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == val)
                {
                    printf("marks fount at position : %d", i + 1);
                }
            }
            break;
        case 5:
            for (int i = 0; i < n - 1; i++)
            {
                int j;
                for (j = 0; j < n - i - 1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            printf("sortde marks\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            int value;
            printf("Enter Marks to Serch : ");
            scanf("%d", &value);
            int low = 0;
            int high = n - 1;
            int found = 0;
            while (low <= high)
            {
                mid = (low + high) / 2;
                if (arr[mid] == value)
                {
                    printf("marks found at position %d", mid + 1);
                    found = 1;
                    break;
                }
                else if (arr[mid] < value)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            if (!found)
            {
                printf("marks not found\n");
                break;
            }
        case 6:
            printf("Exiting program");
            break;
        default:
            printf("invalid Choice\n");
        }
    } while (choice != 6);
}