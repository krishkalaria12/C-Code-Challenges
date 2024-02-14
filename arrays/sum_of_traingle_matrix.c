#include<stdio.h>

int main()
{
    int a, i, j,sum=0;
    scanf("%d", &a);
    int arr[a][a];

    for (i = 0; i < a; i++)
    {
        for (j = 0; j < a; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (i = 0; i < a; i++)
    {
        for (j = 0; j <= i; j++)
        {
            sum += arr[i][j];
        }
    }

    printf("%d\n", sum);

    return 0;
}