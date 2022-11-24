#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "Header.h"

int main()
{
    srand(time(NULL));
    int *arr;
    int *mas;
    int n;
    double temphoar=0.0, tempsortt=0.0;
    printf("size: " );
    n=inputCheck();
    printf("\n");
    mas=callocc(n);
    arr=callocc(n);
    printf("1 random. 2 keyboard: ");
    int choice = inputChoice();
    printf("Enter arr:\n");
    inputMas(mas, n, choice);
    *arr=array(mas, n);
    clock_t beginh = clock();
    hoar(arr, 0, n-1);
    clock_t endh = clock();
    temphoar += (double)(endh-beginh)/CLOCKS_PER_SEC;
    printf("Arr: \n");
    //output(mas, n);
    printf("\n");
    clock_t begins = clock();
    sortt(mas, n);
    clock_t ends = clock();
    tempsortt += (double)(ends-begins)/CLOCKS_PER_SEC;
    printf("New array: \n");
   // output(mas, n);
    printf("\n");
    printf("Hoar sort time: %f s\n", temphoar);
    printf("Choice sort time: %f s", tempsortt);
    printf("\n");
    return 0;
}
