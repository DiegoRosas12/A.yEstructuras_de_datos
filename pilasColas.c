#include <stdio.h>

typedef struct pc {
    int n; //n = numero de datos; 
    float *data;
    float cv, cll; //casi lleno casi vacio
    int flag;
    float*(*crear)(int n); // Un asterisco es porque es funcion el otro es porque es puntero
    void(*liberar)(float *data);
}

int main() {
    return 0;
}
