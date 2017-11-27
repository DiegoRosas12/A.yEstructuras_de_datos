// Find any duplicate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
 
int main(){
    int n, i, *N, *NX, *H;
   
    srand((unsigned int)time(NULL));
    printf("Ingrese el valor N\n");
    scanf("%d", &n);
    N = (int*)malloc((n+1)*sizeof(int));
    H = (int*)calloc(n, sizeof(int));

    NX = N;

    while((NX-N)<(n+1)){
        *NX = ((n-1)*rand())/RAND_MAX+1;
        NX++;
    }
   
//Histograma
    for(i = 0; i < (n+1); i++)
        H[N[i]-1]++;
//Buscando la mayor repeticion
    for(i=0; i<(n+1); i++){
        if(H[i]>1){
        printf("\nEl numero que mas se repite es: %d\n", i+1);
        break;
        }  
    }
 
   printf("N: %d\n", n);
    for(i=0; i<(n+1); i++){
        printf("%d ", N[i]);
    }
 
    printf("\nH (Histograma)\n");
    for(i=0; i<(n+1); i++){
        printf("%d ", H[i]);
    }
   
    free(H);
    free(N);
    return 0;
}
