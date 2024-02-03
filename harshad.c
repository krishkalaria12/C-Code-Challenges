#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int sum = 0;
    int temp = num;

    while (temp > 0) {
        int digit = temp % 10;
        sum += digit;
        temp /= 10;
    }

    if (num % sum == 0) {
        printf("%d is a Harshad number.\n", num);
    } else {
        printf("%d is not a Harshad number.\n", num);
    }

    return 0;
}
