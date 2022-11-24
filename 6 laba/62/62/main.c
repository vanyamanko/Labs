#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"
int main()
{
    int n,m;
    printf("row: ");
    n=inputCheck();
    printf("col: ");
    m=inputCheck();
    int **mas;
    printf("Matrix:\n");
    mas=input(n, m);
    printf("Your array:\n");
    output(mas, n, m);
    merge(mas, n, m);
    printf("New array:\n");
    output(mas, n, m);
    return 0;
}

