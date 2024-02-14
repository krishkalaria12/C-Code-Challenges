#include<stdio.h>

int main()
{   
    int number, counter = 0;
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
        for (int j = i+1; j < number; j++)
        {
            if (arr[j] == arr[i])
            {
                counter+=1;
            }
            
        }
    }

    printf("Number of unique elements in the array: %d\n", number-counter);
    
    return 0;
}