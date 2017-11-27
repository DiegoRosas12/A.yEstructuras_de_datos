//Max Difference
#include <stdio.h>

int** sort(int *x, int n){
	int i, j;
	int **px, *aux;
	px = (int**)malloc(n*sizeof(int*));
	for (i = 1, *px = x++; i < n; i++, x++)
		px[i] = x;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (*px[i] < *px[j])
			{
				aux = px[i];
				px[i] = px[j];
				px[j] = aux;
			}
	return px;
}

int main() {
    int i,n, *p;
    printf("Numero de elementos: ");
    scanf("%i",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%i",&a[i]);
    p = a;
    for(i=0;i<n;i++)
    printf("%i\n",*(p+i));

    return 0;
}