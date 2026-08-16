#include <stdio.h>

int main() {
    int n, m, x;

    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position(index) and value: ");
    scanf("%d %d", &m, &x);

    int newArr[n + 1];
    if(m<0 || m>n){
        printf("Invalid position\n");
        return 0;
    }


    for(int i=0; i<m; i++){
        newArr[i]=arr[i];
    }

    newArr[m]=x;

    for(int i=m; i<n; i++){
        newArr[i+1]=arr[i];
    }

    printf("Array after insertion: ");
    for(int i=0; i<n+1; i++){
        printf("%d ", newArr[i]);
    }
    printf("\n");
    return 0;
}