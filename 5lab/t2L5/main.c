
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ff.h"
int main()
{
    
    int n;
    printf("select how to enter matrix rows and columns: 1 for random input, 2 for keyboard input: ");
    int choice1=check_choice();

    if (choice1==2){
        printf("Enter the number of matrix rows and columns: ");
        n=input_check();
    }
    else {
        n = 1+rand()%100;
        printf("The number of matrix rows and columns: %d\n", n);
    }

    printf("select how to enter array: 1 for random input, 2 for keyboard input: ");
    int choice2=check_choice();
    int **mas;

    mas=memory(n);

    if (choice2==2){
        printf("Enter array:\n");
        input_matr(mas,n);
        printf("Your array:\n");
        output(mas,n,n);
    }
    else {
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                *(*(mas + i) + j) = 1+rand()%100;
            }
        }
        printf("Your array: %d\n", n);
        output(mas,n,n);
    }
    int m=n-1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j<n; j++) {
            if (i+j == n-1) {
                movee(*(mas + i), j, n);
            }
        }
    }

    mas = (int**)realloc(mas, m*sizeof(int*));

    printf("New array:\n");
    output(mas,n,m);

    free(mas);
    return 0;
}
