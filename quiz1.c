#include <stdio.h>

int main() {
    int n, t, l, i,s=0;
    int hi[101], hd[101];
    printf("No de elementos");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("1.-Derecho\t2.-Izquierdo\n");
        printf("Tamaño, der o izq\n");
        scanf("%d%d",&t,&l);
        if(l!=1)
            l=0;
        if(l==1){
            hd[t]++;
        }else{
            hi[t]++;
        }
    }
    for(i=1;i<=101;i++) {
        if(hd[i]&&hi[i])
        hd[i]+=hi[i];
        s += (hd[i]%2);
    }
    printf("Pares: %d",s);
    return 0;
}