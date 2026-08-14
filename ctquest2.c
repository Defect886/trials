#include <stdio.h>
#include <math.h>
int main(){
    double a,b,c,x,d;

    printf("Enter the three coeffecients a b c in order:");
    scanf("%lf %lf %lf", &a, &b, &c);

    d=pow(b, 2)- 4* a* c;
    
    if(d<0){
        printf("Error discriminant is negative.");
    }

    if(d>0 || d==0){
        x=(-b+sqrt(d))/2*a;
        printf("Taking + sign answer is %lf\n", x);

        x=(-b-sqrt(d))/2*a;
        printf("Taking - sign answer is %.3lf\n", x);
    }

    return 0;
}