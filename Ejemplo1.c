// ConsoleApplication1.cpp: define el punto de entrada de la aplicaci�n de consola.
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

void imprimir2(float **px, int m)
{
	int i;
	for (i = 0; i < m; i++)
		printf("X[%d] = %f\n", i+1, *(px[i]));
}

float media1(float *x, int n)
{
	int i;
	float m = *x;
	for (i = 1; i < n; i++)
		m += x[i];
	return m / n;
}

float media2(float *x, int n, int i)
{
	if (i<n)
		return media2(x, n, i+1) + x[i] / n;
	else
		return 0;
}

float media3(float *x, int n, int i)
{
	if (i<n)
		return media2(x, n, i + 1) + x[i];
	else
		return 0;
}

float media4(float *x, int n, float suma)
{
	return suma - x[0] + x[n];
}

float** ordenar(float *x, int m)
{
	int i, j;
	float **px, *aux;
	px = (float**)malloc(m*sizeof(float*));
	for (i = 1, *px = x++; i < m; i++, x++)
		px[i] = x;
	for (i = 0; i < m - 1; i++)
		for (j = i + 1; j < m; j++)
			if (*px[i] < *px[j])
			{
				aux = px[i];
				px[i] = px[j];
				px[j] = aux;
			}
	return px;
}

float mediana(float *x, int m)
{
	float **px, med;
	px = ordenar(x, m);
	med = (m%2 ? *px[m/2] : (*px[m/2]+*px[m/2-1])/2);
	free(px);
	return med;
}

int main()
{
	float min, max, *x, *mx, *aux, *mdx;
	//float **px;
	double tm1, tm2, tm3, tm4, tm5;
	int n, m, i;
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
	tm1 = difftime(t2, t1);
	printf("mx[%d] = %f\nmx[%d] = %f\nmx[%d] = %f\n", 1, mx[0], (m-n)/2+1, mx[(m-n)/2], m-n+1, mx[m-n]);
	printf("Tiempo 1: %lf\n", tm1);
	/*
	time(&t1);
	aux = x;
	while ((aux - x)<(m - n + 1))
	{
		mx[aux - x] = media2(aux, n, 0);
		aux++;
	}
	time(&t2);
	tm2 = difftime(t2, t1);
	printf("Tiempo 2: %lf\n", tm2);
	time(&t1);
	aux = x;
	while ((aux - x)<(m - n + 1))
	{
		mx[aux - x] = media3(aux, n, 0);
		mx[aux - x] /= n;
		aux++;
	}
	time(&t2);
	tm3 = difftime(t2, t1);
	printf("Tiempo 3: %lf\n", tm3);
	*/
	time(&t1);
	for (i = 1, mx[0] = x[0]; i < n; i++)
		mx[0] += x[i];
	mx[0] /= n;
	aux = x;
	while ((aux - x)<(m - n))
	{
		mx[aux - x + 1] = media4(aux, n, mx[aux - x]*n);
		mx[aux - x + 1] /= n;
		aux++;
	}
	time(&t2);
	tm4 = difftime(t2, t1);
	printf("mx[%d] = %f\nmx[%d] = %f\nmx[%d] = %f\n", 1, mx[0], (m - n) / 2 + 1, mx[(m - n) / 2], m - n + 1, mx[m - n]);
	printf("Tiempo 4: %lf\n", tm4);
	//imprimir(mx, m-n+1);
	time(&t1);
	/*
	printf("Original\n");
	imprimir(x, n);
	px = ordenar(x, n);
	printf("Despues de ordenar\n");
	imprimir(x, n);
	printf("Ordenado\n");
	imprimir2(px, n);
	*/
	mdx = (float*)malloc((m-n+1)*sizeof(float));
	aux = x;
	while ((aux - x) < (m - n + 1))
	{
		mdx[aux - x] = mediana(aux, n);
		aux++;
	}
	time(&t2);
	tm5 = difftime(t2, t1);
	printf("Tiempo 5: %lf\n", tm5);
	getchar();
	getchar();
	//free(px);
	free(x);
	free(mx);
	free(mdx);
    return 0;
}

