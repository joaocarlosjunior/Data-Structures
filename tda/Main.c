#include <stdio.h>
#include <stdlib.h>
#include "Ponto.c"

int main(){
    Ponto *p;
    float a,b;
    
    p = pto_create(5, 7);

    
    pto_get(p, &a, &b);
    
    printf("a = %.2f\nb = %.2f",a,b);
    
    return 0;
}