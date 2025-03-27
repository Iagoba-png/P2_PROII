/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
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
bool checkPointer(tPosL p, tList L);
bool insertItem (tItemS d, tPosL p, tList* L);
tItemS getItem (tPosL p, tList L);
void updateItem (tItemS d, tPosL p, tList* L);
tPosL findItem (tConsoleId, tList L);
void deleteAtPosition(tPosL p, tList* L);
#endif
