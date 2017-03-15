/* 2016-17 Estructures de Dades i Algorismes I
 * 
 * Practice assignment 2: Hanoi Towers Game 
 * File: listOperations.h
 * 
 * This file contains the prototipe of all functions who pertains to
 * the file named listOperations.c
 * 
 * Prepared by: 
 * Modified: February 2017
 */

#include "structs.h"
#include <stdio.h>

#ifndef LISTOPERATIONS_H
#define LISTOPERATIONS_H

/*This Macro is used for check if the program have more 
 * memory and if it was not true this will show that was a error
 * and then finish the execution.
 */
#define ERRORMEMORY(condition, msg) if condition {printf msg; exit(0);}

/*The macros of PRINTSTRTOSTR and LOOPPRINT is used for print the
 * picture of the state of the hanoi movement in the file o in the
 * console
 */
#define LOOPPRINT(string, stringTPrint, size, LoR, e, disk, aux, aux2) \
aux = size;\
do{\
if (LoR == LEFT){\
aux2 = disk - aux;\
while(e < aux2){\
strlcat(string, STREMPTY, sizeof (string)); \
e++;\
}\
while(aux != 0){\
strlcat(string, stringTPrint, sizeof (string)); \
aux--; \
e++;\
}\
} else {\
if(aux == 0){\
strlcat(string, STREMPTY, sizeof (string)); \
e++; \
}\
while(aux != 0){\
strlcat(string, stringTPrint, sizeof (string)); \
aux--; \
e++;\
}}}while(e < disk);\
aux = 0; aux2 = 0; \

#define PRINTSTRTOSTR(condition, string, size, stringTPrint, e, nDisk, aux, aux2) \
    if condition { \
    LOOPPRINT(string, STREMPTY, size, LEFT, e, nDisk, aux, aux2);\
    e = 0; \
    strlcat(string, STRSEPA, sizeof (string)); \
    LOOPPRINT(string, STREMPTY, size, RIGTH, e, nDisk, aux, aux2);\
    e = 0; \
    }else{ \
    LOOPPRINT(string, STRDSK, size, LEFT, e, nDisk, aux, aux2); \
    e = 0; \
    strlcat(string, STRSEPA, sizeof (string));\
    LOOPPRINT(string, STRDSK, size, RIGTH, e, nDisk, aux, aux2); \
    e = 0; }\

int hanoi(int nd, int org, int dest, int aux, int *movemt, int depth, sHeader *stateList, sNode *node, int ***TowerInfo);
int move(int org, int dest, int *movemt, int depth, sHeader *stateList, sNode *node, int ***TowerInfo);
void initMatrix(int ***TowerInfo, int columnas, int filas);
void initHeaderInfo(sHeader *stateList, int nd, int nt);
void showMovement(sNode node, sHeader stateList, int mvmNumber, FILE *fp);
void initList(sNode *node);
void pushList(sNode *node, int depth, int towerOrg, int towerDest, int diskMoved, int mvmNumb, int **towerStatus, sHeader *stateList);
void showList(sNode *node);
void freeTheMemoryMatrix(int ***TowerInfo, int filas);
void freeTheListMemory(sNode *node);
void cpyMtr(int ***TowerInfo, int **TowerTCpy, int filas, int columnas);
void showMtr(int **MvmState, sHeader stateList, FILE * fp);
void updateDate(sHeader *stateList, int FirstOSec);

#endif /* LISTOPERATIONS_H */

