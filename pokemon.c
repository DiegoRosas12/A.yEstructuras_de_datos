//Diego Rosas
//Esteban Jaime
//Jose Vilchis
#include <stdio.h>
 
int main(int argc, const char * argv[]) {
   
    // N numero de pokemon
    // M numeros de barras de dulce
    // X precio de numero de barras de dulce para evolucionar pokemon
    // Y precio de numero de barras de dulce para vender pokemon (Sin evolucionar)
   
    int N=0, M=0, X=0, Y=0, r=0;
   
    printf("Ingrese el numero de Pokemon capturados: \n");
    scanf("%d", &N);
   
    printf("\nIngrese el numero de barras de dulce disponibles: \n");
    scanf("%d", &M);
   
    printf("\nIngrese el numero de barras de dulce para evolucionar al pokemon: \n");
    scanf("%d", &X);
   
    printf("\nIngrese el numero de barras de dulce para vender un pokemon: \n");
    scanf("%d", &Y);
   
   /* while(!(r>0)){
        r = M - (X*N);
        if (r<0){
        N--;
        M += Y;
        }
if (r==0)
break;
    }
    */
    
    while(r<0){
        r = M - (X*N);
        M += Y;
        N--;
        if(r==0)
          break;
    }
    
    //printf("N:%d M:%d X:%d Y:%d",N,M,X,Y);
    printf("\nResultado : %i\n",N);
    return 0;
}