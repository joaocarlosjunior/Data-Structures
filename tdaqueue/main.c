#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.c"

int main(){
    FILA teste;
    ELEMENTO el;

    el.value.ival = 10;

    initializeQueue(&teste, INTEGER);

    if(isFull(&teste)) printf("\ncheia\n");
    if(isEmpty(&teste)) printf("\nvazia\n");

    toQueue(&teste, el);

    if(isFull(&teste)) printf("\ncheia\n");
    if(isEmpty(&teste)) printf("\nvazia\n");

    el.value.ival = 20;

    toQueue(&teste, el);

    if(isFull(&teste)) printf("\ncheia\n");
    if(isEmpty(&teste)) printf("\nvazia\n");

    deQueue(&teste, &el);
    printf("\n%d\n", el.value.ival);
    if(isFull(&teste)) printf("\ncheia\n");
    if(isEmpty(&teste)) printf("\nvazia\n");

    deQueue(&teste, &el);
    printf("\n%d\n", el.value.ival);
    if(isFull(&teste)) printf("\ncheia\n");
    if(isEmpty(&teste)) printf("\nvazia\n");

    deQueue(&teste, &el);
    if(isFull(&teste)) printf("\ncheia\n");
    if(isEmpty(&teste)) printf("\nvazia\n");
    printf("\n%d\n", el.value.ival);


    printf("\n\n");
    system("pause");
    return 0;

}