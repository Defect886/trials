#include <stdio.h>
int main(){
    int i,n;
    double SUMxf=0, SUMf=0, x, f;

    printf("Enter the number of terms:");
    scanf("%d", &n);

    if(n==0){
        printf("X(avg) is 0\n");
    }

    for(i=1;i<=n;i++){
        printf("Enter x:\n");
        scanf("%lf", &x);

        printf("Enter f(weight):\n ");
        scanf("%lf", &f);

        SUMxf=SUMxf+x*f;
        SUMf=SUMf+f;
    }

    if(n<0){
        printf("Cant be less than Zero");
    }

    double Xweight=SUMxf/SUMf;

    printf("%lf", Xweight);

    return 0;
}