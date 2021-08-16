#include <stdio.h>
#include "palindromo.c"

int main()
{
 LIST* lista = NULL;
 lista = lst_insere(lista,'m');
 lista = lst_insere(lista,'a');
 lista = lst_insere(lista,'m');
 lista = lst_insere(lista,'a');
 lista = lst_insere(lista,'m');
 
 LIST* listaAux = NULL;
 listaAux = lst_insere(listaAux,'a');
 listaAux = lst_insere(listaAux,'r');
 listaAux = lst_insere(listaAux,'a');
 listaAux = lst_insere(listaAux,'r');
 
 printList(lista);
    
    if (interativePali(lista)) {
        printf("-Interativo- eh um palindromo\n");
    } else {
        printf(" -Interativo- nao eh um palindromo\n");
    }
 
 printList(listaAux);
    
    if (interativePali(listaAux)) {
        printf("-Interativo- eh um palindromo\n");
    } else {
        printf("-Interativo- nao eh um palindromo\n");
    }
    
    free(lista);
    free(listaAux);

 return 0;
}