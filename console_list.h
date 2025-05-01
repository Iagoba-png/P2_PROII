/*
* TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Iago Bescansa Alcoba LOGIN 1: iago.alcoba
 * AUTHOR 2: Daniel Marrero Sánchez LOGIN 2: daniel.marrero.sanchez
 * GROUP: 1.2
 * DATE: 30 / 04 / 2025
 */

#ifndef CONSOLE_LIST_H
#define CONSOLE_LIST_H

#include "types.h"
#include "bid_stack.h"

/* Write your code here... */
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#define LNULL NULL

typedef struct tItemL {
 tUserId seller;
 tConsoleId consoleId;
 tConsoleBrand consoleBrand;
 tConsolePrice consolePrice;
 tBidCounter bidCounter;
 tStack bidStack;
} tItemL;

typedef struct tNode* tPosL;
typedef struct tNode {
 tItemL data;
 tPosL next;
} tNode;

typedef tPosL tList;

void createEmptyList (tList* L);
bool isEmptyList (tList L);
tPosL first (tList L);
tPosL last (tList L);
tPosL next (tPosL p, tList L);
tPosL previous (tPosL p, tList L);
bool insertItem (tItemL d, tList* L);
tItemL getItem (tPosL p, tList L);
void updateItem (tItemL d, tPosL p, tList* L);
tPosL findItem (tConsoleId, tList L);
void deleteAtPosition(tPosL p, tList* L);
tPosL nextOrderId(tConsoleId d, tList L);
#endif
