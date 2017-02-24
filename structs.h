/* 
 * File:   structs.h
 * Author: u140172
 *
 * Created on February 21, 2017, 12:28 PM
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
    char ouputFilename[MAXLENGTH100];
    char fileOperations[MAXLENGTH20];
    sDateTime date; 
    sMovesState moveState[MOVESMAX3];
}sHeader;

typedef struct{
    int moves;
    int TowerInfo[MAXOFTOWERS][MAXOFDISK];
}sTowersState;



#endif	/* STRUCTS_H */

