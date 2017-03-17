/* 2016-17 Estructures de Dades i Algorismes I
 * 
 * Practice assignment 2: Hanoi Towers Game 
 * File: fileOperations.h
 * 
 * This file contains the prototipe of all functions who pertains to
 * the file named fileOperations.c
 * 
 * Prepared by: 193610 Guillem Martinez, 192860 Sandra Rodriguez, 193518 Oriol Bernier 
 * Modified: February 2017
 */

#include "structs.h"
#include <stdio.h>

#ifndef FILESOPERATIONS_H
#define	FILESOPERATIONS_H

void showCommands();
int inputComands(sHeader *stateList, char cmd[MAXLENGTH500]);
void dump_line( FILE * fp );
void writeInFile(sHeader stateList, sNode node, char path[MAXLENGTH1500]);
void writeInFileHeader(sHeader stateList, FILE * fp, int FirstOSec, int moves, char path[MAXLENGTH1500]);

#endif	/* FILESOPERATIONS_H */

