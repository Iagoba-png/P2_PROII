/*
* TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "project_list.h"
#include <stdlib.h>
#include <string.h>

void createEmptyListP(tListP *L) {        //Crea una lista vacía.
    *L = NULLP;
}

bool createNode(tPosP *p) {
    *p = malloc(sizeof(struct tNode));

    return *p != NULLP; //True si p apunta a algo no nulo (un nodo).
}

tPosP findPosition(tItemP d, tListP L) {
    tPosP p;
    p = L;

    while ((p->next != NULLP) && (strcmp(p->next->data.projectName, d.projectName) < 0)) {
        p = p->next;
    }
    return p;
}

bool insertItemP(tItemP d, tListP *L) {
    tPosP p, q;

    if (!createNode(&q)) {
        return false;
    }else {
        q->data = d;
        q->next = NULLP;
    }
    if (*L == NULLP) {
        *L = q;
    }else if (strcmp(d.projectName, (*L)->data.projectName) < 0) {
        q->next = *L;
        *L = q;
    }else {
        p = findPosition(d, *L);
        q->next = p->next;
        p->next =q;
    }
    return true;
}

void updateItemP(tItemP d, tPosP p, tListP *L) {      //Da un nuevo valor al elemento de la posición seleccionada.
    p->data = d;
}

void deleteAtPositionP(tPosP p, tListP *L) {      //Elimina el elemento de la posición seleccionada.
    tPosP q;

    if (p == *L) {      //Eliminar el primer nodo.
        *L = (*L)->next;
    } else if (p->next == NULLP) {      //Eliminar el último nodo.
        for (q = *L; q->next != p; q = q->next) {
        }
        q->next = NULLP;
    } else {        //Eliminar nodo intermedio.
        q = p->next;
        p->data = q->data;
        p->next = q->next;
        p = q;      //Para que free elimine el nodo correcto.
    }
    free(p);
}

tPosP findItemP(tProjectName name, tListP L) {
    tPosP p;

    for (p = L; (p != NULLP) && (strcmp(p->data.projectName, name) < 0); p = p->next){}
    if (p != NULLP && strcmp(p->data.projectName, name) == 0) {
        return p;
    }else {
        return NULLP;
    }
}

bool isEmptyListP(tListP L) {         //Determina si una lista está vacía.
    return L == NULLP;
}

tItemP getItemP(tPosP p, tListP L) {      //Devuelve el valor del elemento de la posición seleccionada.
    return p->data;
}

tPosP firstP(tListP L) {             //Devuelve la posición del primer elemento de la lista.
    return L;
}

tPosP lastP(tListP L) {               //Devuelve la posición del último elemento de la lista.
    tPosP p;

    for (p = L; p->next != NULLP; p = p->next) {        //Recorre la lista de principio a fin.
    }
    return p;
}

tPosP previousP(tPosP p, tListP L) {      //Devuelve la posición del anterior elemento al de la posición recibida.
    tPosP q;

    if (p == L) {       //p es la primera posición.
        return NULLP;
    } else {
        for (q = L; q->next != p; q = q->next) {        //Recorre la lista desde el principio de la lista hasta la posición previa.
        }
        return q;
    }
}

tPosP nextP(tPosP p, tListP L) {      //Devuelve la posición del siguiente elemento al de la posición recibida.
    return p->next;
}
