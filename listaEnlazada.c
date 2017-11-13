#include <stdio.h>
#include <stdlib.h>

typedef struct lt {
    int v;
    lt *s;
}lt;

int agregar(lt *nodo, int n){
    nodo->s = NULL;
    if (primero == NULL){
        primero = nodo;
        ultimo = nodo;
        nodo->v = n;
    }else{
        ultimo->s = nodo;
        ultimo = nodo;
        
    }
    return 0
}

int main() {
    int op;
    lt *primero = NULL;
    lt *ultimo = NULL;
    do {
        printf("Desea ingresar otro elemento?\n");
        scanf("%i",&op);
        lt *nv = (*lt)malloc(sizeof(lt));

    }while(op);
    imprimir(lt1);
    liberar(lt);
    return 0;
}