//Diego Eduardo Rosas Gonzalez
//Esteban Daniel Jaime Rosales 
//Jose Abel Vilchis Mar

// Find any duplicate
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, aux, i=0, j, *N;
    //Creacion del vector
    scanf("%d", &n);
    printf("\n");
    N = (int*)malloc((n+1)*sizeof(int));
    //Ingreso de valores
    while(i<(n+1)){
        do{
            scanf("%d", &aux);
        }while(aux<1 || aux>n);
        *(N+i) = aux;
        i++;
    }
    //Buscando la mayor repeticion
    aux=0;
    for(i=0; i<n; i++){
        aux = *(N+i);
        for(j=i+1; j<(n+1); j++){
            if(*(N+j) == aux){
            printf("\n\n%d\n", aux);
            free(N);
            return 0;
            }
        }
    }
    free(N);
    return 0;
}

