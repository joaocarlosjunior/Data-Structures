#include <stdio.h>
#include <stdlib.h>
#include "order.c"

int main(){
    TREE arv = NULL;
    int control;
    
    printf("Arvore dinamica   - 1 -\n");
    printf("Arvore estatica   - 2 -\n");
    scanf("%d",&control);
    
    switch(control){
        case 1:
            //        4         //
            //       / \        //
            //      3   7       //
            //         / \      //
            //        5   10    //
            arv = maketreeDinamic(4);
            arv->left = maketreeDinamic(3);
            arv->right = maketreeDinamic(7);
            arv->right->right = maketreeDinamic(10);
            arv->right->left = maketreeDinamic(5);

            printf("\n-Dinamica-");
            printf("\nEm ordem:");
            inOrder(arv,0);
            printf("\nPos - ordem:");
            postOrder(arv,0);
            printf("\nPre - ordem:");
            preOrder(arv,0);
            free(arv);
            break;
        case 2:
            //        4         //
            //       / \        //
            //      3   7       //
            //         / \      //
            //        5   10    //
            makeTreeSequential(4);
            setLeftSequential(0,3);
            setRightSequential(0,7);
            setLeftSequential(2,5);
            setRightSequential(2,10);
            
            printf("\n-Estatica-");
            printf("\nEm ordem:");
            inOrder(arv,0);
            printf("\nPos - ordem:");
            postOrder(arv,0);
            printf("\nPre - ordem:");
            preOrder(arv,0);
            free(node);
            break;
        default:
            printf("Opcao errada!!");
            break;
    }
    return 0; 
}