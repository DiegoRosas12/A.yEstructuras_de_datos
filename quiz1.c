//Diego Rosas, Vilchis Mar, Esteban Jaime 
#include <stdio.h>

#define M 101

int main() {
    //No quitamos punteros *hd, *hi
    //s no inicializado en 0
    int n, t, l, i,s=0;
    printf("Num de elementos: ");
    //Falta & en scanf
    scanf("%d",&n);
    int hi[M], hd[M];
    for(i=0;i<n;i++) {
        printf("Tamaño, der(1) o izq(2)\n");
        scanf("%d%d",&t,&l);
        if(l!=1)
            l=0;
        if(l==1){
            printf("Derecho | %d\n",t);
            hd[t]++;
        }else{
            printf("Izquierdo | %d\n",t);
            hi[t]++;
        }
    }
    for(i=1;i<=101;i++) {
        //Anterior if(hd[i]&&hi[i])
        if(hd[i]&&hi[i]){
        hd[i] += hi[i];
        //Modulo no cuenta los pares
        //ha[i]%2 -> ha[i]/2
        s += (hd[i]/2);
        }
    }
    printf("\nPares: %d\n",s);
    return 0;
}