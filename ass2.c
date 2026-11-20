#include <stdio.h>
int main()
{
    int roll[100], n, i, j, temp;
    printf("Enter the number of student : ");
    scanf("%d", &n);
    printf("Enter %d roll number : \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &roll[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        int found = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (roll[j] > roll[j + 1])
            {
                found = 1;
                temp = roll[j];
                roll[j] = roll[j + 1];
                roll[j + 1] = temp;
            }
        }
        if (!found)
        {
            printf("sorted\n");
            break;
        }
        for (j = 0; j < n; j++)
        {
            printf(" %d", roll[j]);
        }
        printf("\n");
    }
    printf("sorted array\n");
    for (j = 0; j < n; j++)
    {
        printf("%d ", roll[j]);
    }
}