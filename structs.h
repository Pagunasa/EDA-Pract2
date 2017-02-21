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
#define MOVESMAX3 7
#define MOVESMAX4 15

//Colors
#define COLOR_RED   "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"
//End of Colors

typedef struct{
    char day[MAXLENGTH20];
    char month[MAXLENGTH20];
    char nDay[MAXLENGTH20];
    char hour[MAXLENGTH20];
    char year[MAXLENGTH20];
}sDateTime;

typedef struct{
    char cmdLine[MAXLENGTH500];
    char towerNum[MAXLENGTH10];
    char diskNum[MAXLENGTH10];
    char ouputFilename[MAXLENGTH100];
    char fileOperations[MAXLENGTH20];
    sDateTime date; 
}sHeader;

typedef struct{
    int moves;
    int TowerInfo[2][MAXOFDISK];
}sTowersState;

typedef struct{
    int depth;
    int towerOrg;
    int towerDest;
    int diskMoved;
}sMovesState;


#endif	/* STRUCTS_H */

