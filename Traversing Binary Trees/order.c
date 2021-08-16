#include <stdio.h>
#include "order.h"

//inserir na arvore dinamica
TREE maketreeDinamic(int x){
    TREE p = (TREE)malloc(sizeof(struct arv));
    p->info = x;
    p->right = NULL;
    p->left = NULL;
    return p;
}
//Insere primeira info na arvore sequencial
void makeTreeSequential(int x){
    node[0].info = x;
    node[0].used = 1;
    for(int i = 1;i < TAM;i++){
        node[i].used = 0;
    }
}
//Insere lado esquerdo da arvore
void setLeftSequential(int p,int x){
    int q;
    
    q = 2 * p + 1;
    if (q > TAM){
        printf("Estouro do vetor\nUltimo numero nao inserido\n");
    }else if(node[q].used)
        printf("Insercao incorreta\n");
    else{
        node[q].info = x;
        node[q].used = 1;
    } 
}
//Insere lado direito da arvore
void setRightSequential(int p,int x){
    int q;
    
    q = 2 * p + 2;
    if(q > TAM){
        printf("Estouro do vetor\nUltimo numero nao inserido\n");
    }else if(node[q].used)
        printf("Insercao incorreta\n");
    else{
        node[q].info = x;
        node[q].used = 1;
    }
    
}
//Pecorre a arvore em ordem
void inOrder(TREE p,int n){
    
    if(node[n].used){
        inOrder(p,2*n+1);
        printf(" %d ",node[n].info);
        inOrder(p,n*2+2);
    }

    if(p != NULL){
       inOrder(p->left,n);
       printf(" %d ", p->info);
       inOrder(p->right,n);
    }
}
//Pecorre a arvore Pos ordem
void postOrder(TREE p,int n){
    
    if(node[n].used){
        postOrder(p,2*n+1);
        postOrder(p,n*2+2);
        printf(" %d ",node[n].info);
    }

    if(p != NULL){
       postOrder(p->left,n);
       postOrder(p->right,n);
       printf(" %d ", p->info);
    }
}
//Pecorre a arvore Pre ordem
void preOrder(TREE p,int n){

    if(node[n].used){
        printf(" %d ",node[n].info);
        preOrder(p,2*n+1);
        preOrder(p,2*n+2);
    }

    if(p != NULL){
       printf(" %d ", p->info);
       preOrder(p->left,n);
       preOrder(p->right,n);
    }
}