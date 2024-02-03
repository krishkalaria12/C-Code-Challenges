#include<stdio.h>

int main()
{
    int a, i, j;
    scanf("%d", &a);
    int arr[a][a];
    int arr2[a][a];

    // Input the matrix
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < a; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Reverse the diagonals
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < a; j++)
        {
            if (i == j || i + j == a - 1)
            {
                arr2[i][j] = arr[a - i - 1][a - j - 1];
            }
            else
            {
                arr2[i][j] = arr[i][j];
            }
        }
    }

    // Print the reversed matrix
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < a; j++)
        {
            if (j != a - 1)
            {
                printf("%d   ", arr2[i][j]);
            }
            else
            {
                printf("%d", arr2[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
