#include <stdio.h>
#include <stdlib.h>
typedef struct p{
    int topo;
    char *pElem;
}Pilha;

Pilha *criarPilha(){
    
    Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
    aux->topo = -1;
    aux->pElem = (char *)malloc(300*sizeof(char));
    return aux;
}

void push( Pilha *p, char v){

	p->topo++;
	p->pElem[p->topo] = v;
}

int pop(Pilha *p){
    
    return p->pElem[p->topo--];
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

int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return 0;
}


void infixPosfix(char *ch){
	Pilha *q = criarPilha();
    char x;
	while(*ch != '\0'){
        if (*ch >= 'A' && *ch <= 'Z' || *ch >= '0' && *ch <= '9' || *ch >= 'a' && *ch <= 'z')
            printf("%c",*ch);
        else if(*ch == '(')
            push(q,*ch);
        else if(*ch == ')'){
            while((x = pop(q)) != '(')
                printf("%c", x);
        }else{
            while(prec(peek(q)) >= prec(*ch))
                printf("%c",pop(q));
            push(q,*ch);
        }
        ch++;
    }
    while(!isEmpty(q)){
        printf("%c",pop(q));
    }
}

int main(){
    char expr[300];
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",expr);
        infixPosfix(expr);
        printf("\n");
    }
 return 0;
}