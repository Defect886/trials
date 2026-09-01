#include <stdio.h>
#include <stdlib.h>

int *typeinput(int n){
    int *a;
    a=(int *)malloc(n*sizeof(int));
    return a;
}

int **marks(int m, int n){
    int **a;
    a=(int **)malloc(n*sizeof(int *));
    for(int i=0; i<n; i++){
        a[i]=(int *)malloc(m*sizeof(int));
    }
    return a;
}


void sortStudents(int *total, int *roll, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i; j<n-1; j++){
            if(total[j]>total[j+1]){
                int temp=total[j];
                total[j]=total[j+1];
                total[j+1]=temp;

                int tempRoll = roll[j];
                roll[j] = roll[j + 1];
                roll[j + 1] = tempRoll;
            }
        }
    }

}

int main(){
    int n, m;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    printf("Enter the number of subjects: ");
    scanf("%d", &m);

    int *roll=typeinput(n);
    int *total=typeinput(n);

    int **mark=marks(m, n);

    for(int i=0; i<n; i++){
        printf("Enter roll number for student %d: ", i + 1);
        scanf("%d", &roll[i]);
        total[i]=0;
        printf("Enter marks for %d subjects for student %d:\n", m, i + 1);
        for (int j = 0; j < m; j++) {
            scanf("%d", &mark[i][j]);
            total[i] += mark[i][j]; 
    }
}
    sortStudents(total, roll, n);

    printf("\nRoll Number | Total Marks\n");
    printf("--------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%11d | %11d\n", roll[i], total[i]);
    }

    for (int i = 0; i < n; i++) {
        free(mark[i]);
    }
    free(mark);
    free(roll);
    free(total);

    return 0;


}