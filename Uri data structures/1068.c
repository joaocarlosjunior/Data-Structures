#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p{
    int topo;
    char *pElem;
}Pilha;

Pilha *criarPilha(){
    
    Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
    aux->topo = -1;
    aux->pElem = (char *)malloc(1000*sizeof(char));
    return aux;
}

void push( Pilha *p, char v){

	p->topo++;
	p->pElem[p->topo] = v;
}

void pop(Pilha *p){
	
    p->topo--;
}

int isEmpty(Pilha *p){
    
    if(p->topo == -1){
        return 1;
    }else{
        return 0;
    }          
}

int peek(Pilha *p){
    
    return p->pElem[p->topo];
}

int verificaPares(char o,char c){
	if(o == '(' && c == ')'){
        return 0;
    }else{
        return 1;
    }
}

int verifica(char *exp){
    Pilha *p;
    p = criarPilha();
    int i;
    int tam = strlen(exp);
	for(i = 0;i < tam;i++){
		if(exp[i] == '('){
            push(p,exp[i]);
        }
		else if(exp[i] == ')'){
			if(isEmpty(p) || verificaPares(peek(p),exp[i])){
				return 0;
            }
			else{
                pop(p);
            }
		}
	}
    if(isEmpty(p)){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char expr[1000];

	while(scanf("%s", expr) != EOF){

		if(verifica(expr)){
			printf("correct\n");
        }
		else{
            printf("incorrect\n");
        }
    }
    return 0;
}