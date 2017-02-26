/* 2016-17 Estructures de Dades i Algorismes I
 * 
 * Practice assignment 2: Hanoi Towers Game 
 * File: structs.h
 * 
 * This file contains the definitions of all constants and the typedef of 
 * all the structs who is needed for working the program.
 * 
 * Prepared by: 
 * Modified: February 2017
 */


#ifndef STRUCTS_H
#define	STRUCTS_H

#define MAXLENGTH20 20
#define MAXLENGTH10 10
#define MAXLENGTH100 100
#define MAXLENGTH500 500
#define MAXOFDISK 3
#define MAXOFTOWERS 3
#define MOVESMAX3 7
#define MOVESMAX4 15
#define TOWERORIGIN 0
#define TOWERAUXILIAR 1
#define TOWERDESTINY 2


//Colors
#define COLOR_RED   "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
//End of Colors

typedef struct{
    char day[MAXLENGTH20];
    char month[MAXLENGTH20];
    char nDay[MAXLENGTH20];
    char hour[MAXLENGTH20];
    char year[MAXLENGTH20];
}sDateTime;


typedef struct{
    int depth;
    int towerOrg;
    int towerDest;
    int diskMoved;
}sMovesState;

typedef struct{
    char cmdLine[MAXLENGTH500];
    int towerNum;
    int diskNum;
    char ouputFilename[MAXLENGTH100]; //nombre fichero
    char fileOperations[MAXLENGTH20];
    sDateTime date; 
    sMovesState moveState[MOVESMAX3];
}sHeader;

typedef struct{
    int moves;
    int TowerInfo[MAXOFTOWERS][MAXOFDISK];
}sTowersState;



#endif	/* STRUCTS_H */

