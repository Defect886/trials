#include <stdio.h>
int main(){
    int n,x,count=0;
    scanf("%d", &n);
    scanf("%d", &x);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n; i++){
        if(x==arr[i]){
            printf("Element found at %d position\n", i+1);
            count++;
        }
    }
    if(count==0){
        printf("Element not found\n");
        return 0;
    }

    printf("Total appearances is %d\n", count);
    return 0;
    
    
    
}