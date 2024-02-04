#include<stdio.h>

int main() {
    int user;
    printf("Enter the Number of Element: ");
    scanf("%d", &user);
    int arr[user];

    for (int i = 0; i < user; i++) {
        scanf("%d", &arr[i]);
    }

    int maxDiff = 0, indexDiff = 0;

    for (int i = 0; i < user - 1; i++) {
        for (int j = i + 1; j < user; j++) {
            if (arr[j] >= arr[i]) {
                int diff = j - i;
                if (diff > maxDiff) {
                    maxDiff = diff;
                    indexDiff = i;
                }
            }
        }
    }

    printf("The maximum difference of indices (j - i) is %d, achieved for the pair (%d, %d) with values %d and %d.\n",
        maxDiff, indexDiff, indexDiff + maxDiff, arr[indexDiff], arr[indexDiff + maxDiff]);

    return 0;
}
