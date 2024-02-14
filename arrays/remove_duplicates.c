#include <stdio.h>

void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            printf("%d\t", arr[i]);
        }
    }
    printf("\n");
}

void removeDuplicates(int arr[], int size) {
    int duplicate[size];

    for (int i = 0; i < size; i++) {
        duplicate[i] = 0;
    }

    int count = 0;  // Variable to keep track of non-duplicate elements in duplicate array

    for (int i = 0; i < size; i++) {
        int isDuplicate = 0;

        // Check if arr[i] is already present in the duplicate array
        for (int j = 0; j < count; j++) {
            if (duplicate[j] == arr[i]) {
                isDuplicate = 1;
                break;
            }
        }

        // If not a duplicate, add it to the duplicate array
        if (!isDuplicate) {
            duplicate[count] = arr[i];
            count++;
        }
    }

    PrintArray(duplicate, count);  
}

int main() {
    int user;
    printf("Enter the Number of elements: ");
    scanf("%d", &user);

    int arr[user];

    printf("Enter the elements: ");
    for (int i = 0; i < user; i++) {
        scanf("%d", &arr[i]);
    }

    int size = sizeof(arr) / sizeof(arr[0]);

    removeDuplicates(arr, size);

    return 0;
}
