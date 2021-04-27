#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Ponto.h"

typedef struct ponto{
    float x;
    float y;
};

//Function to add the values ​​to the structure
Ponto* pto_create(float x, float y){
    Ponto* p = (Ponto *) malloc(sizeof(Ponto));

    if(p != NULL){
        p->x = x;
        p->y = y; 

    }
    return p;
}
//Function to get the values ​​of the structure
void pto_get(Ponto *p, float *x, float *y){
    *x = p->x;
    *y = p->y;
}