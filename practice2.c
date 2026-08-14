#include <stdio.h>
#include <math.h>
int date( int y, int m, int d){
    int s;
    int const yc=365, mc=30;
    s= y*yc + m*mc + d;
    return s;
}

int main(){
    int y, m, d, s, yc, mc;
    printf("Enter your Year, Month and Day\n:");
    scanf("%d %d %d", &y, &m, &d);
    printf("number of days: %d\n", date(y, m, d));
    int s1= date(y, m, d);

    printf("Enter your date for the second time\n:");
    scanf("%d %d %d", &y, &m, &d);
    printf("number of days: %d\n", date(y, m, d));
    int s2= date(y, m, d);

    printf("Difference is %d\n", s1-s2);

    int s3=s1-s2;
    
    int s4=s3%365; 
    int s5=s3/365;
    
    
    int s6= s4/30;
    int s7= s4%30;

    printf("Year, Month, Day: %d %d %d", s5, s6, s7 );
    return 0;

}