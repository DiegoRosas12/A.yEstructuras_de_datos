
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
#define B0 1
#define B1 2
#define B2 4
#define B3 8
#define B4 16
 
typedef struct pc
{
    int n, i, ne;
    float *data;
    float cv, cll;
    char flag;
    float* (*crear)(int n);
    void (*liberar)(float *data);
    float (*pop)(struct pc *pc1);
    int (*push)(struct pc *pc1, float dato);
    int (*estado)(struct pc pc1);
}pc;
 
float* crear_mem(int n)
{
    return (float*)malloc(n*sizeof(float));
}
 
void liberar_mem(float *px)
{
    free(px);
}
 
float pop_pila1(pc *pc1)
{
    float dato;
    if (pc1->ne > 0)
    {
        dato = pc1->data[pc1->i];
        pc1->ne--;
        if(pc1->i)
            pc1->i--;
    }
    return dato;
}
 
int push_pila1(pc *pc1, float dato)
{
    if(!(pc1->flag&B4))
    {
    if (pc1->ne)
        pc1->i++;
    pc1->data[pc1->i] = dato;
    pc1->ne++;
    if(pc1->ne < (pc1->cv*pc1->n))
        pc1->flag=((pc1->flag^B1)^B2);

    return 0;
    }
    else
    {
        return 1;
    }
}
 
int estado(pc pc1)
{
    int tp, st;
    tp = pc1.flag&B0;
    printf("La ");
    if (tp)
        printf("cola esta ");
    else
        printf("pila esta ");
    switch ((pc1.flag)&(B1|B2|B3|B4)) //hacemos un and con 01111 para obtener 00001
    {
    case B1:
        printf("vacia. \n");
        break;
    case B2:
    printf("casi vacia. \n");
        break;
    case B3:
    printf("casi llena. \n");
        break;
    case B4:
    printf("llena. \n");
        break;
    default:
    printf("normal.\n");
    }
    return 0;
}
 
int main()
{
    pc pc1;
    int n, op;
    float dato;
    do {
        printf("Ingrese el numero de elementos: ");
        scanf("%d", &n);
    } while (n < 1);
    pc1.n = n;
    pc1.i = 0;
    pc1.ne = 0;
    pc1.crear = crear_mem;
    pc1.data = pc1.crear(pc1.n);
    if (pc1.data == NULL)
    {
        printf("Error al asignar la memoria.\n");
        return 1;
    }
    pc1.cv = 0.25;
    pc1.cll = 0.75;
    pc1.flag = B1;
    pc1.pop = pop_pila1;
    pc1.push = push_pila1;
    do {
        estado(pc1);
        printf("Seleccione la operacion: ");
        scanf("%d", &op);
        switch(op)
        {
        case 1:
            printf("Ingrese el valor del dato: ");
            scanf("%f", &dato);
            op = pc1.push(&pc1, dato);
            if (op)
                printf("Error en el push\n");
            break;
        default:
            dato = pc1.pop(&pc1);
            printf("Dato[%d]: %f\n", pc1.ne, dato);
            break;
        }
        printf("Desear realizr otra operación: ");
        scanf("%d", &op);
    } while (op);
    return 0;
}