#include <stdio.h>
int main(){
    int n, cars, buses, motorcycles;
    int l=0,m=0,h=0,s=0, load=0, x=0, y, c=0;

    printf("Enter your time slot:\n");
    scanf("%d", &n);

    if(n<2 || n>10){
        printf("Error. Time slots should be from 2 to 10\n");
    }

    else{

    printf("Enter the Number of Cars, Buses and Motorcycles %d times in Order:\n", n);

    for(int i=0; i<n; i++){
        
        
        scanf("%d %d %d", &cars, &buses, &motorcycles);
    

        if(cars<=0 || cars>=100 || buses<=0 || buses>=30 || motorcycles<=0 || motorcycles>=100){
            printf("The number of vehicles can't be less than Zero or exceed the maximum Number.\n");
            break;
        }

        int newload= cars+ buses*3 + motorcycles;

        if(newload>=0 && newload<30){
            while(l<10){
                printf("Slot %d: LIGHT - LOAD %d\n", i+1, newload);
                y=0;
                l++;
                break;
            }
        }

        else if(newload>=30 && newload<60){
            while(m<10){
                printf("Slot %d: MODERATE - LOAD %d\n", i+1, newload);
                y=2;
                m++;
                break;
            }
        }

        else if(newload>=60 && newload<89){
            while(h<10){
                printf("Slot %d: HEAVY - LOAD %d\n", i+1, newload);
                y=5;
                h++;
                break;
            }
        }

        else if(newload>=90){
            while(s<10){
                printf("Slot %d: SEVERE - LOAD %d\n", i+1, newload);
                y=8;
                s++;
                break;
            }
        }


        
        if(x<newload){
            x=newload;
        }

        c=c+y;
        load=newload+ load;
    }


    
    printf("Total Load: %d\n", load);
    printf("Highest Load: %d\n", x);

    printf("Slot counts: LIGHT %d, MODERATE %d, HEAVY %d, SEVERE %d\n", l, m, h, s);

    printf("Congestion Points: %d\n", c);

    if(s==1 || s>1)
        printf("Road Status: CRITICAL\n");

    else if(h==2 || h>2)
        printf("Road Status: CONGESTED\n");

    else if(m==2 || m>2)
        printf("Road Status: BUSY\n");

    else
        printf("Road Status: NORMAL\n");
}


    return 0;

}