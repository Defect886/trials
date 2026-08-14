#include <stdio.h>
#include <limits.h>
int main(){
    int intmin= INT_MIN;
    int intmax= INT_MAX;

    unsigned char ucharmin= 0;
     unsigned char ucharmax= UCHAR_MAX;

     printf("minimum for char is %d %o %x in decimal, octal and hexadecimal\n", ucharmin, ucharmin, ucharmin);
     printf("maximum for char is %d %o %x\n", ucharmax, ucharmax, ucharmax);

     printf("minimum for int is %d %o %x\n", intmin, intmin, intmin);
     printf("maximum for int is %d %o %x\n", intmax, intmax, intmax);

     return 0;
}