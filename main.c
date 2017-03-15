/* 2016-17 Estructures de Dades i Algorismes I
 * 
 * Practice assignment 2: Hanoi Towers Game 
 * File: main.c
 * 
 * This file contains the hearth of hanoi game. It only calls another 
 * functions for doing the caracteristics that the game need for working 
 * and have a function who is used for show the menu (writeMenu) and have 
 * the funcionality of show a movement with his matix who is associated
 * 
 * It can only operate with 3 towers and the number of disk can be changed 
 * manually putting it in the inputComands function.
 * 
 * Prepared by: 
 * Modified: February 2017
 */

#if 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "listOperations.h"
#include "filesOperations.h"
#include "mainOperations.h"

// This function indicates a move of one disk

//void move(int towerorg, int towerdest)

// Recursive function to move nd disks from the origin tower towerorg, to 
// destination tower towerdest, using toweraux as auxiliary tower.
// it doesn't return anything and instead it prints information of the move of 
// the disks to display

//void hanoi(int nd, int towerorg, int towerdest, int toweraux)

int main(int argc, char *argv[]) {

    char cmd[MAXLENGTH500];
    int cmdCounter = 1;
    strlcpy(cmd, STRWHTSPACE, sizeof (cmd));

    /*In this part of the code we get the arguments of the program and use 
     * strlcat for send the final string to the inputCommands fucntion who 
     * comproves that the structure of the command is correct. 
     */
    char path[MAXLENGTH1500];
    strlcpy(path, argv[0], sizeof (path));

    if (argc > 1 && argc < 9) {
        do {
            strlcat(cmd, argv[cmdCounter], sizeof (cmd));
            strlcat(cmd, STRSPACE, sizeof (cmd));
            cmdCounter++;
        } while (cmdCounter < argc);
    } else if (argc > 8) {
        printf(COLOR_RED "Too many arguments supplied.\n" COLOR_RESET);
        exit(0);
    } else {
        printf(COLOR_RED "Argument expected.\n" COLOR_RESET);
        exit(0);
    }

    if (DEBUG == TRUE) {
        printf("The argument supplied is %s\n", cmd);
    }

    int nd = MAXOFDISK, nt = MAXOFTOWERS;
    sHeader stateList;
    int **TowerInfo = 0;
    sNode node;
    initList(&node);

    int movemnt = 1;
    int depth = 0;
    int pass;

    //showCommands(); //this is used in a old version for show the possibilities of the arguments
    initHeaderInfo(&stateList, nd, nt);
    updateDate(&stateList, FIRST);

    /*This loop was used in a old version for force the user to 
     *reintroduce the command.
     */
    // do {
    pass = inputComands(&stateList, cmd);
    //} while (pass != 0); 
   
    if (pass == 1) {
        exit(0);
    }

    if (DEBUG == TRUE) {
        printf("%s", stateList.cmdLine);
    }

    initMatrix(&TowerInfo, stateList.diskNum, stateList.towerNum);

    if (DEBUG == TRUE) {
        for (int i = 0; i < stateList.towerNum; i++) {
            printf("\n");
            for (int j = 0; j < stateList.diskNum; j++)
                printf("%d \n", TowerInfo[i][j]);
        }
    }

    hanoi(stateList.diskNum, TOWERORIGIN, TOWERAUXILIAR, TOWERDESTINY, &movemnt, depth, &stateList, &node, &TowerInfo);
    printf(COLOR_GREEN STRPASSCORRECT COLOR_RESET);
    updateDate(&stateList, SECOND);
    writeInFile(stateList, node, path);

    if (DEBUG == TRUE) {
        for (int i = 0; i < stateList.towerNum; i++) {
            printf("\n");
            for (int j = 0; j < stateList.diskNum; j++)
                printf("%d \n", TowerInfo[i][j]);
        }
    }

    freeTheMemoryMatrix(&TowerInfo, stateList.towerNum);

    if (DEBUG == TRUE) {
        showList(&node);
    }

    writeMenu(node, stateList);
    freeTheListMemory(&node);
    return (0);
}

/*This function have a Node and sateList of parameters for show to the user
 * the movement that was introduced in the program. The funcionality if for 
 * comprove that the user wants to show a movement and if it was to show it
 * then show the movement for the console.
 */
void writeMenu(sNode Node, sHeader stateList) {
    char option;
    int mvm, pass;
    FILE * fp;
    fp = stdout;
    do {
        printf(STRMENU1_1);
        printf(STRMENU1_2);
        printf(STRMENU1_3);
        option = getc(stdin);
        dump_line(stdin);
        switch (option) {
            case SEEMOVEMENT:
                do {
                    do {
                        printf(STRMENU2_1, Node.size);
                        printf(STRMENU2_2);
                        pass = scanf("%i", &mvm);
                        dump_line(stdin);
                        if (pass == 0 || mvm < 0 || mvm > Node.size) {
                            printf(COLOR_RED STRERRORINPUT COLOR_RESET);
                        }
                    } while (pass == 0 || mvm < 0 || mvm > Node.size);
                    showMovement(Node, stateList, mvm, fp);
                } while (mvm != 0);
                break;
            case NOTSEEMOVEMENT:
                printf(STRTHNKS);
                break;
            default:
                printf(STRERRORINPUT);
        }
    } while (option != NOTSEEMOVEMENT);
}
#endif 