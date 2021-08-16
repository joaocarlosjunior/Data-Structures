#include <stdio.h>
#include <stdlib.h>

typedef struct p{
    int topo;
    int *pElem;
}Pilha;

Pilha *criarPilha(){
    
    Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
    aux->topo = -1;
    aux->pElem = (int *)malloc(1000*sizeof(int));
    return aux;
}

void push( Pilha *p, int v){

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

int main(){
    int n,vet[1000],max;
    int i,j,flag;
    Pilha *p;

    while(scanf("%d",&n)){
        if(n == 0){
            break;
        }
        while(scanf("%d",&vet[0])){
            if(vet[0] == 0){
                break;
            }
            for(i = 1;i < n;i++){
                scanf("%d",&vet[i]);
            }
            flag = 1;
            p = criarPilha();
            max = vet[0];

            for(i = 1;i < vet[0];i++){
                push(p,i);
            }
            for(i = 1;i < n;i++){
                if(max < vet[i]){
                    for(j = max+1;j < vet[i];j++){
                        push(p,j);
                    }
                    max = vet[i];
                }else{
                    if(vet[i] == peek(p)){
                        pop(p);
                    }else{  
                        flag = 1;
                        break;
                    }
                }
            }
            if(isEmpty(p) == 0){
                flag = 0;
            }
            if(flag){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
        printf("\n");
    }
    return 0;
}