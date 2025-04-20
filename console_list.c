/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Iago Bescansa Alcoba LOGIN 1: iago.alcoba
 * AUTHOR 2: Daniel Marrero Sánchez LOGIN 2: daniel.marrero.sanchez
 * GROUP: 1.2
 * DATE: ** / ** / **
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


  while(Q->next != LNULL){ //Recorre la lista hasta encontrarse con el final de esta, devolviendo el valor anterior.
      Q = Q->next;
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
    while (Q->next!=p){
      Q=Q->next;
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

void updateItem( tItemL d, tPosL p, tList* L) {
  if (p!=LNULL) {//Condiciones para que se actualice el elemento
    p->data = d;
  }
}


bool insertItem (tItemL d, tList* L){
  tPosL P=LNULL;
  P=malloc(sizeof(tNode));
  P->data=d;
  P->next=LNULL;

  if (isEmptyList(*L)==true) {
    *L=P;
    return true;
  }

  tPosL Q = findItem(P->data.consoleId,*L);

  if (Q==LNULL) {//Caso de que d sea un nuevo item
    tPosL R = nextOrderId(d.consoleId,*L);
    if (R==LNULL) {//
      tPosL T = last(*L);
      T->next=P;
    }
    else {
      tPosL Y=previous(R,*L);
      if (Y==LNULL) {
        P->next=R;
        *L=P;
      }
      else {
        Y->next=P;
        P->next=R;
      }
    }
    return true;
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
    else {//Si es la primera casilla L pasa a apuntar a la siguiente y borra la seleccionada por p
      *L=(*L)->next;
      free(p);
    }
  }
}

tItemL getItem (tPosL p, tList L){//Obtiene el elemento apuntado por p
  return p->data;
}

tPosL findItem(tConsoleId a, tList L){//Busca una consola por su id

  for (tPosL Q=L;Q!=LNULL;Q=Q->next){//Escanea la lista al completo si no encuentra "a"
    if (strcmp(Q->data.consoleId, a)==0) {//Si encuentra "a" devuelve un puntero a su casilla
      return Q;
    }
  }

  return LNULL;////Si no encuentra "a" devuelve un valor nulo

}

tPosL nextOrderId(tConsoleId d, tList L) {
  for (tPosL Q=L;Q!=LNULL;Q=Q->next){//Escanea la lista al completo si no encuentra "d"
    if (strcmp(Q->data.consoleId, d)>0) {//Si encuentra un id mayor que "d" devuelve un puntero a su casilla
      return Q;
    }
  }

  return LNULL;////Si no encuentra "d" devuelve un valor nulo
}