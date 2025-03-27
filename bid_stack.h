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
#define SNULL -1
#define SMAX 25
/* Write your code here... */
typedef int tPosS;

typedef struct tItemS {
    tUserId bidder;
    tConsolePrice price;
}tItemS;

typedef struct tStack {
    tItemS data[SMAX];
    tPosS top;
} tStack;

void createEmptyStack(tStack* S);
bool push(tItemS d, tStack* S);
void pop(tStack* S);
tItemS peek(tStack S);
bool isEmptyStack(tStack S);
#endif
