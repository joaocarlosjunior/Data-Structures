#ifndef QUEUE_H
#define QUEUE_H

#define QUEUESIZE 2

enum vtypes{
    ELEMENT,
    INTEGER,
    FLOAT,
    CHARACTER,
    CHAR_POINTER
};

typedef enum vtypes values_types;

typedef struct queue FILA;

int initializeQueue(FILA*, int);

int isFull(FILA*);

int isEmpty(FILA*);

int toQueue(FILA* , ELEMENTO);

int deQueue(FILA* , ELEMENTO*);

#endif