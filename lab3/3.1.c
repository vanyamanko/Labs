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

    int Choose_input2; NotCorrected=0;
    while (NotCorrected==0) {
        printf("select: 1 for random input, 2 for keyboard input: ");
        res=scanf("%d", &Choose_input2);
        fflush(stdin);
        if (res==1 && (Choose_input2==1 || Choose_input2==2)) {NotCorrected=1;}
        else {printf("Wrong! Try again.\n");}
    }

    float a[100];
    if (Choose_input2==2) {
        for (int i=0; i<n; i++) {
            NotCorrected=0;
            while (NotCorrected==0) {
                printf("Enter value %d: ", i+1);
                res=scanf("%f", &a[i]);
                fflush(stdin);
                if (res==1) {NotCorrected=1;}
                else {printf("Wrong! Try again.\n");}
            }
        }
    }
    else {
        for (int i=0; i<n; i++) {
            a[i] = rand()%20000-10000;
            printf("The value %d: %f\n", i+1, a[i]);
        }
    }

    float min=a[0];
    for (int i=0; i<n; i++) {
        if (a[i]<min) {min=a[i];}
    }
    printf("Min value: %.2f.\n", min);

    int i=0,first;
    while (i<n && a[i]<0) {i++;}
    if (i>=n) {first=-1;}
    else {first=i;}

    i=n-1;
    int second;
    while (i>=0 && a[i]<0) {i--;}
    if (i<0) {second=-1;}
    else {second=i;}

    float sum=0;
    if (first==-1 || second==-1) {
        printf("We don't have positive number.");
    }
    else {
        for (i=first+1; i<second; i++) {sum+=a[i];}
        printf("Sum value: %.2f.\n", sum);
    }

    return 0;
}
