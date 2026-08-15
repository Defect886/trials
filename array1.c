#include <stdio.h>
int main() {
int n,max, temp, s=0, avg;
scanf("%d", &n);
int array[n];

for (int i = 0; i < n; i++) {
  scanf("%d", &array[i]);
}

for (int i = 0; i < n; i++) {
    s+= array[i];
    if(array[i] >max){
        max = array[i];
    }

    temp = array[0];
    if (array[i] < temp) {
        temp = array[i];
    }
    
    

}
avg= s/n;

printf("Sum: %d\n", s);
printf("Max: %d\n", max);
printf("Average: %d\n", avg);
printf("Min: %d\n", temp);

return 0;
}