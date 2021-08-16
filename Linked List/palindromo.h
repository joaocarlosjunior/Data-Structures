#ifndef PALINDROMO_H
#define PALINDROMO_H

typedef struct List_Enc {
    char caract;
    struct List_Enc *next;
    struct List_Enc *prev;
};

typedef struct List_Enc LIST;
void lst_imprime(LIST* list);
int interativePali(LIST* left);
int recursivePali(LIST **left, LIST *right);

#endif