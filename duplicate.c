#include<stdio.h>

int main()
{
    int number, counter = 0, frequency = 0;
    printf("Enter the number: ");
    scanf("%d", &number);

    int arr[number];

    for (int i = 0; i < number; i++)
    {
        printf("Enter the value: ");
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < number; i++)
    {
        for (int j = i + 1; j < number; j++)
        {
            if (arr[i] == arr[j])
            {
                frequency += 1;
            }
        }
        if (frequency > 0)
        {
            counter += 1;
            printf("Number of duplicates of %d is %d\n", arr[i], frequency + 1);
            break;
        }
        frequency = 0;
    }

    printf("\nNumber of Duplicate Items are: %d\n", counter);
    return 0;
}
