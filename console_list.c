/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
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

void updateItem( tItemS d, tPosL p, tList* L) {
  if (p!=LNULL) {//Condiciones para que se actualice el elemento
    p->data = d;
  }
}

bool checkPointer(tPosL p, tList L) {//Comprueba si el puntero p apunta a la lista L

  if (p==L) {
    return true;
  }

  tPosL Q;


  for(Q=L;Q->next!=p && Q->next!=LNULL;Q=Q->next);//Recorre toda la lista en busca de p, si no lo encuentra Q=last(L) y devuelve false
  if(Q!=last(L)) {
    return true;
  }

  return false;


}

bool insertItem (tItemS d, tPosL p, tList* L){

  if (p!=LNULL&&checkPointer(p,*L)==true) {//Condición de p no nulo y apuntando a L
    if (p==*L){//Caso específico de que p apunte al primer elemento
      tPosL M;
      M=LNULL;
      M=malloc(sizeof(tNode));//Creación de una nueva casilla
      M->data=d;
      M->next=*L;//La nueva casilla apunta a la antigua primera casilla
      *L=M;//La nueva casilla se convierte en la primera

      return true;
    }
    tPosL R, Y;
    R=LNULL;
    Y=malloc(sizeof(tNode));//Creación de una nueva casilla
    R=previous(p,*L);//R apunta al elemento anterior de p
    Y->next=p;//La nueva casilla apunta a la posicion p
    Y->data=d;
    R->next=Y;//La nueva casilla es la siguiente a la apuntada por R
    return true;
 }
  if (p==LNULL) {//Caso p=NULL
    tPosL T;
    T=LNULL;
    T=malloc(sizeof(struct tNode));//Creación de una nueva casilla
    T->data=d;
    T->next=LNULL;
    if (isEmptyList(*L)==true) {//Caso de que sea la primera casilla
      *L=T;
      return true;
    }
    if (isEmptyList(*L)==false) {
      tPosL S;
      S=last(*L);//S apunta a la última casilla
      S->next=T;//T se coloca después de la última casilla
      return true;
    }
  }

    return false;
}


void deleteAtPosition(tPosL p, tList* L){//Borra una casilla
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

tItemS getItem (tPosL p, tList L){//Obtiene el elemento apuntado por p
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
