#include<stdio.h>

void mode(int arr[], int size) {
    int element, counter=0;

    for (int i = 0; i < size; i++)
    {
        int ctr=0;
        for (int j = i+1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                ctr++;
            }
        }

        if (counter < ctr)
        {
            counter = ctr;
            element = arr[i];
        }
    }

    printf("%d is the mode in the elements", element);
}

int main()
{
    int user;
    printf("Enter the Number of elements: ");
    scanf("%d", &user);

    int arr[user];

    for (int i = 0; i < user; i++) {
        printf("Enter the element %d: ", i);
        scanf("%d", &arr[i]);
    }

    int size = sizeof(arr) / sizeof(arr[0]);

    mode(arr, size);

    return 0;
}