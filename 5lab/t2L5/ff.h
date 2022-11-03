
#ifndef FF_H_INCLUDED
#define FF_H_INCLUDED

int check_choice()
{
    int choice;
    while (scanf("%d", &choice) != 1 || getchar()!='\n' || (choice!=1 && choice != 2)) {
        printf("Wrong! Try again.\n");
        rewind(stdin);
    }
    return 0;
}

int input_check()
{
    int val;
    while (scanf("%d", &val) != 1 || getchar()!='\n') {
        printf("Wrong! Try again.\n");
        rewind(stdin);
    }
    return val;
}

int **memory(int n)
{
    int **mas;
    mas = (int **)calloc(n, sizeof(int *));
    for(int i=0; i<n; i++)
    {
        mas[i] = (int *)calloc(n, sizeof(int)); //*(mas + i)
    }
    return mas;
}

void input_row(int *mas, int n)
{
    for (int i = 0; i < n; i++)
        *(mas+i) = input_check();
}

void input_matr(int **matr, int n)
{
    int i, j;
    for(i = 0; i < n; i++)
        input_row(*(matr + i), n);
}

void deleteElement(int** array, int* size, int index)
{
    *size = *size - 1;

    for (int i = index; i < *size; i++)
        (*array) = (*array)[i + 1];

    *array = realloc(*array, *size * sizeof(int));
}

void movee(int* row, int index, int n) {
    for (int j = index; j<n; j++)
        *(row + j)=*(row+1+j);
}

void print_row(int *m, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", *(m + i)); // m[i]
    printf("\n");
}

void output(int **matr, int n, int m)
{
    for (int i = 0; i < n; i++)
        print_row(matr[i], m);
}

#endif 

