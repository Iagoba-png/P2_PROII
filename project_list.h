/*
* TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "types.h"
#include <stdlib.h>

#define NULLP NULL

typedef struct tNode *tPosP;
typedef tPosP tListP;

typedef struct {

 tProjectName projectName;
 tNumVotes numVotes;
 tProjectEco projectEco;

} tItemP;

struct tNode {

 tItemP data;
 tPosP next;

};

bool isEmptyListP(tListP L);

tPosP findPosition(tItemP d, tListP L);

bool insertItemP(tItemP d, tListP *L);

void updateItemP(tItemP d, tPosP p, tListP *L);

void deleteAtPositionP(tPosP p, tListP *L);

void createEmptyListP(tListP *L);

tPosP firstP(tListP L);

tPosP lastP(tListP L);

tPosP nextP(tPosP p, tListP L);

tPosP previousP(tPosP p, tListP L);

tPosP findItemP(tProjectName name, tListP L);

tItemP getItemP(tPosP p, tListP L);