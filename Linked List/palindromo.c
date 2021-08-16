#include <stdlib.h>
#include "palindromo.h"

LIST* lst_insere(LIST* list, char c) {
    LIST* new = (LIST*) malloc(sizeof(LIST));
    new->caract = c;
    new->next = list;
    new->prev = NULL;
    
    if (list != NULL){
        list->prev = new; 
    }
    
 return new;
}   

void printList(LIST* list){
    LIST* p; 
        for(p = list; p != NULL; p = p->next){
            printf ( "%c", p->caract ) ;
    }   
}

int interativePali(LIST* left){
    LIST *left1 = left;
    LIST *right1 = left;
    LIST *prev = NULL;
    LIST *temp;
    while (right1 != NULL && right1->next != NULL) {
 
         right1 = right1->next->next;
 
          temp = left1;
          left1 = left1->next;
  
          temp->next = prev;
           prev = temp;
       }
 
         if (right1 != NULL) {
           left1 = left1->next;
         }
 
         while (prev != NULL && left1 != NULL) {
             if (prev->caract != left1->caract) {
                  return 0;
             }
 
             prev = prev->next;
             left1 = left1->next;
         }
        int result = (prev == NULL && left1 == NULL);
        return result;
}

int recursivePali(LIST **left, LIST *right){
    
    if (right == NULL) {
        return 1;
    }
 
    int temp = recursivePali(left, right->next);
        if(temp == 0){
            return 0;
        }
    
    int temp2 = ((*left)->caract == right->caract);
    (*left) = (*left)->next;
 
    return temp2;
}