#include <stdio.h>

int main() {
    int number, frequency;
    printf("Enter the number: ");
    scanf("%d", &number);

    int arr[number];

    for (int i = 0; i < number; i++) {
        printf("Enter the value: ");
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < number; i++) {
        frequency = 1;
        for (int j = i + 1; j < number; j++) {
            if (arr[j] == arr[i]) {
                frequency++;
            }
            printf("Frequency of %d is %d\n", arr[i], frequency);
        }
    }

    return 0;
}
