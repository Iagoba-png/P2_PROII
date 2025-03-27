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


typedef struct tStack* tPosS;
typedef struct tStack {
 tItemS data;
 tPosS top;
} tStack;

typedef tPosS tList;

void createEmptyList (tList* L);
bool isEmptyList (tList L);
tPosS first (tList L);
tPosS last (tList L);
tPosS next (tPosS p, tList L);
tPosS previous (tPosS p, tList L);
bool checkPointer(tPosS p, tList L);
bool insertItem (tItemS d, tPosS p, tList* L);
tItemS getItem (tPosS p, tList L);
void updateItem (tItemS d, tPosS p, tList* L);
tPosS findItem (tConsoleId, tList L);
void deleteAtPosition(tPosS p, tList* L);
#endif
