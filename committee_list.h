/*
* TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "types.h"
#include "project_list.h"

#define NULLC -1
#define MAX 1000

typedef int tPosC;

typedef struct {

 tCommitteeName committeeName;
 tNumVotes totalEvaluators;
 tNumVotes validVotes;
 tNumVotes nullVotes;
 tListP projectList;

} tItemC;

typedef struct {

 tItemC data[MAX];
 tPosC lastPos;

} tListC;

bool isEmptyListC(tListC L);

bool insertItemC(tItemC d, tListC *L);

void updateItemC(tItemC d, tPosC p, tListC *L);

void deleteAtPositionC(tPosC p, tListC *L);

void createEmptyListC(tListC *L);

tPosC firstC(tListC L);

tPosC lastC(tListC L);

tPosC nextC(tPosC p, tListC L);

tPosC previousC(tPosC p, tListC L);

tPosC findItemC(tProjectName name, tListC L);

tItemC getItemC(tPosC p, tListC L);
