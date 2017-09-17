
// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//
 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
void imprimir(float *x, int m)
{
    int i;
    for (i = 0; i < m; i++)
        printf("X[%d] = %f\n", i+1, x[i]);
}
 
float media1(float *x, int n)
{
    int i;
    float m = *x;
    for (i = 1; i < n; i++)
        m += x[i];
    return m / n;
}
 
int main()
{
    float min, max, *x, *mx, *aux, t;
    int n, m;
    time_t t1, t2;
    srand(time(NULL));
    printf("Ingrese el maximo: ");
    scanf("%f", &max);
    printf("Ingrese el minimo: ");
    scanf("%f", &min);
    if (max < min)
    {
        max = max + min;
        min = max - min;
        max = max - min;
    }
    do {
        printf("Numero de datos: ");
        scanf("%d", &m);
    } while (m<1);
    do {
        printf("Numero de datos en media: ");
        scanf("%d", &n);
    } while ((n<1)||(m<n));
    x = (float*)malloc(m*sizeof(float));
    mx = x;
    while ((mx-x)<m)
    {
        *mx = ((max-min)*rand())/RAND_MAX+min;
        //printf("%d\n", (int)(mx-x));
        mx++;
    }
    //imprimir(x, m);
    mx = (float*)calloc(m-n+1, sizeof(float));
    time(&t1);
    aux = x;
    while ((aux-x)<(m-n+1))
    {
        mx[aux - x] = media1(aux, n);
        aux++;
    }
    time(&t2);
    t = difftime(t2, t1);
    printf("Tiempo: %f\n", t);
    //imprimir(mx, m-n+1);
    getchar();
    getchar();
    free(x);
    free(mx);
    return 0;
}