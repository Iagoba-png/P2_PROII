/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Iago Bescansa Alcoba LOGIN 1: iago.alcoba
 * AUTHOR 2: Daniel Marrero Sánchez LOGIN 2: daniel.marrero.sanchez
 * GROUP: 1.2
 * DATE: ** / ** / **
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "console_list.h"

#define MAX_BUFFER 255

float mean(tList list){
    tPosL p=list;
    float sum=0;
    float count=0;
    for (p;p->next!=NULL;p=p->next){
        sum+=p->data.bidCounter;
        count++;
    }
    return sum/count;
}

char *enumtochar(tConsoleBrand b) {//Convierte del tipo enum a cadena de caracteres
    if (b==nintendo) {
        return "nintendo";
    }
    else {return "sega";}
}

void New(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList list){//Inserta una nueva consola en la lista si el id no existía ya
    tItemL item;
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

    if (insertItem(item, nextOrderId(item.consoleId,list), &list)==true) {
        printf("New: console %s seller %s brand %s price %s\n",param1, param2, param3, param4);
    }

    else {
        printf("+ Error: New not possible\n");
    }
}

void Delete(char *commandNumber, char command, char *param1, tList list){//Elimina el item indicado con su stack de pujas
    printf("********************\n%s %c: console %s \n", commandNumber, command, param1);
    tItemL item1=getItem(findItem(param1,list),list);
    while (isEmptyStack(item1.bidStack)!=true) {//Elimina el bid stack
        pop(&item1.bidStack);
    }
    item1.bidCounter=0;
    deleteAtPosition(findItem(param1,list),&list);
    if (findItem(param1,list)==LNULL) {
        printf("Delete: console %s seller %s brand %s price %.2f bids %d\n",item1.consoleId,item1.seller,enumtochar(item1.consoleBrand), item1.consolePrice,item1.bidCounter);
    }
    else {
        printf("+ Error: Delete not possible\n");
    }
}

void Bid(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList list) {
    printf("********************\n%s %c: console %s bidder %s brand %s bid %s\n", commandNumber, command, param1, param2, param3, param4);

    tItemL itemL=getItem(findItem(param1,list),list);
    tItemS itemS;
    itemS.consolePrice=atof(param4);
    strcpy(itemS.bidder,param2);
    if (itemL.seller!=param2 && atof(param4)>peek(itemL.bidStack).consolePrice && findItem(param1,list)!=LNULL) {
        if (push(itemS,&itemL.bidStack)==true){
            itemL.bidCounter++;
            printf("* Bid: console %s seller %s brand %s price %.2f bids %d\n", itemL.consoleId, itemL.seller, enumtochar(itemL.consoleBrand), itemL.consolePrice, itemL.bidCounter);
        }
    }
    else printf("+ Error: Bid not possible\n");
}

void Award(char *commandNumber, char command, char *param1, tList list) {
    printf("********************\n%s %c: console %s\n", commandNumber, command, param1);
    tItemL item=getItem(findItem(param1, list),list);
    if (findItem(item.consoleId,list)==LNULL||item.bidCounter==0) {
        printf("+ Error: Award not possible\n");
    }
    else {
        printf("********************\nAward: console %s bidder %s brand %s price %.2f\n", item.consoleId, item.bidStack.data->bidder, enumtochar(item.consoleBrand), item.bidStack.data->consolePrice);
        while (isEmptyStack(item.bidStack)!=true) {//Elimina las pujas
            pop(&item.bidStack);
        }
        item.bidCounter=0;
        deleteAtPosition(findItem(param1,list),&list);
    }

}

void InvalidateBids(char *commandNumber, char command, tList list){
    printf("********************\n%s %c\n", commandNumber, command);
    float mean2=mean(list)*2;
    tPosL p=list;
    int count=0;
    for (p;next(p,list)!=NULL;p=next(p,list)){
        if (p->data.bidCounter>mean2){
            printf("* InvalidateBids: console %s seller %s brand %s price %f bids %d average bids %.2f\n",p->data.consoleId, p->data.seller, enumtochar(p->data.consoleBrand), p->data.consolePrice, p->data.bidCounter, mean(list));
            while (isEmptyStack(p->data.bidStack)!=true) {//Elimina las pujas
                pop(&p->data.bidStack);
            }
            p->data.bidCounter=0;
            count++;
        }
    }
    if (count==0||isEmptyList(list)==true){
        printf("+ Error: InvalidateBids not possible\n");
    }

}

void Stats(char *commandNumber, char command, tList list) {
    printf("********************\n%s %c\n", commandNumber, command);
    int n=0,s=0;
    float sumn=0,sums=0;
    tPosL p=first(list);
    if (isEmptyList(list)==false) {
        for(p;p!=LNULL;p=next(p,list)) {
            printf("Console %s seller %s brand %s price %.2f bids %d top bidder %.2f\n",getItem(p,list).consoleId,getItem(p,list).seller,enumtochar(getItem(p,list).consoleBrand),getItem(p,list).consolePrice,getItem(p,list).bidCounter, getItem(p,list).bidStack.data->consolePrice);
        }
        p=first(list);
        while (p!=LNULL) {
            if(getItem(p,list).consoleBrand==nintendo) {
                n++;
                sumn+=getItem(p,list).consolePrice;
            }
            else {
                s++;
                sums+=getItem(p,list).consolePrice;
            }
            p=next(p,list);
        }
        printf("Brand     Consoles    Price  Average\nNintendo  %8d %8.2f %8.2f\nSega      %8d %8.2f %8.2f\n", n, sumn, sumn/n, s, sums, sums/s);
    }
    else printf("+ Error: Stats not possible\n");
}

void Remove(char *commandNumber, char command, tList list){
    printf("********************\n%s %c\n", commandNumber, command);
    tPosL p=list;
    for (p;next(p,list)!=LNULL;p=next(p,list)){
        if (p->data.bidCounter==0) {
            printf("Removing console %s seller %s brand %s price %f bids %d",p->data.consoleId, p->data.seller, enumtochar(p->data.consoleBrand), p->data.consolePrice, p->data.bidCounter);
        }
    }
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList list) {

    switch (command) {
        case 'N':New(commandNumber, command, param1, param2, param3, param4, list);
            break;
        case 'D':Delete(commandNumber, command, param1, list);
            break;
        case 'B':Bid(commandNumber, command, param1, param2, param3, param4, list);
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


void readTasks(char *filename, tList list) {

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
    tList list;
    createEmptyList(&list);


    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name, list);

    return 0;
}