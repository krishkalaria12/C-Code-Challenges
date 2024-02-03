#include<stdio.h>

int main()
{
    // Perfect Number

    int number,remainder;
    printf("Enter the number: ");
    scanf("%d", &number);
    int count=0;

    for(int j = 1; j < number; j++)  {
        remainder = number % j;
        if (remainder == 0)  {
            count += j;
        }
    }
    
    if (count == number)
    {
        printf("Number is a perfect number");
    }else {
        printf("Number is not a perfect number");
    }
    
    

    return 0;
}