// Find any duplicate

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
int n, *N, *NX, *H;

srand(time(NULL));
printf("Ingrese el valor N\n");
scanf("%d", &n);
N = (int*)malloc((n+1)*sizeof(int));
H = (int*)calloc(n, sizeof(int));

NX = N;

while(NX-N<(n+1)){
    *NX = ((n-1)*rand()/RAND_MAX+1);
    NX++;
}


free(N);
return 0;
}
