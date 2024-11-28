#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *m1 = NULL;
int *m2 = NULL;
int *sum = NULL;
int *mis = NULL;
int *mim1 = NULL;
int *mim2 = NULL;
int *n = NULL;
int *A = NULL;

void output()
{
    int i;
    for (i=0;i<*n;i++)
        printf("%i: %i \n", i, A[i]);
    printf("\nдва максимальных числа под индексами %i %i: %i %i \nсумма = %i", *mis,(*mis+1), A[*mis], A[(*mis+1)], *sum);
    printf("\nдва минимальных числа под индексами %i %i: %i %i", *mim2, *mim1, *m1, *m2);
    printf("\nрезультат работы программы: %i %i \n", (*sum+*m1),(*sum+*m2));
}

void fill()
{
    int i;
    for (i=0;i<*n;i++)
        A[i] = rand() % 101 - 50;
}

void findmaxsum()
{
for(int i=0;i<(*n-1);i++)
{
    if((A[i]+A[i+1])>*sum){*sum=(A[i]+A[i+1]); *mis=i;}
}
}

void findmintwo()
{
*m1=A[0];
*m2=A[1];
for(int i=0;i<*n;i++)
{
    if(A[i]<*m1)
    {
        *m2=*m1;
        *m1=A[i];
        *mim1=*mim2;
        *mim2=i;
    }
}
}

int main()
{
m1 = calloc(1, sizeof(int));
m2 = calloc(1, sizeof(int));
sum = calloc(1, sizeof(int));
mis = calloc(1, sizeof(int));
mim1 = calloc(1, sizeof(int));
mim2 = calloc(1, sizeof(int));
n = calloc(1, sizeof(int));
A = malloc(sizeof(int));
if((m1) && (m2) && (sum) && (mis) && (mim1) && (mim2) && (n))
{
srand(time(NULL));
printf("Введите число элементов массива \n");
scanf("%i", &*n);
A = calloc(*n, sizeof(int));
if(A)
{
fill();
findmaxsum();
findmintwo();
output();
free(A);
A = NULL;
}

free(m1);
free(m2);
free(sum);
free(mis);
free(mim1);
free(mim2);
free(n);
m1 = NULL;
m2 = NULL;
sum = NULL;
mis = NULL;
mim1 = NULL;
mim2 = NULL;
n = NULL;
}
return 0;
}
