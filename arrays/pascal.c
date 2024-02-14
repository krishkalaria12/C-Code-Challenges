#include<stdio.h>

int main()
{
    // Pascal Traingle

    int number;
    printf("enter the number: ");
    scanf("%d", &number);

    for (int line = 1; line <= number; line++) { 
        for (int space = 1; space <= number - line; space++) 
            printf("  "); 

        int coef = 1; 
        for (int i = 1; i <= line; i++) { 
            printf("%4d", coef); 
            coef = coef * (line - i) / i; 
        } 
        printf("\n"); 
    } 
    
    return 0;
}