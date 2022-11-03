
#ifndef ff_h
#define ff_h
//удаление
void deleteElement(float** array, int* size, int index)
 {
      *size = *size - 1;

      for (int i = index; i < *size; i++)
          (*array)[i] = (*array)[i + 1];

      *array = realloc(*array, *size * sizeof(float));
 }
//вывод
void output(float* mas,int n)
{
    printf("New array:\n");
    for (int i=0; i<n; i++) {
        printf("%.2f ", mas[i]);
    }
}
//проверка размера
int inputCheck()
{
    int val;
    while (scanf("%d", &val) != 1 || getchar()!='\n') {
        printf("Wrong! Try again.\n");
        rewind(stdin);
    }
    return val;
}
//проверка массива
float input_check_mas()
{
    float val;
    while (scanf("%f", &val) != 1  || getchar()!='\n') {
        printf("Wrong! Try again.\n");
        rewind(stdin);
    }
    return val;
}
void input_mas(float* m, int n)
{
    for (int i=0; i<n; i++) {
        m[i]=input_check_mas();
    }
}


#endif

