//Diego Rosas
//Esteban Jaime
//Jose Vilchis

#include <stdio.h>

int main() {
    int n,i, k, r=0;
    printf("Ingrese numero n de elementos\n");
    scanf("%i",&n);
    int a[n];
    for (i=0;i<n;i++){
        printf("[%i]: ",i+1);
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++) {
    for(k=(i+1);k<n;k++) {
        if (((a[i] + a[k])%3)==0)
            r +=1;
    }
}
    printf("Resultado : %i\n",r);
    return 0;
}