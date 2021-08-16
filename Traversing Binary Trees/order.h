#ifndef ORDER_H
#define ORDER_H
#define TAM 10
struct arv{
    int info;
    struct arv *left, *right;
};
struct tree{
      int info;
      int used;
}node[TAM];
typedef struct arv *TREE;
TREE maketreeDinamic(int x);
void makeTreeSequential(int x);
void setLeftSequential(int p,int x);
void setRightSequential(int p,int x);
void inOrder(TREE p,int n);
void postOrder(TREE p,int n);
void preOrder(TREE p,int n);
#endif