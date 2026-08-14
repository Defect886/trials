#include <stdio.h>
int main(){
    int n;
    printf("Enter your number in any format:");
    scanf("%i", &n);

    printf("In decimal Output is %d\n", n);
    printf("In octal Output is %o\n", n);
    printf("In hexadecimal Output is %x\n", n);

    return 0;
}