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

#ifndef LISTOPERATIONS_H
#define	LISTOPERATIONS_H

int hanoi(int nd, int org, int dest, int aux, int *movemt, int depth, sHeader *stateList, sTowersState *towers, sNode *node);
int move(int org, int dest, int *movemt, int depth, sHeader *stateList, sTowersState *towers, sNode *node);
void initTowers(sTowersState *towers, sHeader *stateList);
void initHeaderInfo(sHeader *stateList, int nd, int nt);
void showMovement(sHeader stateList,int mvmNumber);
void initList(sNode *node);
void pushList(sNode *node, int depth, int towerOrg, int towerDest, int diskMoved, int mvmNumb);
void showList(sNode *node);

#endif	/* LISTOPERATIONS_H */

