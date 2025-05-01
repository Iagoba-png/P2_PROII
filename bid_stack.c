/*
* TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Iago Bescansa Alcoba LOGIN 1: iago.alcoba
 * AUTHOR 2: Daniel Marrero Sánchez LOGIN 2: daniel.marrero.sanchez
 * GROUP: 1.2
 * DATE: 30 / 04 / 2025
 */

#include "bid_stack.h"

/* Write your code here... */

void createEmptyStack(tStack* S) {//Inicializa top en -1
    S->top = SNULL;
}

bool push(tItemS d, tStack* S) {//Introduce un elemento en el stack
    if(S->top == SMAX-1) {//Comprueba si la lista está llena
        return false;
    }else{
        S->top++;
        S->data[S->top] = d;
        return true;
    }
}

bool isEmptyStack(tStack S) {//Compara el valor de top con -1
    return (S.top == SNULL);
}

void pop(tStack* S){//Elimina el primer elemento del stack
    if (isEmptyStack(*S)!=true)
    {
        S->top--;
    }
}

tItemS peek(tStack S) {//Devuelve el primer elemento del stack
    if (isEmptyStack(S)!=true){
        return S.data[S.top];
    }
}
