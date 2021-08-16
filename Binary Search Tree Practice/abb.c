#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abb.h"

//inserir na arvore
TREE *insert(TREE *p, int x){
    if(p == NULL){
        p = getnode();
        p->info = x;
        p->left = NULL;
        p->right = NULL;
    }else if(x < p->info){
            p->left = insert(p->left,x);
        }else if(x > p->info){
                p->right = insert(p->right,x);
            }    
    return p;
}
//retornar o valor na arvore
int returnValue(TREE *p){
    return p->info;
}
//O nivel maximo da arvore
int maxLevel(TREE *p) {
   int heightLeft;
   int heightRight;
   if(p == NULL){
       return 0;
   }else{
      heightLeft = maxLevel(p->left);
      heightRight = maxLevel(p->right);
      if(heightLeft > heightRight){
        return (heightLeft + 1);  
      }else{
          return (heightRight + 1);
      } 
   }
}
//O nivel minimo da arvore
int underLevel(TREE *p){
	int minLeft;
    int minRight;
    if(p == NULL){
		return 0;
	}
	minLeft = underLevel(p->left);
	minRight = underLevel(p->right);
	if(minLeft == minRight){
		return (minLeft + 1);
	}else if(minLeft > minRight){
		if(minRight != 0){
			return (minRight + 1);
		}
		else{
			return (minLeft + 1);
		}
	}else{
		if(minLeft != 0){
			return (minLeft + 1);
		}
		else{
			return (minRight + 1);
		}
	}
}
//Exibe a arvore em ordem
void showTree(TREE *p){
    if(p != NULL){
       showTree(p->left);
       printf("Valor: %d\n", p->info);
       showTree(p->right);
    }
}
//Contagem de diferenca entre nivel maximo e minimo
void score(int *q){
    int i,key, j;
    int cont;
    //Ordenado utilizando insertion sort
    for(i = 1; i < 50; i++){
        key = q[i];
        j = i - 1;
        while(j >= 0 && q[j] > key){
            q[j + 1] = q[j];
            j = j - 1;
        }
        q[j + 1] = key;
    }
    
    i = 0;
    cont = 1;
    for(i = 1;i < 51;i++){
        if(q[i] == q[i-1]){
            cont++;
        }else if(q[i - 1] == 0){
                printf("A %d arvore(s) com nenhuma diferenca\n",cont);
                cont = 1;
            }else{
                printf("A %d arvore(s) com %d de diferenca\n",cont,q[i - 1]);
                cont = 1;
                }
    }
}
//Libera a arvore da memoria
TREE *freeTree(TREE *p){
    if(p != NULL){
        p->left = freeTree(p->left);
        p->right = freeTree(p->right);
        free(p);
    }
    return NULL;
}
//Gera e inseri numeros aleatorios na arvore
void numbers(){
    TREE *No;
    int cont[50];
    No = initializeTree();
    srand(time(NULL));
       
       //"Cria" 50 árvores com numeros aleatorios
       for(int i = 0; i < 50;i++){
            for(int j = 0; j < 100; j++){//Gera e insere 100 números aleatórios na árvore
                int x = (1 + rand()%1000);
                //printf("--Number: %d --\n",x);
                No = insert(No, x);
                if(j == 99){
                    showTree(No);//Exibe a arvore em ordem
                    printf("Maior nivel: %d\n",maxLevel(No));
                    printf("Menor nivel: %d\n",underLevel(No));
                    cont[i] = maxLevel(No) - underLevel(No);//Diferenca entre maior e menor nivel
                    No = freeTree(No);//Libera a arvore
                    printf("---------------\n");
                }
            }
       }
    printf("    -CONTAGEM-    \n");
    score(cont);
    printf("\n"); 
}
