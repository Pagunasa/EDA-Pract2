/* 2016-17 Estructures de Dades i Algorismes I
 * 
 * Practice assignment 2: Hanoi Towers Game 
 * File: listOperations.c
 * 
 * This file contains the operations who is refereds whit the work with the 
 * files, inputs, ouputs and the function who cleans the stdin. 
 * It only have five functions for showing who you have tho write the command , 
 * the inputComands who is needed for segure that the input was correct, the 
 * dump_line function who we use for cleaning the stdin and twoo more for print
 * the information in the file who the user put in the command, one of them only
 * print the headers (writeInFileHeader) and the other all the body of the 
 * file (writeInFile). 
 * 
 * Prepared by:
 * Modified: February 2017
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "filesOperations.h"
#include "listOperations.h"

/*This function haven't any parameter and only show all the information of the
 * commands and who it is structure
 */
void showCommands() {
    printf(STRSHOW1);
    printf(COLOR_MAGENTA STRCMD1 COLOR_RESET);
    printf(COLOR_CYAN STRCMD2 COLOR_RESET);
    printf(COLOR_YELLOW STRCMD3 COLOR_RESET);
    printf(COLOR_GREEN STRCMD4 COLOR_RESET);

    printf(STRSHOW2);
    printf(COLOR_GREEN STROPTION1);
    printf(STROPTION2 COLOR_RESET);
}

/*This function have the satetList for save the command and the command who 
 * the user input, the fucntion returns 0 if the command is correct and 1
 * if the user input a error in the command.
 */
int inputComands(sHeader *stateList, char cmd[MAXLENGTH500]) {
//    char cmd[MAXLENGTH100];
    char cmdAux[MAXLENGTH100];
//
//    printf(STRINPUTCMD);
//    scanf("%[^\n]", cmd);   //This is used in a old version for input in this point the command
//    dump_line(stdin);

    int i = 0, j = 0, e = 0, a = 0, intAux, fail = 0;
    int moreCmds = 0;

    while (i < strlen(cmd)) {
        if (cmd[i] != ' ' && cmd[i] != '\0') {
            cmdAux[i] = cmd[i];
        } else {
            cmdAux[i] = '\0';
            moreCmds = 1;
            if (strcmp(cmdAux, STRBASE) == 0) {
                i++;
                j = 0;
                memset(cmdAux, '\0', strlen(cmdAux));

                while (i < strlen(cmd)) {
                    if (cmd[i] != ' ') {
                        cmdAux[j] = cmd[i];
                    } else {
                        i++;
                        a = i;
                        e = 0;
                        if (strcmp(cmdAux, STRMINUSD) == 0) {
                            memset(cmdAux, '\0', strlen(cmdAux));
                            while (e < strlen(cmd)) {
                                if (cmd[a] != '\0' && cmd[a] != ' ') {
                                    cmdAux[e] = cmd[a];
                                    e++;
                                } else {
                                    e = strlen(cmd);
                                }
                                a++;
                            }
                            intAux = atoi(cmdAux);

                            if (intAux > 0) {
                                stateList->diskNum = intAux;
                            } else {
                                printf(COLOR_RED STRERRORCMDDSK COLOR_RESET, cmdAux);
                                fail = 1;
                            }
                            i = a - 1;
                            memset(cmdAux, '\0', strlen(cmdAux));
                            j = -1;
                        } else if (strcmp(cmdAux, STRMINUSF) == 0) {
                            memset(cmdAux, '\0', strlen(cmdAux));
                            while (e < strlen(cmd)) {
                                if (cmd[a] != '\0' && cmd[a] != ' ') {
                                    cmdAux[e] = cmd[a];
                                    e++;
                                } else {
                                    e = strlen(cmd);
                                }
                                a++;
                            }

                            if (strcmp(cmdAux, STRMINUSD) == 0 || strcmp(cmdAux, STRMINUSO) == 0 || strcmp(cmdAux, STRMINUSF) == 0) {
                                printf(COLOR_RED STRERRORCMDFL COLOR_RESET, cmdAux);
                                fail = 1;
                            } else {
                                strcpy(stateList->ouputFilename, cmdAux);
                            }
                            i = a - 1;
                            memset(cmdAux, '\0', strlen(cmdAux));
                            j = -1;
                        } else if (strcmp(cmdAux, STRMINUSO) == 0) {
                            memset(cmdAux, '\0', strlen(cmdAux));
                            while (e < strlen(cmd)) {
                                if (cmd[a] != '\0' && cmd[a] != ' ') {
                                    cmdAux[e] = cmd[a];
                                    e++;
                                } else {
                                    e = strlen(cmd);
                                }
                                a++;
                            }

                            intAux = 0;
                            if (strcmp(cmdAux, STRAP) != 0) {
                                intAux++;
                            }
                            if (strcmp(cmdAux, STRW) != 0) {
                                intAux++;
                            }
                            if (intAux == 2) {
                                printf(COLOR_RED STRERRORCMDOPT COLOR_RESET, cmdAux);
                                fail = 1;
                            } else {
                                strcpy(stateList->fileOperations, cmdAux);
                            }

                            i = a - 1;
                            memset(cmdAux, '\0', strlen(cmdAux));
                            j = -1;
                        } else {
                            printf(COLOR_RED STRERRORCMD COLOR_RESET, cmdAux);
                            fail = 1;
                            i = strlen(cmd);
                        }
                    }
                    i++;
                    j++;
                }

            } else {
                printf(COLOR_RED STRERRORCMD COLOR_RESET, cmdAux);
                fail = 1;
                i = strlen(cmd);
            }

        }
        i++;
    }

    if (moreCmds == 0) {
        if (strcmp(cmd, STRBASE) == 0) {
            printf(COLOR_GREEN STRPASSCMD COLOR_RESET);
        } else {
            printf(COLOR_RED STRERRORCMD COLOR_RESET, cmd);
            fail = 1;
        }
    }

    if (fail == 0) {
        strcpy(stateList->cmdLine, cmd);
    }

    return fail;
}

/*This function have 5 parameters the stateList who have saved the most of the
 * information who is showed in the header, the fp who is the file, the 
 * movements, a integer who is used for comprove if the header is the first of
 * the second and the path of the execution. This function print in the file the
 * headers of the file.
 */
void writeInFileHeader(sHeader stateList, FILE * fp, int FirstOSec, int moves, char path[MAXLENGTH1500]) {
    int loop = 0;

    do {
        fprintf(fp, STRSEPHEADER);
        loop++;
    } while (loop < NUMOFHEADSEP);
    loop = 0;

    if (FirstOSec == FIRST) {
        fprintf(fp, STRJMPESP);
        fprintf(fp, STRCMDLN, path, stateList.cmdLine);
        fprintf(fp, STRTWRNUM, stateList.towerNum);
        fprintf(fp, STRDSKNUM, stateList.diskNum);
        fprintf(fp, STROUTPUTFN, stateList.ouputFilename);
        fprintf(fp, STRFILEOP, stateList.fileOperations);
        fprintf(fp, STRJMPESP);
        fprintf(fp, STRINITTIME, stateList.initDate);
    } else {
        fprintf(fp, STRJMPESP);
        fprintf(fp, STRTWRNUM, stateList.towerNum);
        fprintf(fp, STRDSKNUM, stateList.diskNum);
        fprintf(fp, STROUTPUTFN, stateList.ouputFilename);
        fprintf(fp, STRFILEOP, stateList.fileOperations);
        fprintf(fp, STRJMPESP);
        fprintf(fp, STRTOTALNUM, moves);
        fprintf(fp, STRENDTIME, stateList.endDate);
    }

    do {
        fprintf(fp, STRSEPHEADER);
        loop++;
    } while (loop < NUMOFHEADSEP);
}

/*This function have three parameters, the stateList who have the most of the
 * information who is showed in the header, the node who have the refenrece of
 * the first movement and is used for print all the movements. This function 
 * print the body of the text and call the writeInFileHeader when is his turn
 * for print in the file.
 */
void writeInFile(sHeader stateList, sNode node, char path[MAXLENGTH1500]) {
    if (strcmp(stateList.ouputFilename, STRNULL)) {
        char fileNameTxt[MAXLENGTH24];
        int timeToWrite;
        FILE * fp;
        strlcpy(fileNameTxt, stateList.ouputFilename, sizeof (fileNameTxt));
        strlcat(fileNameTxt, STRTYPEFILE, sizeof (fileNameTxt));
        if (strcmp(stateList.fileOperations, STRAP) == 0) {
            fp = fopen(fileNameTxt, "a");
        } else {
            fp = fopen(fileNameTxt, "w");
        }
        writeInFileHeader(stateList, fp, FIRST, node.size, path);
        if (fp == NULL) {
            printf(COLOR_RED STRERRORFILE COLOR_RESET);
        } else {
            timeToWrite = 0;
            do {
                showMovement(node, stateList, timeToWrite, fp);
                fprintf(fp, STRJMPESP);
                fprintf(fp, STRJMPESP);
                timeToWrite++;
            } while (timeToWrite <= node.size);
        }
        writeInFileHeader(stateList, fp, SECOND, node.size, path);
        fclose(fp);
    } else {
        printf(COLOR_GREEN STRSTDOUT COLOR_RESET);
    }
}

/*This function have one parameter who is a file and his functionality is
 * for cleaning stdin, and to prevent a infinity loop.
 */
void dump_line(FILE * fp) {
    int ch;

    while ((ch = fgetc(fp)) != EOF && ch != '\n')
        /* null body */;
}
