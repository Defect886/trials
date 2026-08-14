#include <stdio.h>
#include <stdlib.h>

void sortStudents(int *roll, int *total, int n){
    for(int i=0; i<n-1;++i){
        for(int j=0; j<n-i-1;j++){
            if(*(total+j)>*(total+j+1)){
                int temptotal=*(total+j+1);
                *(total+j+1)=*(total+j);
                *(total+j)=temptotal;

                int temproll=*(roll+j+1);
                *(roll+j+1)=*(roll+j);
                *(roll+j)=temproll;
            }
        }
    }
}

int main(){
    int n, m;;


    printf("Enter the number of students:\n");
    scanf("%d", &n);
    printf("Enter the number of Subjects:\n");
    scanf("%d", &m);

    int *roll=(int *) malloc(n*sizeof(int));
    int *total=(int *) malloc(n*sizeof(int));

    int **marks=(int **)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        *(marks+i)=(int *) malloc(m*sizeof(int));
    }

    for(int i=0; i<n; i++){
        printf("Enter your roll for %d student\n", i+1);
        scanf("%d", (roll+i));
         
        *(total+i)=0;

        for(int j=0; j<m; j++){
            
            printf("Enter your mark for % d subbject for %d student:\n", j+1, i+1);
            scanf("%d", *(marks+i)+j);

            *(total+i)+=*(*(marks+i)+j);
        }
    }

        sortStudents(roll, total, n);

        printf("\nRoll || Total marks\n");
        printf("\n---------------\n");
        for(int i=0; i<n; i++){
            printf("%d | %d\n", *(roll+i), *(total+i));
        }

        for(int i=0; i<n; i++){
            free(*(marks+i));
        }

        free(marks);
        free(roll);
        free(total);

        return 0;
    }

