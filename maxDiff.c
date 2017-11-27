//Max Difference
#include <stdio.h>
#include <stdlib.h>

int** sort(int *p, int n){
	int i, j;
	int **px, *aux;
	px = (int**)malloc(n*sizeof(int*));
	for (i = 1, *px = p++; i < n; i++, p++)
		px[i] = p;
        for (i=1; i<n; i++) {
          j = i - 1;
          aux = px[i];
          while(*aux < *px[j]){
               px[j+1] = px[j];
               j--;
               if (j == -1)
                    break;
          }
          px[j+1] = aux; 
     }
	return px;
}

int main() {
    int i,n, *p, **px;
    printf("Numero de elementos: ");
    scanf("%i",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%i",&a[i]);
    p = a;
    px = sort(p,n);
    for(i=0;i<n-1;i++)
        a[i] = (*px[i+1] - *px[i]);
    a[n] = 0; 
    p = a;
    px = sort(p,n);
    printf("%i\n",**(px+(n-2)));
    free(px);
    return 0;
}