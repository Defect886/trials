#include <stdio.h>
double MPH(int rpm, int radi){
    double mph;
    mph= (3.14159*(radi/100.0)*rpm*3600)/(30*1609.344);
    return mph;
}
int main(){
    int rpm, radi;
    double mph;
    scanf("%d %d", &rpm, &radi);
    double result= MPH(rpm, radi);
    printf("%.10lf", result);
}