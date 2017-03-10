/* 2016-17 Estructures de Dades i Algorismes I
 * 
 * Practice assignment 2: Hanoi Towers Game 
 * File: fileOperations.h
 * 
 * This file contains the prototipe of all functions who pertains to
 * the file named fileOperations.c
 * 
 * Prepared by: 
 * Modified: February 2017
 */


#ifndef FILESOPERATIONS_H
#define	FILESOPERATIONS_H

void paintMoves(sMovesState stateList, int move);
void showCommands();
int inputComands(sHeader *stateList);
void makeTxt(sMovesState stateList, sTowersState towers, sHeader header, char fileName);
void dump_line( FILE * fp );
void writeInFile(sHeader stateList, sNode node);

#endif	/* FILESOPERATIONS_H */

