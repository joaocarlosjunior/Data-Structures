#ifndef FILA_H
#define FILA_H
#define TAM 6

typedef struct alunos{
  int front;
  int rear;
  float note[TAM];
  int grade[TAM];
}FILA;

void initialize(FILA* p);
int insert(FILA* p, float x, int y);
int bubbleSort(FILA* q);
void imprime(FILA* p);
#endif