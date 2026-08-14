#include <stdio.h>
int main(){
    int i,n,x=1;

    printf("Enter the Number:");
    scanf("%d", &n);

    for(i=1;i<=n;i++){
        x=x*i;
    }
    printf("%d", x);
    return 0;

}