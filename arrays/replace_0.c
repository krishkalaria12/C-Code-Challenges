#include<stdio.h>

int main()
{   
    int a; // 2304501
    int b = 0;
    scanf("%d", &a);

    int multiplier = 1; // To keep track of the position value

    while (a != 0)
    {
        int n = a % 10;
        if (n == 0)
        {
            n = 1;
        }
        
        b = b + n * multiplier;
        a = a / 10;
        multiplier *= 10;
    }
    
    printf("%d\n", b);

    return 0;
}
