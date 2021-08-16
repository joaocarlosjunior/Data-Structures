#include <stdlib.h>
#include "question.h"

void initialize(FILA* p){
  p->front = 0;
  p->rear = -1;
}

int insert(FILA* p, float x, int y){

  if(p->front == p->rear){
      printf("Overflow!");
      return 0;
  }else if(p->rear == TAM-1){
            p->note[p->rear] = x;
            p->grade[p->rear] = y;
            p->rear = 0;
  }else if(p->rear == -1){
            (p->rear)++;
            p->note[p->rear] = x;
            p->grade[p->rear] = y;
            (p->rear)++;
  }else{
        p->note[p->rear] = x;
        p->grade[p->rear] = y;
        (p->rear)++;
  }
}

int bubbleSort(FILA* q){
    float aux;
    int aux2;
    
      for(int i = 0;i < TAM;i++){
        for(int j = 0; j<TAM-1; j++){
            if(q->note[j] > q->note[j+1]){
              aux = q->note[j+1];
              aux2 = q->grade[j+1];
              q->note[j+1] = q->note[j];
              q->grade[j+1] = q->grade[j];
              q->note[j] = aux;
              q->grade[j] = aux2;
            }
         }
      }
}

void imprime(FILA* p){
    int j = TAM - 1;
    printf("|     Best notes:      |        Worse notes:    |\n");
        for(int i = 0; i<TAM/2;i++){
            printf("| Note:%.2f  grade:%d   | note:%.2f  grade:%d |\n", p->note[j], p->grade[j], p->note[i], p->grade[i]);
            j-=1;
          }
}

