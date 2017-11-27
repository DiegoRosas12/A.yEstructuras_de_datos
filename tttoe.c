#include <stdio.h>
#include <stdlib.h>

//Agregue X


//Agregue O


//Funcion posibilidad
int posibilidad(int **pT) {
    int i, k;
    //tenemos que guardar un resultado por renglón y al final sumar los resultados de los renglones
    // para saber quien tiene más posibilidades de ganar 
    for (i=0;i<3;i++) {
        
    }
    return 0;
}

void imprimir(int **ppT) {
    int i, j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
        printf("%i",*(*ppT+i)+j);
    }
}

int main(){
int T[3][3];
int i=0, k=0, p=0, r,*pT, **ppT;
//Guardar posiciones
for (i=0;i<3;i++){
    for(k=0;k<3;k++){
    scanf("%d",&T[i][k]);
    p += T[i][k];
    }
}
if (p>2||p<(-2)){
    printf("posición incorrecta\n");
    r = -1;
}else if (p==1) {
    printf("turno de O\n");
}else if (p==-1) {
    printf("turno de X\n");
}else {
    printf("No se sabe quien tira\n");
   // r = 0;
}
    //Imprimir tablero
    for(i=0;i<3;i++){
        for(k=0;k<3;k++){
        printf("%d",T[i][k]);
        }
        printf("\n");
    }
pT = (int*)malloc(sizeof(int)*3);
ppT = (int**)malloc(sizeof(int*)*3);
for(i=0;i<3;i++){
    for(k=0;k<3;k++)
    //ppT
} 

printf("%i",r);
return 0;
}

