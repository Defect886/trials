#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter which element you want to delete(the index): \n");
    int m;
    scanf("%d",&m);
    if(m<0 || m>=n){
        printf("Invalid position\n");
        return 0;
    }
    for(int i=m;i<n-1;i++){
        arr[i]=arr[i+1];
        
    }

    arr[n-1];

    for(int i=0;i<n-1;i++){
        printf("%d ",arr[i]);
    }

    return 0;
    
}