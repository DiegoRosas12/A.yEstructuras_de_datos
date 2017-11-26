#include <stdio.h>
#include <stdlib.h>

//Agregue X


//Agregue O


//Funcion posibilidad
int posibilidad(int **pT) {
    int i, k, a=0;
    //tenemos que guardar un resultado por renglón y al final sumar los resultados de los renglones
    // para saber quien tiene más posibilidades de ganar 
    for (i=0;i<3;i++) {
        a += T[i][k];
    }
    return 0;
}


int main(){
int T[3][3];
int i=0, k=0, p=0, r;
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
printf("%i",r);
return 0;
}

