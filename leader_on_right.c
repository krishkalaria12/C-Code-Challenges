#include<stdio.h>

int main()
{
    int user;
    scanf("%d", &user);
    int arr[user];

    for (int i = 0; i < user; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < user; i++)
    {
        int j;
        for (j = i+1; j < user; j++)
        {
            if (arr[i] < arr[j])
            {
                break;
            }
        }
        if (j == user) {
            printf("%d\t", arr[i]);
        }
    }
    
    return 0;
}
