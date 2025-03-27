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

void createEmptyStack(tStack* S) {
    S->top = SNULL;
}

bool push(tItemS d, tStack* S) {
    if(S->top == SMAX-1) {
        return false;
    }else{
        S->top++;
        S->data[S->top] = d;
        return true;
    }
}

bool isEmptyStack(tStack S) {
    return (S.top == SNULL);
}

void pop(tStack* S){
        S->top--;
}

tItemS peek(tStack S) {
    return S.data[S.top];
}
