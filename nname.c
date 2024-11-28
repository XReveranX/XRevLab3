#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int m1=0;
int m2=0;
int sum=0;
int mi=0;
int mii=0;
int miii = 0;
int n=0;

void output(int a[])
{
    int i;
    for (i=0;i<n;i++)
        printf("%i: %i \n", i, a[i]);
    printf("\nдва максимальных числа под индексами %i %i: %i %i \nсумма = %i", mi,(mi+1), a[mi], a[(mi+1)], sum);
    printf("\nдва минимальных числа под индексами %i %i: %i %i", miii, mii, m1, m2);
    printf("\nрезультат работы программы: %i %i \n", (sum+m1),(sum+m2));
}

void fill(int a[])
{
    int i;
    for (i=0;i<n;i++)
        a[i] = rand() % 101 - 50;
}

int findmaxsum(int a[])
{
for(int i=0;i<(n-1);i++)
{
    if((a[i]+a[i+1])>sum){sum=(a[i]+a[i+1]); mi=i;}
}
}

void findmintwo(int a[])
{
m1=a[0];
m2=a[1];
for(int i=0;i<n;i++)
{
    if(a[i]<m1)
    {
        m2=m1;
        m1=a[i];
        mii=miii;
        miii=i;
    }
}
}

int main()
{
    srand(time(NULL));
printf("Введите число элементов массива \n");
scanf("%i", &n);
int A[n];
fill(A);
findmaxsum(A);
findmintwo(A);
output(A);
}
