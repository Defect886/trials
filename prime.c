#include <stdio.h>
int isPrime(int n, int i){
    if(n==2){
    return 1;}

    for(i=2;i<=n-1;i++){
        if(n%i==0){
            return 0;
        }
    }

    return 1;
}

int main(){
    int n, i=1;
    printf("Enter a Number:");
    scanf("%d", &n);

    printf("%s", isPrime(n, i) ? "Prime":"Not a Prime");

    return 0;
}