// Find any duplicate

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* ordenar(int *N, int n, int **H){
    int i, j;
    int *ON, *aux, *H1;
    H1 = *H
    ON = (int*)malloc((n+1)*sizeof(int));

    H1 == (int*)calloc(n, sizeof(int));

    for(i = 0; i < (n+1); i++)
        H1[N[i] - 1]++;
    
    j = max - 1;
    for(i = 0; i <(n+1);)
    {
        while(H1[j])
        {
            ON[i++] = j + 1;
            H1[j]--;
        }
        j--;
    }
    return ON;
}

int main(){
int n, i, *N, *NX, *aux, *H;

srand(time(NULL));
printf("Ingrese el valor N\n");
scanf("%d", &n);
N = (int*)malloc((n+1)*sizeof(int));
//H = (int*)calloc(n, sizeof(int));

NX = N;

while(NX-N<(n+1)){
    *NX = ((n-1)*rand()/RAND_MAX+1);
    NX++;

}
H = NULL;
aux = N;
while(aux - N < (n+1)){
    NX[aux - N] = ordenar(aux, n, &H);
    aux++;
}

printf("N (Desordenado) = %d\n", n);
for(i=0; i<(n+1); i++){
    printf("%d ", N[i]);
}

printf("NX (Ordenado)\n");
for(i=0; i<(n+1); i++){
    printf("%d ", NX[i]);
}

printf("H (Histograma)\n");
for(i=0; i<n; i++){
    printf("%d ", H[i]);
}

free(H);
free(N);
free(NX);
return 0;
}
