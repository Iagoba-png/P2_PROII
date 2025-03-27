/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#ifndef BID_STACK_H
#define BID_STACK_H

#include "types.h"
#include "console_list.h"
/* Write your code here... */

typedef struct tItemS {
    tUserId bidder;
    tConsolePrice price;
}tItemS;

void createEmptyStack(tStack* stack);
bool push(tItemS* d, tStack* stack);
void pop(tStack* stack);
tItemS* peek(tStack* stack);
bool isEmptyStack(tStack* stack);
#endif
