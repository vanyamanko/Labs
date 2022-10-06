#include <stdio.h>

int main()
{
    srand(time(NULL));

    int n,res;
    int NotCorrected=0;

    int Choose_input;
    while (NotCorrected==0) {
        printf("select: 1 for random input, 2 for keyboard input: ");
        res=scanf("%d", &Choose_input);
        fflush(stdin);
        if (res==1 && (Choose_input==1 || Choose_input==2)) {NotCorrected=1;}
        else {printf("Wrong! Try again.\n");}
    }

    if (Choose_input==2) {
        NotCorrected=0;
        while (NotCorrected==0) {
            printf("Enter the number: ");
            res=scanf("%d", &n);
            fflush(stdin);
            if (res==1 && n<=100 && n>0) {NotCorrected=1;}
            else {printf("Wrong! Try again.\n");}
        }
    }
    else {
        n = 1+rand()%100;
        printf("The number of elements: %d\n", n);
    }

    int mas[100];

    int Choose_input2; NotCorrected=0;
    while (NotCorrected==0) {
        printf("select: 1 for random input, 2 for keyboard input: ");
        res=scanf("%d", &Choose_input2);
        fflush(stdin);
        if (res==1 && (Choose_input2==1 || Choose_input2==2)) {NotCorrected=1;}
        else {printf("Wrong! Try again.\n");}
    }

    if (Choose_input2==2) {
        for (int i=0; i<n; i++) {
            NotCorrected=0;
            while (NotCorrected==0) {
                printf("Enter value %d: ", i+1);
                res=scanf("%d", &mas[i]);
                fflush(stdin);
                if (res==1) {NotCorrected=1;}
                else {printf("Wrong! Try again.\n");}
            }
        }
    }
    else {
        for (int i=0; i<n; i++) {
            mas[i] = rand()%20000-10000;
            printf("The value %d: %d\n", i+1, mas[i]);
        }
    }

    int i=n-1;
    int second;
    while (i>=0 && mas[i]%2!=0) {i--;}
    if (i<0) {second=-1;}
    else {second=i;}

    if (second==-1) {
        printf("We don't have even numbers.");
    }
    else {
        for (i=second+1; i<n; i++) {mas[i]=0;}
        n=second;
        printf("The number of elements: %d\n", n+1);
        for (i=0; i<=n; i++) {
            printf("Value %d: %d\n", i+1, mas[i]);
        }
    }

    return 0;
}
