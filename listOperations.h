/* 
 * File:   listOperations.h
 * Author: u140172
 *
 * Created on February 21, 2017, 12:29 PM
 */

#ifndef LISTOPERATIONS_H
#define	LISTOPERATIONS_H

int hanoi(int nd, int org, int dest, int aux, int *movemt, int depth, sHeader *stateList, sTowersState *towers);
int move(int org, int dest, int *movemt, int depth, sHeader *stateList, sTowersState *towers);
void initTowers(sTowersState *towers, sHeader *stateList);
void initHeaderInfo(sHeader *stateList, int nd, int nt);

#endif	/* LISTOPERATIONS_H */

