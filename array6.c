#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int size=0;
    for(int i=0; i<n; i++){
        int found=0;
        for(int j=0; j<size; j++){
            if(arr[j]==arr[i]){
                found=1;
                break;
            }

        }

        if (!found){
            arr[size]=arr[i];
            size++;
        }
        }
        
    
    
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}