#include <stdlib.h>
#include <math.h>
#include "element.h"

struct element{
    int etype;/*etype equivale a INTGR FLT CHAR ou STRING*/
    union{
        int ival;
        float fval;
        char cval;
        char *sval; /*ponteiro para uma sring*/
    }value;
};