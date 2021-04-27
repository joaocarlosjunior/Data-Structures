#include <stdlib.h>
#include <math.h>
#include "element.c"
#include "queue.h"

struct queue{
    int etype, front, rear;//*Inteiro para inicio e fim da fila.
    ELEMENTO itens[QUEUESIZE];
};

//*Referencia para uma fila e seu tipo
int initializeQueue(FILA* x, int ETYPE){//*Inicilazar a fila.
    x->etype = ETYPE;//*Ver o tipo da fila(Ex:Element,inteiro,float,char etc).
    x->rear = x->front = -1;//*Iniciliza inicio e fim com -1 para aproveitar o espaço total da array.

    return 1;
}

//*
int isFull(FILA* x){//*Função para verificar se estar cheio.
    return (x->rear == x->front && x->rear != -1);//Indice do inicio e do final forem iguais e além disso forem diferentes de -1 
}

int isEmpty(FILA* x){//*Função para verificar se estar vazio
    return (x->rear == x->front && x->rear == -1);
}

int toQueue(FILA* x, ELEMENTO e){//*Enfileirar
    if(isFull(x)){//*Verificar se estar cheia
        printf("\n\n----> queue overflow <----\n\n");
        return 0;
    }

    if(isEmpty(x)) x->front = QUEUESIZE - 1;//*Verificar se estar vazia

    if(x->rear == QUEUESIZE - 1) x->rear = 0;//*Quando coincidir de final da fila chegar no final do vetor ele volta pro inicio do vetor.
    else (x->rear)++;

    x->itens[x->rear] = e;//*Atribui o elemento na vetor

    return 1;
}

int deQueue(FILA* x, ELEMENTO* e){//*Desinfileirar
    if(isEmpty(x)){//*Verificar se não estar vazio
        printf("\n\n----> queue empty <----\n\n");
        return 0;
    }

    if (x->front == QUEUESIZE - 1) x->front = 0;//*Se chegar no limite do vetor volta para o inicio do vetor.
    else (x->front)++;

    *e = x->itens[x->front];//*Retira do inicio e atribui no vetor

    if (x->front == x->rear) initializeQueue(x,x->etype);//*Quando fila estiver vazia depois de desinfileirar os valores de front e rear serão -1.

    return 1;
}