#include <stdio.h>
#include <stdlib.h>

//funcion posibilidad

int main(){
int T[3][3];
int i=0, k=0;
//Guardar posiciones
for (i=0;i<3;i++)
    for(k=0;k<3;k++)
    scanf("%d",&T[i][k]);
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

