/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Iago Bescansa Alcoba LOGIN 1: iago.alcoba
 * AUTHOR 2: Daniel Marrero Sánchez LOGIN 2: daniel.marrero.sanchez
 * GROUP: 1.2
 * DATE: 25 / 04 / 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "console_list.h"

#define MAX_BUFFER 255
float average(float total, int num){//Devuelve la media
    if(num==0){return 0;}
    return total/num;
}

float priceRatio(tItemL d){//Devuelve la diferencia porcentual entre el precio original y la puja más alta
    if (isEmptyStack(d.bidStack)==false){
        return 100*((peek(d.bidStack).consolePrice/d.consolePrice)-1);
    }
    else return 0;
}

float mean(tList list){//Devuelve la media del precio de pujas de la lista
    tPosL p=list;
    float sum=0;//suma total de las pujas
    float count=0;
    while (p!=NULL){
        sum+=p->data.bidCounter;
        count++;
        p=next(p,list);
    }
    return sum/count;
}

char *enumtochar(tConsoleBrand b) {//Convierte del tipo enum a cadena de caracteres
    if (b==nintendo) {
        return "nintendo";
    }
    else {return "sega";}
}

void New(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList* list){//Inserta una nueva consola en la lista si el id no existía ya
    tItemL item;//Item que luego inseramos
    printf("********************\n%s %c: console %s seller %s brand %s price %s\n", commandNumber, command, param1, param2, param3, param4);
    strcpy(item.consoleId, param1);
    strcpy(item.seller, param2);
    if (strcmp("nintendo", param3) == 0) {
        item.consoleBrand=nintendo;
    }
    else {
        item.consoleBrand=sega;
    }
    item.consolePrice=atof(param4);
    item.bidCounter=0;
    createEmptyStack(&item.bidStack);

    if (insertItem(item, list)==true) {  //Muestra la nueva consola en caso de ser posible.
        printf("* New: console %s seller %s brand %s price %s\n",param1, param2, param3, param4);
    }

    else {
        printf("+ Error: New not possible\n");
    }
}

void Delete(char *commandNumber, char command, char *param1, tList *list){
    //Elimina el item indicado con su stack de pujas
    printf("********************\n%s %c: console %s \n", commandNumber, command, param1);
    tPosL Q=findItem(param1,*list);//Variable que apunta al item o indica que no existe
    if (Q!=NULL){
        tItemL item1=getItem(Q,*list);
        while (isEmptyStack(item1.bidStack)!=true) {//Elimina el bid stack
            pop(&item1.bidStack);
        }
        printf("* Delete: console %s seller %s brand %s price %.2f bids %d\n",item1.consoleId,item1.seller,enumtochar(item1.consoleBrand), item1.consolePrice,item1.bidCounter);
        item1.bidCounter=0;
        updateItem(item1,Q,list);
        deleteAtPosition(Q,list);
    }
    else printf("+ Error: Delete not possible\n");
}


void Bid(char *commandNumber, char command, char *param1, char *param2, char *param3, tList *list) { //Puja por la siguiente consola.
    printf("********************\n%s %c: console %s bidder %s price %s\n", commandNumber, command, param1, param2, param3);

    tPosL Q=findItem(param1,*list);//Variable que apunta al item o indica que no existe

    if(Q!=LNULL){
        tItemL itemL=getItem(Q,*list);//"Extraemos" el item para actualizarlo
        tConsolePrice topbid=itemL.consolePrice;//Variable para almacenar la máxima puja
        if(isEmptyStack(itemL.bidStack)!=true){
            topbid=peek(itemL.bidStack).consolePrice;//Máxima puja si existe
            }
        tItemS itemS;//Tipo stack para actualizar el itemL
        itemS.consolePrice=atof(param3);
        strcpy(itemS.bidder,param2);
        if (itemL.seller!=param2) {
            if(itemS.consolePrice>topbid){
                topbid=itemS.consolePrice;
                if (push(itemS,&itemL.bidStack)==true){
                    itemL.bidCounter++;
                    updateItem(itemL,Q,list);
                    printf("* Bid: console %s bidder %s brand %s price %.2f bids %d\n", itemL.consoleId, itemL.bidStack.data->bidder, enumtochar(itemL.consoleBrand), itemL.bidStack.data->consolePrice, itemL.bidCounter);
                }
                else printf("+ Error: Bid not possible\n");
            }
            else printf("+ Error: Bid not possible\n");
        }
        else printf("+ Error: Bid not possible\n");
    }
    else printf("+ Error: Bid not possible\n");
}

void Award(char *commandNumber, char command, char *param1, tList* list)
{
    printf("********************\n%s %c: console %s\n", commandNumber, command, param1);
    tPosL Q=findItem(param1, *list);//Variable que apunta al item o indica que no existe
    if(Q!=LNULL){
        tItemL item=getItem(Q,*list);
        if (findItem(item.consoleId,*list)==LNULL||item.bidCounter==0) {
            printf("+ Error: Award not possible\n");
        }
        else {
            printf("* Award: console %s bidder %s brand %s price %.2f\n", item.consoleId, item.bidStack.data->bidder, enumtochar(item.consoleBrand), item.bidStack.data->consolePrice);
            while (isEmptyStack(item.bidStack)!=true) {//Elimina las pujas
                pop(&item.bidStack);
            }
            item.bidCounter=0;
            updateItem(item,Q,list);
            deleteAtPosition(Q,list);
        }
    }
    else printf("+ Error: Award not possible\n");
}

void InvalidateBids(char *commandNumber, char command, tList* list){//Elimina consolas con más del doble de la media de numero de pujas
    printf("********************\n%s %c\n", commandNumber, command);
    if(!isEmptyList(*list)){
        float mean2=mean(*list)*2;//Doble de la media de numero de pujas
        tPosL p=first(*list);//Apunta al primer elemento de la lista
        int count=0;//Contador
        while (p!=NULL){//Recorre la lista eliminando las consolas con demasiadas pujas
            if (p->data.bidCounter>mean2){
                printf("* InvalidateBids: console %s seller %s brand %s price %.2f bids %d average bids %.2f\n",p->data.consoleId, p->data.seller, enumtochar(p->data.consoleBrand), p->data.consolePrice, p->data.bidCounter, mean(*list));
                while (isEmptyStack(p->data.bidStack)!=true) {//Elimina las pujas
                    pop(&p->data.bidStack);
                }
                p->data.bidCounter=0;
                count++;
            }
            p=next(p,*list);
        }

        if (count==0||isEmptyList(*list)==true){//Si no elimina ninguna o la lisa está vacía da mensaje de error
            printf("+ Error: InvalidateBids not possible\n");
        }
    }
    else printf("+ Error: InvalidateBids not possible\n");

}

void Stats(char *commandNumber, char command, tList* list) {//Imprime un resumen de la lista
    printf("********************\n%s %c\n", commandNumber, command);
    int n=0,s=0;//Numero de consolas de cada marca
    float sumn=0,sums=0;//Suma de los precios de cada marca
    tPosL p=first(*list);//Preparo para recorrer la lista
    tItemL topincrease=getItem(first(*list),*list);//Variable que va a copiar la consola con un mayor incremento de precio porcentual

    if (isEmptyList(*list)==false)
    {
        //Condición para que stats imprima los datos
        for(p;p!=LNULL;p=next(p,*list)){//Recorro la lista
            tItemL item=getItem(p,*list);//Variable para usar en cada iteración del "for"
            if (isEmptyStack(item.bidStack)!=true){//Imprimo la lista con un mensaje diferente dependiendo de si tiene pujas
                printf("Console %s seller %s brand %s price %.2f bids %d top bidder %s\n",item.consoleId,item.seller,enumtochar(item.consoleBrand),item.consolePrice,item.bidCounter,item.bidStack.data->bidder);
            }
            else printf("Console %s seller %s brand %s price %.2f. No bids\n",item.consoleId,item.seller,enumtochar(item.consoleBrand),item.consolePrice);

            if(item.consoleBrand==nintendo) {//Almaceno los datos de las consolas
                n++;
                sumn+=item.consolePrice;
            }
            else {
                s++;
                sums+=item.consolePrice;
            }

            if (priceRatio(item)>priceRatio(topincrease)){//Se queda con la diferencia porcentual más alta
                topincrease=item;
            }
        }

        printf("Brand     Consoles    Price  Average\nNintendo  %8d %8.2f %8.2f\nSega      %8d %8.2f %8.2f\n", n, sumn, average(sumn, n), s, sums, average(sums, s));
        if (isEmptyStack(topincrease.bidStack)!=true){//En caso de que haya habido pujas
            printf("Top bid: console %s seller %s brand %s price %.2f bidder %s top price %.2f increase %.2f%%\n",topincrease.consoleId, topincrease.seller, enumtochar(topincrease.consoleBrand), topincrease.consolePrice, peek(topincrease.bidStack).bidder, peek(topincrease.bidStack).consolePrice, priceRatio(topincrease));
        }
        else printf("Top bid not possible\n");
    }
    else printf("+ Error: Stats not possible\n");
}

void Remove(char *commandNumber, char command, tList* list){
    printf("********************\n%s %c\n", commandNumber, command);
    tPosL p=first(*list);
    for (p;next(p,*list)!=LNULL;p=next(p,*list)){
        if (p->data.bidCounter==0) {
            printf("Removing console %s seller %s brand %s price %.2f bids %d\n",p->data.consoleId, p->data.seller, enumtochar(p->data.consoleBrand), p->data.consolePrice, p->data.bidCounter);
            deleteAtPosition(p,list);
        }
    }
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *list) {//Incluyo la lista a los argumentos

    switch (command) {
        case 'N':New(commandNumber, command, param1, param2, param3, param4, list);
            break;
        case 'D':Delete(commandNumber, command, param1, list);
            break;
        case 'B':Bid(commandNumber, command, param1, param2, param3, list);
            break;
        case 'A':Award(commandNumber,command,param1,list);
            break;
        case 'R':Remove(commandNumber,command,list);
            break;
        case 'S':Stats(commandNumber, command, list);
            break;
        case 'I':InvalidateBids(commandNumber, command, list);
            break;
        default:
            break;
    }
}


void readTasks(char *filename, tList *list) {//Incluyo la lista a los argumentos

    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, param4, list);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {
    tList list;//Creo la lista
    createEmptyList(&list);//Inicializo la lista


    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name, &list);

    return 0;
}