#include <stdio.h>
int main(){
    int n;
    printf("Enter a Number:");
    scanf("%d", &n);
    int s=0, last, rem;
    last=n;
    while(last!=0){
        rem=last%10;
        s= s*10 + rem;
        last/=10;
    }

    printf("%d", s);
    return 0;
}