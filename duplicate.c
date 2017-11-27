// Find any duplicate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
 
int main(){
    int n, n2, i=0, *N, *H;
   
    srand((unsigned int)time(NULL));
//Creacion del vector
    printf("Ingrese el valor N\n");
    scanf("%d", &n);
    N = (int*)malloc((n+1)*sizeof(int));
    H = (int*)calloc((n-1), sizeof(int));

//Ingreso de valores
    while(i<(n+1)){
        do{
        printf("Ingrese un numero para N[%d]\n", i+1);
        scanf("%d", &n2);
    }while(n2<1 || n2>n);
    N[i] = n2; 
        H[N[i]-1]++;
        i++;
    }
   
//Histograma

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
    for(i=0; i<n; i++){
        printf("%d ", H[i]);
    }
   
    free(H);
    free(N);
    return 0;
}
