#include<stdio.h>
#include<stdlib.h>
#include "question.c"

int main(){
  FILA q[TAM];
  initialize(q);

    insert(q,8.5,20201251);
    insert(q,5.5,20201252);
    insert(q,8.0,20201253);
    insert(q,9.0,20201254);
    insert(q,4.5,20201255);
    insert(q,3.5,20201256);
    
    bubbleSort(q);
    imprime(q);

  return 0;
}