//Diego Eduardo Rosas Gonzalez
//Esteban Daniel Jaime Rosales 
//Jose Abel Vilchis Mar
#include <stdio.h>
#include <stdlib.h>

//Agregue X


//Agregue O


//Funcion posibilidad
void posibilidad(int T[0][3]){
    int p=0, i;
    for(i=0;i<3;i++)

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
int v[8][1][3][1];
int i=0, k=0, p=0, r,*pT, **ppT, t;
//Guardar posiciones
for (i=0;i<3;i++){
    for(k=0;k<3;k++){
    scanf("%d",&t);
    switch(t){
        case 2:
        T[i][k] = 1;
        break;
        case 1:
        T[i][k] = -1;
        break;

        default:
        T[i][k] = 0;
        break;
    }

    p += T[i][k];
    }
}

for (i=0;i<8;i++){
for (k=0;k<3;k++){

v[i][1][1][k]=
}
}









if (p>=2||p<=(-2)){
    printf("-1\n");
    r = -1;
}else if (p==1) {
    printf("turno de X\n");
}else if (p==-1) {
    printf("turno de 0\n");
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
posibilidad(T);
//printf("%i",r);
return 0;
}

