#include<stdio.h>

int main()
{
    // Fibannocci series

    int number;
    printf("Enter the number of terms: ");
    scanf("%d", &number);

    int t1=0, t2=1;
    int nextterm = t1+t2;
    printf("%d\t %d\t", t1, t2);
    for (int i = 0; i <= number-2; i++)
    {
        int t = nextterm;
        t1=t2;
        t2=nextterm;
        nextterm = t1+t2;
        printf("%d\t", t);
    }
    
    
    return 0;
}