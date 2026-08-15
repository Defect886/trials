#include <stdio.h>
int main(){
    int n, temp=0, temp1=0;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    for(int i=0; i<n; i++){

        
        if(arr[i]==0 && i+1 < n && arr[i+1]==0){
            int j=i+1;
            while(j < n && arr[j]==0){
                j++;
            }
            
            if(j < n){
                int temp1=arr[j];
                arr[j]=arr[i];
                arr[i]=temp1;
            }
        }
        else if(arr[i]==0 && i+1 < n){
            int temp=arr[i+1];
            arr[i+1]=arr[i];
            arr[i]=temp;
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}