#ifndef PONTO_H
#define PONTO_H

typedef struct ponto Ponto;

Ponto* pto_create(float x,float y);//função para manipular o "Ponto"

void pto_get(Ponto* p, float* x, float* y);



#endif