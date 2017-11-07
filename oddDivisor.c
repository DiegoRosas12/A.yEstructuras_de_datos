//Diego Rosas
//Esteban Jaime
//Jose Vilchis
#include <stdio.h>

int main() {
    int a, b, i,k, t=0, l=0;
    printf("Ingrese el valor de a: \n");
    scanf("%d",&a);
    printf("Ingrese el valor de b: \n");
    scanf("%d",&b);
    if(b<a){
        b = b + a;
        a = b - a;
        b = b - a;
    }
    //if(a==1)
      //  t++;
    for(i=a;i<=b;i++){
        for (k=1;k<=b;k++){
         if((i%k)==0)
            t++;   
        }
        if((!(t%2))==0)
        l++;
        t=0;
    }
    printf("Resultado: %d\n",l); 
    return 0;

}
//Esteban ves esto?XDXDXDXD