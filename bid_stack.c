/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "bid_stack.h"

/* Write your code here... */

void createemptystack(tStackL* S) {
    *S=SNULL;
}

bool isemptystack(tStackL S) {
    return (S==SNULL);
}

bool createnode(tPosS* p) {
    *p=malloc(sizeof(struct tNodeS));
    return (*p!=SNULL);
}

bool push(tItemS item, tStackL* S) {
    tPosS aux;
    if (!createnode(&aux)) {
        return false;
    }else {
        aux->data=item;
        aux->down=*S;
        *S=aux;
        return true;
    }
}

void pop(tStackL* S) {
    tPosS aux;
    *S=(*S)->down;
    free(aux);
}

tItemS peek(tStackL S) {
    return S->data;

}
