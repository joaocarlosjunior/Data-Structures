#ifndef ABB_H
#define ABB_H
struct arv{
    int info;
    struct arv *left, *right, *father;
};
typedef struct arv TREE;

TREE *getnode(){
    TREE *t;
    t = (TREE *) malloc(sizeof(TREE));
    return t;
}
TREE *initializeTree(){
    return NULL;
}
TREE *insert(TREE *a, int v);
int returnValue(TREE *p);
int maxLevel(TREE *p);
int underLevel(TREE *p);
void showTree(TREE *p);
void score(int *q);
TREE *freeTree(TREE *p);
void numbers();
#endif