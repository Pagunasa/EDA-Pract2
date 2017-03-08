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

#define ERRORMEMORY(condition, msg) if condition {printf msg; exit(0);}

int hanoi(int nd, int org, int dest, int aux, int *movemt, int depth, sHeader *stateList, sNode *node, int ***TowerInfo);
int move(int org, int dest, int *movemt, int depth, sHeader *stateList, sNode *node, int ***TowerInfo);
void initMatrix(int ***TowerInfo, int columnas, int filas);
void initHeaderInfo(sHeader *stateList, int nd, int nt);
void showMovement(sNode node, sHeader stateList,int mvmNumber);
void initList(sNode *node);
void pushList(sNode *node, int depth, int towerOrg, int towerDest, int diskMoved, int mvmNumb, int **towerStatus, sHeader *stateList);
void showList(sNode *node);
void freeTheMemoryMatrix(int ***TowerInfo, int filas);
void cpyMtr(int ***TowerInfo, int **TowerTCpy, int filas, int columnas);
void showMtr(int **MvmState, sHeader stateList);

#endif	/* LISTOPERATIONS_H */

