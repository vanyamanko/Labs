
//вывод
void output(int* mas,int n)
{
    for (int i=0; i<n; i++) {
        printf("%d ", mas[i]);
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

void inputMas(int* mas, int n, int choice)
{
    if(choice==2) {
        for (int i=0; i<n; i++) {
            mas[i]=inputCheck();
        }}
    else
    {
        for(int i=0; i<n; i++)
        {
            mas[i]=rand()%100;
        }
    }
}

//сортировка
void sortt(int *mas, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int i1=i;
        if(mas[i]%2==0) {
            
            for(int j=i+1; j<n; j++)
            {
                if(mas[i1]>mas[j] && mas[j]%2==0) i1=j;
            }
                    int temp=mas[i];
                     mas[i]=mas[i1];
                     mas[i1]=temp;
                
        }
    }
}
int inputChoice()
{
    int val;
    while (scanf("%d", &val) != 1 || (val!=1 && val!=2) || getchar()!='\n') {
        printf("Wrong! Try again.\n");
        rewind(stdin);
    }
    return val;
}


int* callocc(int n)
{
    int *mas=(int*)calloc(n, sizeof(int));
    return mas;
}
int array(int *mas, int n)
{
    int *arr;
    for(int i=0; i<n; i++) arr[i]=mas[i];
    return arr;
}

void hoar(int *mas, int l, int r)
{
int i, j, t;
int sr = mas[(l + r) / 2];
i = l; j = r;
do{
    while (mas[i] < sr &&mas[i]%2==0) i++; // ищем слева элемент больше    среднего
    while (mas[j] > sr &&mas[j]%2==0) j--; // ищем справа элемент меньше среднего
    if (i <= j) // если левая граница не прошла за правую
    {
    t = mas[i];
    mas[i] = mas[j];
    mas[j] = t;
    i++; j--;
    }
} while (i <= j); // пока границы не совпали

if (i < r)
   hoar(mas, i, r);
if (j>l)
    hoar(mas, l, j);
}
