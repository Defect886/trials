#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int sl= arr[0];

    for(int i=0; i<n; i++){
        if(arr[i]<max && arr[i]>sl){
            sl = arr[i];
        }
    }

    if(sl==arr[0]){
        printf("No second largest element\n");
    }
    else{
        printf("Second largest element is %d\n", sl);
    }
    printf("Largest element is %d\n", max);
    return 0;
}