#include <stdio.h>
#include <stdlib.h>

//Agregue X


//Agregue O


//Funcion posibilidad



int main(){
int T[3][3];
int i=0, k=0, p=0;
//Guardar posiciones
for (i=0;i<3;i++){
    for(k=0;k<3;k++){
    scanf("%d",&T[i][k]);
    p += T[i][k];
    }
}
if (p>2||p<(-2)){
    printf("posición incorrecta\n");
}else if (p==1) {
    printf("turno de X\n");
}else if (p==-1) {
    printf("turno de O\n");
}else {
    printf("No se sabe quien tira\n");
}
    //Imprimir tablero
    for(i=0;i<3;i++){
        for(k=0;k<3;k++){
        printf("%d",T[i][k]);
        }
        printf("\n");
    }

//Caso Incorrecto


return 0;
}

