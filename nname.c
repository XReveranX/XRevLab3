#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int m1=0;
int m2=0;

void fill(int n, int a[])
{
    int i;
    for (i=0;i<n;i++)
        a[i] = rand() % 101 - 50;
}

int findmaxsum(int n, int a[])
{
int m=0;
for(int i=0;i<(n-1);i++)
{
    if((a[i]+a[i+1])>m){m=(a[i]+a[i+1]);}
}
return(m);
}

void findmintwo(int n, int a[])
{
m1=a[0];
m2=a[1];
for(int i=0;i<n;i++)
{
    if(a[i]<m1)
    {
        m2=m1;
        m1=a[i];
    }
}
}

int main()
{
    srand(time(NULL));
int n;
printf("Введите число элементов массива \n");
scanf("%i", &n);
int A[n];
fill(n, A);
int sum=findmaxsum(n, A);
findmintwo(n, A);
printf("%i %i \n",(m1+sum), (m2+sum));
}