/* 2016-17 Estructures de Dades i Algorismes I
 * 
 * Practice assignment 2: Hanoi Towers Game 
 * File: listOperations.c
 * 
 * This file contains the operations who is refereds whit the work with the 
 * files, inputs, ouputs and the function who cleans the stdin. 
 * It only have three functions for showing who you have tho write the command , 
 * the inputComands who is needed for segure that the input was correct and the 
 * dump_line function who we use for cleaning the stdin.
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

int inputComands(sHeader *stateList) { //Devuelve un 0 si esta bien y un 1 si esta mal el comando
    char cmd[MAXLENGTH100];
    char cmdAux[MAXLENGTH100];

    printf(STRINPUTCMD);
    scanf("%[^\n]", cmd);
    dump_line(stdin);

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

                            if (intAux != 0) {
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
                            if (strcmp(cmdAux, STRW) != 0){
                                intAux++;
                            }
                            if(intAux == 2){
                                printf(COLOR_RED STRERRORCMDOPT COLOR_RESET, cmdAux);
                                fail = 1;
                            }else{
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
    
    if(fail == 0){
         strcpy(stateList->cmdLine, cmd);
    }

    return fail;
}

void writeInFileHeader(sHeader stateList,  FILE * fp){
    char myTxt[MAXLENGTH1500];
    
}

void writeInFile(sHeader stateList, sNode node){
    if(strcmp(stateList.ouputFilename, STRNULL)){
        char fileNameTxt[MAXLENGTH24];
        int timeToWrite;
        FILE * fp;
        strlcat(fileNameTxt, stateList.ouputFilename, sizeof(fileNameTxt));
        strlcat(fileNameTxt, STRTYPEFILE, sizeof(fileNameTxt));
        if(strcmp(stateList.fileOperations, STRAP) == 0){
            fp = fopen(fileNameTxt, "a");
        }else{
            fp = fopen(fileNameTxt, "w");
        }
        if(fp == NULL){
            printf(COLOR_RED STRERRORFILE COLOR_RESET);
        }else{
            timeToWrite = 0;
            do{
                showMovement(node, stateList, timeToWrite, fp);
                fprintf(fp, STRJMPESP);
                fprintf(fp, STRJMPESP);
                timeToWrite++;
            }while(timeToWrite <= node.size);
        }
        fclose(fp);
    }else{
        printf(COLOR_GREEN STRSTDOUT COLOR_RESET);
    }
}

void dump_line(FILE * fp){
  int ch;

  while( (ch = fgetc(fp)) != EOF && ch != '\n' )
    /* null body */;
}
