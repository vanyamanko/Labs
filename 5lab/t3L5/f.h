#ifndef F_H_INCLUDED
#define F_H_INCLUDED

int input_check()
{
    int val;
    while (scanf("%d", &val) != 1 || getchar()!='\n') {
        printf("Wrong! Try again.\n");
        rewind(stdin);
    }
    return val;
}
int last(int** a, int n)
{
    for (int i=0;; i++) {
        if (*(*(a + n) + i) == -100) {return i+1;}
    }
}
void output(int** mas, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; *(*(mas + i) + j) != -100; j++)
            printf("%d ", *(*(mas + i) + j));
        printf("-100\n");
    }
}
#endif 
