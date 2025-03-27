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
    S->top = SNULL;
}

bool isemptystack(tStackL S) {
    return (S.top == SNULL);
}

bool push(tItemS item, tStackL* S) {
    if(S->top == SMAX-1) {
        return false;
    }else{
        S->top++;
        S->data[S->top] = item;
    }
}

void pop(tStackL* S){
        S->top--;
}

tItemS peek(tStackL S) {
    return S.data[S.top];
}

tItemS peek(tStackL S) {
    return S->data;

}
