
int inputCheck()
{
    int val;
    while (scanf("%d", &val) != 1 || getchar()!='\n') {
        printf("Wrong! Try again.\n");
        rewind(stdin);
    }
    return val;
}

int** input(int n, int m)
{
    int **mas;
    mas = (int**)calloc(n, sizeof(int *));
    for(int i=0; i<n; i++)
    {
        mas[i] = (int*)calloc(m, sizeof(int));
        for(int j=0; j<m; j++)
        {
            mas[i][j]=inputCheck();
        }
    }
    return mas;
}

void inputRow(int *mas, int n)
{
    for (int i = 0; i < n; i++)
        *(mas+i) = inputCheck();
}

int output(int **mas, int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }
    return **mas;
}

void merge(int **mas, int n, int m)
{
    
  int mid = n / 2;
  if (n % 2 == 1)
    mid++;
  int h = 1;
  int **c = (int**)malloc(n * sizeof(int*));
    for(int g=0; g<n; g++)
    {
        c[g]=(int*)malloc(m*sizeof(int));
    }
  int step;
    
        //
        while (h < n)
        {
            step = h;
            int i = 0;
            int j = mid;
            int k = 0;
            int s1=0, s2=0;
            while (step <= mid)
            {
                while ((i < step) && (j < n) && (j < (mid + step)))
                {
                    for(int p=0; p<m; p++)
                    {
                       if(mas[i][p]%2==0) s1+=mas[i][p];
                       if(mas[j][p]%2==0) s2+=mas[j][p];
                    }
                    if (s1<s2)
                    {
                        for(int p=0; p<m; p++){
                            c[k][p] = mas[i][p];}
                        i++; k++;
                    }
                    else {
                        for(int p=0; p<m; p++){
                            c[k][p] = mas[j][p];}
                        j++; k++;
                    }
                }
                while (i < step)
                {
                    for(int p=0; p<m; p++){
                        c[k][p] = mas[i][p];}
                    i++; k++;
                }
                while ((j < (mid + step)) && (j<n))
                {
                    for(int p=0; p<m; p++){
                        c[k][p] = mas[j][p];}
                    j++; k++;
                }
                step = step + h;
            }
            h = h * 2;
            
            for (i = 0; i<n; i++)
                for(int p=0; p<m; p++)
                    mas[i][p] = c[i][p];
        }
}

