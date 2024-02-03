#include<stdio.h>

int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    int arr[a][b];
    int arr2[b][a]; 

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
        {
            arr2[i][j] = arr[j][i];
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
