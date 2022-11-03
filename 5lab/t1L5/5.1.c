#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "fff.h"


int main()
{
    
    float *mas;
    int n;
    printf("size: " );
    n=inputCheck();
    printf("\n");
    mas=(float*)malloc(sizeof(float) * n);
    printf("Enter arr:\n");
    input_mas(mas, n);
    printf("Your arr: \n");
    output(mas, n);
    printf("\n");
    for(int i=0; i<n; i++){
        int k=mas[i];
        if(mas[i]==k){
            deleteElement(&mas, &n, i);
            i--;
        }
    }
    printf("New array:\n");
    output(mas, n);
    printf("\n");
    free(mas);
    return 0;

}

   


