/// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//


#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define B0 1
#define B1 2
#define B2 4
#define B3 8
#define B4 16
#define B5 32
#define B6 64
#define B7 -128

typedef struct lt
{
	int x;
	struct lt *s, *a;
}lt;

void imprimir(int *x, int m)
{
	int i;
	for (i = 0; i < m; i++)
		printf("X[%d] = %d\n", i+1, x[i]);
}

void imprimir2(int **px, int m)
{
	int i;
	for (i = 0; i < m; i++)
		printf("X[%d] = %d\n", i+1, *(px[i]));
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

lt* ordenar5(int *x, int m, int max, int min, int **h, lt* lt1)
{
	char f;
	int i, j;
	int *aux, *h1;
	lt *lt2, *lt3;
	lt2 = lt1;
	h1 = *h;
	f = 0;
	if (h1 == NULL)
	{
		h1 = (int*)calloc(max - min + 1, sizeof(int));
		for (i = 0; i < m; i++)
			h1[x[i] - min]++;
		j = max - min;
		for (i = 0; i < m; )
		{
			while (h1[j])
			{
				lt2 = (lt*)malloc(sizeof(lt));
				lt2->s = NULL;
				lt2->a = lt1;
				if (lt1 != NULL)
					lt1->s = lt2;
				lt1 = lt2;
				lt1->x = min + j;
				h1[j]--;
			}
			j--;
		}
	}
	else
	{
		h1[x[-1] - min]--;
		h1[x[m - 1] - min]++;
		lt2 = (lt*)malloc(sizeof(lt));
		lt2->x = x[m - 1];
		while ((lt1->a != NULL) && (lt1->x > lt2->x))
		{
			if (!(B0&f)&&(lt1->x == x[-1]))
			{
				lt3 = lt1;
				if (lt1->s != NULL)
					lt1->s->a = lt1->a;
				if (lt1->a != NULL)
					lt1->a->s = lt1->s;
				lt1 = lt1->s != NULL ? lt1->s : lt1->a;
				free(lt3);
				f |= B0;
			}
			lt1 = lt1->a;
		}
		if (lt2->x<lt1->x)
		{
			lt2->a = NULL;
			lt2->s = lt1;
			lt1->a = lt2;
		}
		else
		{
			lt2->a = lt1;
			lt2->s = lt1->s;
			lt1->s = lt2;
			if(lt2->s!=NULL)
				lt2->s->a = lt2;
		}
		if (!(B0&f))
		{
			while (lt1->x != x[-1])
				lt1 = lt1->a;
			lt3 = lt1;
			if (lt1->s != NULL)
				lt1->s->a = lt1->a;
			if (lt1->a != NULL)
				lt1->a->s = lt1->s;
			lt1 = lt1->s != NULL ? lt1->s : lt1->a;
			free(lt3);
		}
		while (lt1->s != NULL)
			lt1 = lt1->s;
	}
	return lt1;
}

int* ordenar4(int *x, int m, int max, int min, int **h)
{
	int i, j;
	int *px, *aux, *h1;
	h1 = *h;
	px = (int*)malloc(m * sizeof(int));
	if (h1 == NULL)
	{
		h1 = (int*)calloc(max - min + 1, sizeof(int));
		for (i = 0; i < m; i++)
			h1[x[i] - min]++;
	}
	else
	{
		h1[x[-1] - min]--;
		h1[x[m - 1] - min]++;
	}
	j = max - min;
	for (i = 0; i < m; )
	{
		while (h1[j])
		{
			px[i++] = min + j;
			h1[j]--;
		}
		j--;
	}
	return px;
}

int* ordenar3(int *x, int m, int max, int min)
{
	int i, j;
	int *px, *aux, *h;
	px = (int*)malloc(m * sizeof(int));
	h = (int*)calloc(max-min+1, sizeof(int));
	for (i = 0; i < m; i++)
		h[x[i]-min]++;
	j = max-min;
	for (i = 0; i < m; )
	{
		while (h[j])
		{
			px[i++] = min + j;
			h[j]--;
		}
		j--;
	}
	free(h);
	return px;
}

int** ordenar2(int *x, int m)
{
	int i, j;
	int **px, *aux;
	px = (int**)malloc(m * sizeof(int*));
	for (i = 1, *px = x++; i < m; i++, x++)
		px[i] = x;
	for (i = 1; i < m; i++)
	{
		j = i - 1;
		aux = px[i];
		while (*px[j] < *aux)
		{
			px[j + 1] = px[j];
			j--;
			if (j < 0)
				break;
		}
		px[j+1] = aux;
	}
	return px;
}

int** ordenar(int *x, int m)
{
	int i, j;
	int **px, *aux;
	px = (int**)malloc(m*sizeof(int*));
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

float mediana(int *x, int m)
{
	int **px, med;
	px = ordenar(x, m);
	med = (m%2 ? *px[m/2] : (*px[m/2]+*px[m/2-1])/2);
	free(px);
	return med;
}

float mediana2(int *x, int m)
{
	int **px, med;
	px = ordenar2(x, m);
	med = (m % 2 ? *px[m / 2] : (*px[m / 2] + *px[m / 2 - 1]) / 2);
	free(px);
	return med;
}

float mediana3(int *x, int m, int max, int min)
{
	int *px, med;
	//imprimir(x, m);
	px = ordenar3(x, m, max, min);
	//imprimir(px, m);
	med = (m % 2 ? px[m / 2] : (px[m / 2] + px[m / 2 - 1]) / 2);
	free(px);
	return med;
}

float mediana4(int *x, int m, int max, int min, int **h)
{
	int *px, med;
	//imprimir(x, m);
	px = ordenar4(x, m, max, min, h);
	//imprimir(px, m);
	med = (m % 2 ? px[m / 2] : (px[m / 2] + px[m / 2 - 1]) / 2);
	free(px);
	return med;
}

float mediana5(int *x, int m, int max, int min, int **h, lt **lt1)
{
	int *px, med, i;
	lt *lt2;
	*lt1 = ordenar5(x, m, max, min, h, *lt1);
	lt2 = *lt1;
	for (i = 0; i < m / 2; i++)
		lt2 = lt2->a;
	med = (m % 2 ? lt2->x : (lt2->x + lt2->s->x) / 2);
	return med;
}

int main()
{
	int min, max, *x, *aux, *mdx, *mdx2, *mdx3, *mdx4, *mdx5, *h;
	//float **px;
	double tm1, tm2, tm3, tm4, tm5;
	int n, m, i;
	lt *lt1;
	time_t t1, t2;
	srand(time(NULL));
	printf("Ingrese el maximo: ");
	scanf("%d", &max);
	printf("Ingrese el minimo: ");
	scanf("%d", &min);
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
		printf("Numero de datos en mediana: ");
		scanf("%d", &n);
	} while ((n<1)||(m<n));
	x = (int*)malloc(m*sizeof(int));
	mdx = x;
	while ((mdx-x)<m)
	{
		*mdx = ((max-min)*rand())/RAND_MAX+min;
		//printf("%d\n", (int)(mx-x));
		mdx++;
	}
	//imprimir(x, m);
	/*
	time(&t1);
	mdx = (int*)malloc((m-n+1)*sizeof(int));
	aux = x;
	while ((aux - x) < (m - n + 1))
	{
		mdx[aux - x] = mediana(aux, n);
		aux++;
	}
	time(&t2);
	tm1 = difftime(t2, t1);
	printf("Tiempo 1: %lf\n", tm1);
	time(&t1);
	mdx2 = (int*)malloc((m-n+1)*sizeof(int));
	aux = x;
	while ((aux - x) < (m - n + 1))
	{
		mdx2[aux - x] = mediana2(aux, n);
		aux++;
	}
	time(&t2);
	tm2 = difftime(t2, t1);
	printf("Tiempo 2: %lf\n", tm2);
	*/
	time(&t1);
	mdx3 = (int*)malloc((m - n + 1) * sizeof(int));
	aux = x;
	while ((aux - x) < (m - n + 1))
	{
		mdx3[aux - x] = mediana3(aux, n, max, min);
		aux++;
	}
	time(&t2);
	tm3 = difftime(t2, t1);
	printf("Tiempo 3: %lf\n", tm3);
	time(&t1);
	mdx4 = (int*)malloc((m - n + 1) * sizeof(int));
	aux = x;
	h = NULL;
	while ((aux - x) < (m - n + 1))
	{
		mdx4[aux - x] = mediana4(aux, n, max, min, &h);
		aux++;
	}
	free(h);
	time(&t2);
	tm4 = difftime(t2, t1);
	printf("Tiempo 4: %lf\n", tm4);
	time(&t1);
	mdx5 = (int*)malloc((m - n + 1) * sizeof(int));
	aux = x;
	h = NULL;
	lt1 = NULL;
	while ((aux - x) < (m - n + 1))
	{
		mdx5[aux - x] = mediana5(aux, n, max, min, &h, &lt1);
		aux++;
	}
	free(h);
	free(lt1); ///////////////////////////////////////////////////////////////////////////////////////
	time(&t2);
	tm5 = difftime(t2, t1);
	printf("Tiempo 5: %lf\n", tm5);
	getchar();
	getchar();
	free(x);
//	free(mdx);
//	free(mdx2);
	free(mdx3);
	free(mdx4);
	free(mdx5);
    return 0;
}

