#include <stdio.h>

void sort_mas(int *num, int size)
{
    for (int i=0; i<size-1; i++) {
        for (int j = (size - 1); j > i; j--)
        {
            if (num[j - 1] > num[j])
            {
                int temp = num[j - 1];
                num[j - 1] = num[j];
                num[j] = temp;
            }
        }
    }
}

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
            printf("Enter the number of elements of the first array: : ");
            res=scanf("%d", &n);
            fflush(stdin);
            if (res==1 && n<=100 && n>0) {NotCorrected=1;}
            else {printf("Wrong! Try again.\n");}
        }
    }
    else {
        n = 1+rand()%100;
        printf("The number of elements of the first array: %d\n", n);
    }


    int Choose_input2; NotCorrected=0;
    while (NotCorrected==0) {
        printf("select: 1 for random input, 2 for keyboard input: ");
        res=scanf("%d", &Choose_input2);
        fflush(stdin);
        if (res==1 && (Choose_input2==1 || Choose_input2==2)) {NotCorrected=1;}
        else {printf("Wrong! Try again.\n");}
    }

    int mas1[100];

    if (Choose_input2==2) {

        NotCorrected=0;
        while (NotCorrected==0) {
            printf("Enter the value 1 of the first array: ");
            res=scanf("%d", &mas1[0]);
            fflush(stdin);


            if (res==1) {NotCorrected=1;}
            else {printf("Wrong! Try again.\n");}
        }
        for (int i=1; i<n; i++) {
            NotCorrected=0;
            while (NotCorrected==0) {
                printf("Enter the value %d of the first array: ", i+1);
                res=scanf("%d", &mas1[i]);
                fflush(stdin);
                if (res==1 && mas1[i]<=mas1[i-1]) {NotCorrected=1;}
                else {printf("Wrong! Try again.\n");}
            }
        }
    }
    else {
        for (int i=0; i<n; i++) {
            mas1[i] = rand()%20000-10000;
            printf("The value %d of the first array: %d\n", i+1, mas1[i]);
        }
        sort_mas(mas1,n);
        int rev;
        for (int i=0; i< n/2; i++) {
            rev = mas1[i];
            mas1[i] = mas1[n-i-1];
            mas1[n-i-1] = rev;
        }
    }

    int m; NotCorrected=0;

    int Choose_input3;
    while (NotCorrected==0) {
        printf("select: 1 for random input, 2 for keyboard input: ");
        res=scanf("%d", &Choose_input3);
        fflush(stdin);
        if (res==1 && (Choose_input3==1 || Choose_input3==2)) {NotCorrected=1;}
        else {printf("Wrong! Try again.\n");}
    }

    if (Choose_input3==2) {
        NotCorrected=0;
        while (NotCorrected==0) {
            printf("Enter the number of elements of the second array: ");
            res=scanf("%d", &m);
            fflush(stdin);
            if (res==1 && m<=100 && m>0) {NotCorrected=1;}
            else {printf("Wrong! Try again.\n");}
        }
    }
    else {
        m = 1+rand()%100;
        printf("The number of elements of the second array: %d\n", m);
    }

    int mas2[100];

    int Choose_input4; NotCorrected=0;
    while (NotCorrected==0) {
        printf("select: 1 for random input, 2 for keyboard input: ");
        res=scanf("%d", &Choose_input4);
        fflush(stdin);
        if (res==1 && (Choose_input4==1 || Choose_input4==2)) {NotCorrected=1;}
        else {printf("Wrong! Try again.\n");}
    }

    if (Choose_input4==2) {
        NotCorrected=0;
        while (NotCorrected==0) {
            printf("Enter the value 1 of the second array: ");
            res=scanf("%d", &mas2[0]);
            fflush(stdin);
            if (res==1) {NotCorrected=1;}
            else {printf("Wrong! Try again.\n");}
        }
        for (int i=1; i<m; i++) {
            NotCorrected=0;
            while (NotCorrected==0) {
                printf("Enter the value %d of the second array: ", i+1);
                res=scanf("%d", &mas2[i]);
                fflush(stdin);
                if (res==1 && mas2[i]>=mas2[i-1]) {NotCorrected=1;}
                else {printf("Wrong! Try again.\n");}
            }
        }
    }
    else {
        for (int i=0; i<m; i++) {
            mas2[i] = rand()%20000-10000;
            printf("The value %d of the second array: %d\n", i+1, mas2[i]);
        }
        sort_mas(mas2,m);
    }

    int NewMas[100],i=0,j=m-1,k=0;
    while (i<n || j>=0) {
        if (i>=n) { NewMas[k]=mas2[j]; k++; j--;}
        else  {
            if (j<0) {NewMas[k]=mas1[i]; k++; i++;}
            else {
                if (mas1[i]>mas2[j]) {NewMas[k]=mas1[i]; k++; i++;}
                else {NewMas[k]=mas2[j]; k++; j--;}
            }
        }
    }

    for (i=0; i<n+m; i++) {
        printf("Element %d of the new array: %d\n", i+1, NewMas[i]);
    }

    return 0;
}
