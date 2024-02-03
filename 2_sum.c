#include<stdio.h>

int main()
{
    int user,sum;
    scanf("%d", &user);
    scanf("%d", &sum);
    int arr[user];

    for (int i = 0; i < user; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < user; i++)
    {
        for (int j = i+1; j < user; j++)
        {
            if (sum==arr[i]+arr[j])
            {
                printf("%d %d", i, j);
            }
        }
        
    }


    return 0;
}