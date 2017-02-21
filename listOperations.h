/* 
 * File:   listOperations.h
 * Author: u140172
 *
 * Created on February 21, 2017, 12:29 PM
 */

#ifndef LISTOPERATIONS_H
#define	LISTOPERATIONS_H

int hanoi(int nd, int org, int dest, int aux, int move, int depth, sMovesState *stateList, sTowersState *towers);
int move(int org, int dest, int move, int depth, sMovesState *stateList, sTowersState *towers);
int initTowers(sTowersState *towers);

#endif	/* LISTOPERATIONS_H */

