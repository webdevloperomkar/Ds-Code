#include <stdio.h>
#include <string.h>
#define MAX 5
typedef struct
{
    int patientid;
    int arrivaltime;
} patient;
int main()
{
    patient queue[MAX];
    int front = -1;
    int rare = -1;
    int choice;
    do
    {
        printf("\n ==== hospital managment ====\n");
        printf("1.Add Patient\n");
        printf("2.Attend Patient\n");
        printf("3.view Patient\n");
        printf("4. check queue empty\n");
        printf("5.Exit\n");
        printf("enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (rare == MAX - 1)
            {
                printf("queue is full");
            }
            else
            {
                if (front == -1)
                {
                    front = 0;
                }
                rare++;
                printf("enter your id : ");
                scanf("%d", &queue[rare].patientid);
                printf("enter your arrival time : ");
                scanf("%d", &queue[rare].arrivaltime);
                printf("patient added successfully");
            }
            break;
        case 2:
            if (front == -1)
            {

                printf("no patient is available for removing\n");
            }
            front++;
            printf("removing patient successfully\n");
            break;
        case 3:
            if (front == -1)
            {
                printf("no patient is available for display\n");
            }
            for (int i = front; i <= rare; i++)
            {
                printf("patient id is %d and patient arrival time is%d\n", queue[i].patientid, queue[i].arrivaltime);
            }
            break;
        case 4:
            if (front == -1)
            {
                printf("queue is empty\n");
            }
            else
            {
                printf("queue is not empty\n");
            }
            break;
        case 5:
            printf("Exiting program.......\n");
            break;
        }
    } while (choice != 5);
}