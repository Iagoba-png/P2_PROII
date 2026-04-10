/*
* TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "committee_list.h"
#include "string.h"

void createEmptyListC(tListC *L) {
    //Crea una lista vacía.
    L->lastPos = NULLC;
}

bool isEmptyListC(tListC L) {
    //Determina si una lista está vacía.
    return L.lastPos == NULLC;
}

tPosC firstC(tListC L) {
    //Devuelve la posición del primer elemento de la lista.
    return 0;
}

tPosC lastC(tListC L) {
    //Devuelve la posición del último elemento de la lista.
    return L.lastPos;
}

tPosC nextC(tPosC p, tListC L) {
    //Devuelve la posición del siguiente elemento al de la posición recibida.
    if (p == L.lastPos) {
        //La última posición no tiene siguiente.
        return NULLC;
    } else {
        return (++p);
    }
}

tPosC previousC(tPosC p, tListC L) {
    //Devuelve la posición del anterior elemento al de la posición recibida.
    return --p;
}

bool insertItemC(tItemC d, tListC *L) {
    tPosC i;

    if (L->lastPos == MAX - 1) {
        return false;
    } else {

        L->lastPos++;
        if (isEmptyListC(*L) || (strcmp(d.committeeName, L->data[L->lastPos].committeeName) < 0)) {
            L->data[L->lastPos] = d;
        } else {

            for (i = L->lastPos; (i > 0) && (strcmp(d.committeeName, L->data[i - 1].committeeName) < 0); i--) {
                L->data[i] = L->data[i - 1];
            }
            L->data[i] = d;
        }
        return true;
    }
}

void deleteAtPositionC(tPosC p, tListC *L) {
    //Elimina el elemento de la posición seleccionada.
    tPosC i;
    L->lastPos--;

    for (i = p; i <= L->lastPos; i++) {
        //Reordena el array.
        L->data[i] = L->data[i + 1];
    }
}

tItemC getItemC(tPosC p, tListC L) {
    //Devuelve el valor del elemento de la posición seleccionada.
    return L.data[p];
}

void updateItemC(tItemC d, tPosC p, tListC *L) {
    //Da un nuevo valor al elemento de la posición seleccionada.
    L->data[p] = d;
}

tPosC findItemC(tCommitteeName name, tListC L) {
    //Devuelve el elemento cuyo nombre coincida con el seleccionado.
    tPosC p;

    if (L.lastPos == NULLC) {
        //Lista vacía, no existe.
        return NULLC;
    }

    for (p = 0; (p <= L.lastPos) && (strcmp(L.data[p].committeeName, name) < 0); p++) {
    }
    //Recorre el array.
    if (strcmp(L.data[p].committeeName, name) == 0) {
        return p;
    }
    return NULLC; //No se ha encontrado, no existe.
}
