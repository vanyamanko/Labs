
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "f.h"


int main() {
    int n;
    printf("size of row: ");
    n=input_check();
    int** mas;
    int m;
       mas = (int**)calloc(n, sizeof(int*));
       for (int i = 0; i < n; i++) {
           printf("input amount of numbers in %d row  ", i + 1);
           m = input_check();
           *(mas + i) = (int*)calloc(m, sizeof(int));
           printf("-100 automat\n");
               for (int j = 0; j < m - 1; j++) {
                   while (scanf("%d", *(mas+i)+j) != 1 || *(*(mas + i) + j)==-100 || getchar() != '\n') {
                       printf("Wrong! Try again.\n");
                       rewind(stdin);
                   }
               }
           *(*(mas + i) + m - 1) = -100;
       }
     
    for(int i=0; i<n; i++)
        {
            int k=last(mas,i);
            if((i + 1) % 2 == 0)
            {
                for(int j=0; mas[i][j] != -100; j++)
                {
                    if(mas[i][j] % 2 != 0)
                    {
                        k++;
                        mas[i]=realloc(mas[i], k * sizeof(int));
                        for(int x=k-1; x>j; x--)
                            mas[i][x] = mas[i][x-1];
                        j++;
                    }
                }
            }
        }
        printf("New array:\n");
        output(mas,n);
        free(mas);
        return 0;
    }
