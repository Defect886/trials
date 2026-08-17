#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int size= n;    
    int pass=0;
    int countp=0;

    for(int pass=0;pass<n-1;pass++){
        for(int i=0; i<n-1-pass;i++){
            if(arr[i]>arr[i+1]){
                int temp= arr[i];
                arr[i]= arr[i+1];
                arr[i+1]= temp;
            }
        }

        countp++;

    }

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\nNumber of passes: %d", countp);
    return 0;
}