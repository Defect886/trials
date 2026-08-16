#include <stdio.h>

int main() {
    int a[100], b[100];
    int n1, n2;

    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }

    int printed[100] = {0};   // tracks already printed values

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (a[i] == b[j]) {
                int alreadyPrinted = 0;

                for (int k = 0; k < i; k++) {
                    if (a[k] == a[i]) {
                        alreadyPrinted = 1;
                        break;
                    }
                }

                if (!alreadyPrinted) {
                    printf("%d ", a[i]);
                    printed[a[i]] = 1;   // only works if values are small/non-negative
                }
                break;
            }
        }
    }

    return 0;
}