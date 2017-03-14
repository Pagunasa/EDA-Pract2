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

#define TRUE 0
#define FALSE 1
#define DEBUG TRUE
#define MAXLENGTH20 20
#define MAXLENGTH24 24
#define MAXLENGTH30 30
#define MAXLENGTH10 10
#define MAXLENGTH100 100
#define MAXLENGTH500 500
#define MAXLENGTH1500 1500
#define MAXOFDISK 3
#define MAXOFTOWERS 3
//#define MOVESMAX3 7 //esto desaparecerá
//#define MOVESMAX4 15 //esto desaparecerá
#define TOWERORIGIN 0
#define TOWERAUXILIAR 1
#define TOWERDESTINY 2
#define SEEMOVEMENT 'S'
#define NOTSEEMOVEMENT 'N'
#define LEFT "L"
#define RIGTH "R"
#define SHOWTHEYEAR 1900
#define NUMOFHEADSEP 30
#define FIRST 1
#define SECOND 2

//Strings
#define STRNULL "NULL"
#define STRERRORMEMORY "SYSTEM ERROR(Not enough memory)"
#define STRPASSCORRECT "\nMovimientos completados correctamente. \n\n"
#define STRDBG1 "Move disc %i from %d to %d\n"
#define STRSHWMVM "Move count %i, Rec Depth %i: it moves disc %i from T%i to T%i \n"
#define STRMENU1_1 "Desea visualizar un movimiento?\n"
#define STRMENU1_2 "S - Elija un movimiento\n"
#define STRMENU1_3 "N - Salir \n"
#define STRMENU2_1 "Total de movimentos (0 para salir): %i\n"
#define STRMENU2_2 "Introduce movimiento: "
#define STRERRORINPUT "Input error\n"
#define STRTHNKS "Gracias por usar el programa\n"
#define STRWHTSPACE ""
#define STRSPACE " "
#define STRJMP "\n\n"
#define STRJMPESP "\r\n"
#define STRJMPESPDOUBLE "\r\n\r\n"
//Show commands
#define STRSHOW1 "Los commandos para operar son: \n"
#define STRCMD1 "hanoiplus"
#define STRCMD2 " -d <numero de discos>"
#define STRCMD3 " -f <nombre del fichero>"
#define STRCMD4 " -o <codigo de operacion> \n\n"
#define STRSHOW2 "Los codigos de operacion son: \n"
#define STROPTION1 "ap -> Guardar la informacion en un fichero existente\n"
#define STROPTION2 "w -> Crear un nuevo fichero o aplastar uno existente\n\n"
//inputComands
#define STRINPUTCMD "Introduce el comando: \n"
#define STRERRORCMDDSK "Comando no valido, el numero de discos no se puede ser -d %s \n"
#define STRERRORCMDFL "Comando no valido, no se puede llamar al fichero %s \n"
#define STRERRORCMDOPT "Comando no valido, no se puede introducir -o %s \n"
#define STRERRORCMD "Comando no valido, no se puede introducir %s \n"
#define STRPASSCMD "Comando valido, introducion correcta! \n"
#define STRAP "ap"
#define STRW "w"
#define STRBASE "hanoiplus"
#define STRMINUSD "-d"
#define STRMINUSF "-f"
#define STRMINUSO "-o"
//showMtr
#define STRPROF "H %i\t %s %s %s"
#define STREMPTY "."
#define STRSEPA "|"
#define STRDSK "-"
#define ENDLINE "/"
#define TAB "\t"
//writeInFile
#define STRSTDOUT "Fichero no introducido, pasando a fase interactiva\n"
#define STRERRORFILE "Error abriendo el fichero pasando a fase interactiva\n"
#define STRTYPEFILE ".txt"
//writeInFileHeader
#define STRCMDLN "Command Line Entered: %s/%s\r\n"
#define STRTWRNUM "Number of Towers: %i\r\n"
#define STRDSKNUM "Number of disk: %i\r\n"
#define STROUTPUTFN "Ouput Filename: %s\r\n"
#define STRFILEOP "File Operation: %s\r\n"
#define STRFILEOP "File Operation: %s\r\n"
#define STRTOTALNUM "Total Number Moves: %i\r\n"
#define STRENDTIME "END Time: %s\r\n"
#define STRINITTIME "INIT Time: %s\r\n"
#define STRSEPHEADER "="
//End of Strings

//Ints For ENDLINE
#define ONE 1
#define TWOO 2
#define FOUR 4
//End of Ints For ENDLINE

//Colors--
#define COLOR_RED   "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
//End of Colors

//typedef struct{
//    int day;
//    char month[MAXLENGTH20];
//    int year;
//    char nDay[MAXLENGTH20];
//    int hour;
//    int min;
//    int seg;
//}sDateTime;


typedef struct movement{
    int mvmNumb;
    int depth;
    int towerOrg;
    int towerDest;
    int diskMoved;
    int **towerStatus;
    struct movement *prev;
    struct movement *next;
}sMovesState;

typedef struct{
    char cmdLine[MAXLENGTH500];
    int towerNum;
    int diskNum;
    char ouputFilename[MAXLENGTH100]; //nombre fichero
    char fileOperations[MAXLENGTH20]; //ap o wp
    char initDate[MAXLENGTH30];
    char endDate[MAXLENGTH30];
   // sDateTime date; 
    //sMovesState moveState[MOVESMAX3]; //esto desaparecerá
}sHeader;

typedef struct{
   // sMovesState *moveState;
    sMovesState *firstElement;
    int size;
}sNode;

//typedef struct{
//    int moves;
//    int TowerInfo[MAXOFTOWERS][MAXOFDISK];//esto desaparecera
//}sTowersState; //seguramente desaparecera



#endif	/* STRUCTS_H */

