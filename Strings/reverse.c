#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    int length = strlen(str);
    char reverseString[100];

    for (int i = length - 2, j = 0; i >= 0, j < length; i--, j++)
    {   
        reverseString[j] = str[i];
    }

    reverseString[length - 1] = '\0'; 

    puts(reverseString);
    printf("- Reversed String");

    return 0;
}
