#include <stdio.h>
#include <math.h>
int gcd(int x, int y){
    if (y==0) return x;
    else
    return gcd(y, x%y);
}


int main(){
    int x,y;
    scanf("%d %d", &x, &y);
    printf("Sum is %d\n", x+y);
    printf("Diff is %d\n", x-y);
    printf("Product is %d\n", x*y);
    printf("Quotient is %d\n", x/y);
    printf("Remainder is %d\n", x%y);


    int g= gcd(x, y);
    int numerator= x/g;
    int denominator= y/g;
    printf("%d/%d is %d/%d", x,y, numerator, denominator);
    
    return 0;
}
