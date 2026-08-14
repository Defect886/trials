#include <stdio.h>

double sum(int n, double a, double d){

    for(int i=0; i<n; i++){
        double t= a+ i*d;
        if (i==0)
        printf("%.6g",t);
        
        else 
        printf("+%.6g", t);
    }

    double s= (n/2.0)*(2*a+(n-1)*d);
    return s;
}

int main(){
    int n;
    double a, d, s;
     
    printf("Enter first term:\n");
    scanf("%lf", &a);

    printf("Enter common difference:\n");
    scanf("%lf", &d);

    printf("Enter number of terms:\n");
    scanf("%d", &n);

    printf("=%.6g", sum(n, a, d));
    
    return 0;
}