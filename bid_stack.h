/*
* TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Iago Bescansa Alcoba LOGIN 1: iago.alcoba
 * AUTHOR 2: Daniel Marrero Sánchez LOGIN 2: daniel.marrero.sanchez
 * GROUP: 1.2
 * DATE: 25 / 04 / 2025
 */

#ifndef BID_STACK_H
#define BID_STACK_H

#include "types.h"
#include <stdbool.h>

#define SNULL -1
#define SMAX 25
/* Write your code here... */
typedef int tPosS;

typedef struct tItemS {
    tUserId bidder;
    tConsolePrice consolePrice;
}tItemS;

typedef struct{
    tItemS data[SMAX];
    tPosS top;
} tStack;

void createEmptyStack(tStack* S);
bool push(tItemS d, tStack* S);
void pop(tStack* S);
tItemS peek(tStack S);
bool isEmptyStack(tStack S);
#endif
