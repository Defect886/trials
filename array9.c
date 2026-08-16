#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k;
    printf("Enter the number of times you want to rotate the array: ");
    scanf("%d",&k);
    int temp[k];
    for(int i=0; i<k; i++){

        temp[i] = arr[i];
    }

    for(int i=k; i<n; i++){
        arr[i-k]=arr[i];
    }

    for(int i=0; i<k; i++){
        arr[n-k+i]=temp[i];
    }

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}