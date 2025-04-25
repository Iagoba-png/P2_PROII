/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Iago Bescansa Alcoba LOGIN 1: iago.alcoba
 * AUTHOR 2: Daniel Marrero Sánchez LOGIN 2: daniel.marrero.sanchez
 * GROUP: 1.2
 * DATE: 25 / 04 / 2025
 */

#include "console_list.h"

/* Write your code here... */

void createEmptyList (tList* L){ //Inicializa la lista nula.
  *L=LNULL;
}

bool isEmptyList (tList L) { // Comprueba si la lista se encuentra nula.
    return L == LNULL;
}

tPosL first(tList L) { //Devuelve el primer elemento de la lista
  tPosL P;
  P=LNULL;
  P=L;

  return P;
}

tPosL last(tList L) { //Devuelve el último elemento de la lista.

  tPosL Q=L;


  while(next(Q,L) != LNULL){ //Recorre la lista hasta encontrarse con el final de esta, devolviendo el valor anterior.
      Q = next(Q,L);
    }
    return Q;
}

tPosL previous(tPosL p, tList L) { //Devuelve el anterior elemento del seleccionado.
  if (p == LNULL||p==first(L)) { //En caso inválido devuelve nulo.
      return LNULL;
  }
  else{  //En caso correcto, recorre la lista hasta encontrar un elemento, para devolver su anterior.
    tPosL Q=LNULL;
    Q=L;
    while (next(Q,L)!=p){
      Q=next(Q,L);
    }
    return Q;
  }
}

tPosL next(tPosL p, tList L) { //Si la posición introducida es la última o nula devuelve LNULL, si no devuelve la siguiente posición
  if (p == LNULL) {
    return LNULL;
  }
  else {
      return p->next;
  }
}

void updateItem( tItemL d, tPosL p, tList* L) {//Actuliza una posición
  if (p!=LNULL) {//Condiciones para que se actualice el elemento
    p->data = d;
  }
}


bool insertItem (tItemL d, tList* L){
  tPosL Q;
  Q = findItem(d.consoleId,*L);

  if(Q==LNULL) {
    tPosL p=LNULL;
    p=nextOrderId(d.consoleId,*L);
    tPosL M;
    M=LNULL;
    M=malloc(sizeof(tNode));//Creación de una nueva casilla
    M->data=d;
    M->next=LNULL;
    if (p!=LNULL) {//Condición de p no nulo
      if (p==*L){//Caso específico de que p apunte al primer elemento
        M->next=*L;//La nueva casilla apunta a la antigua primera casilla
        *L=M;//La nueva casilla se convierte en la primera
        return true;
      }
      tPosL R;
      R=LNULL;
      R=previous(p,*L);//R apunta al elemento anterior de p
      M->next=p;//La nueva casilla apunta a la posicion p
      R->next=M;//La nueva casilla es la siguiente a la apuntada por R
      return true;
    }
    if (p==LNULL) {//Caso p=NULL
      if (isEmptyList(*L)==true) {//Caso de que sea la primera casilla
        *L=M;
        return true;
      }
      if (isEmptyList(*L)==false) {
        tPosL S;
        S=last(*L);//S apunta a la última casilla
        S->next=M;//T se coloca después de la última casilla
        return true;
      }
    }
  }

  return false;
}


void deleteAtPosition(tPosL p, tList* L){//Borra una casilla
  if(p->data.bidCounter==0){
    tPosL q;
    q=previous(p,*L);//Selecciona la anterior, la enlaza con la siguiente a p y borra la seleccionada por p
    if (q!=LNULL) {
      q->next=p->next;
      free(p);
    }
    else {//Si p es la primera casilla L pasa a apuntar a la siguiente y borra la seleccionada por p
      *L=p->next;
      free(p);
    }
  }
}

tItemL getItem (tPosL p, tList L){//Obtiene el elemento apuntado por p
  return p->data;
}

tPosL findItem(tConsoleId a, tList L){//Busca una consola por su id
  tPosL Q;
    if (L!=LNULL){
    for (Q=L;Q!=LNULL;Q=Q->next){//Escanea la lista al completo si no encuentra "a"
      if (strcmp(Q->data.consoleId, a)==0) {//Si encuentra "a" devuelve un puntero a su casilla
        return Q;
      }
    }
  }
  Q=LNULL;

  return Q;////Si no encuentra "a" devuelve un valor nulo

}

tPosL nextOrderId(tConsoleId d, tList L) {
  tPosL Q=LNULL;
  Q=first(L);//Creción de Q, que apunta al primer elemnto de la lista
  while (Q!=LNULL){//Escanea la lista al completo si no encuentra "d"
    if (strcmp(Q->data.consoleId, d)>0) {//Si encuentra un id mayor que "d" devuelve un puntero a su casilla
      return Q;
    }
    Q=next(Q,L);
  }

  return LNULL;////Si no encuentra "d" devuelve un valor nulo
}