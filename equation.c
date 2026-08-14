#include <stdio.h>
#include <math.h>

double f(double x){
    return pow(x, 5)+3*pow(x, 2)-10 ;
}

int main(){

    int i=0;
    double x0=1.0, x1=2.0;
    double x2, f0, f1;

    do{
        f0= f(x0);
        f1= f(x1);

        x2= x1 - f1*((x1-x0)/(f1-f0));

        x0=x1;
        x1=x2;

        i++;
    }while(fabs(f(x2))>1e-9 && i<=100);

    printf("%.10lf", x2);

    return 0;

}