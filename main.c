/* 2016-17 Estructures de Dades i Algorismes I
 * 
 * Practice assignment 2: Hanoi Towers Game 
 * File: main.c
 * 
 * This file contains the hearth of hanoi game. It only calls another 
 * functions for doing the caracteristics that the game need for working
 * 
 * It can only operate with 3 towers and the number of disk can be changed 
 * manually putting it in the inputComands function.
 * 
 * Prepared by: 
 * Modified: February 2017
 */

#if 1

#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "listOperations.h"
#include "filesOperations.h"
#include "mainOperations.h"


//#define NDISCS    5 // Number of discs to consider
//#define NTOWERS   3 // Number of towers to consider: it cannot be changed in this version

// This function indicates a move of one disk

//void move(int towerorg, int towerdest){
//    
//    printf("Move one disc from %d to %d\n", 
//            towerorg, towerdest);
//    
//}// move

// Recursive function to move nd disks from the origin tower towerorg, to 
// destination tower towerdest, using toweraux as auxiliary tower.
// it doesn't return anything and instead it prints information of the move of 
// the disks to display

//void hanoi(int nd, int towerorg, int towerdest, int toweraux){
//    
//    if (nd == 1){

//        move(towerorg, towerdest);
//    
//        move(towerorg, towerdest);
//        hanoi(nd - 1, toweraux, towerdest, towerorg);
//    }                                                     
//}// hanoi

int main() {
    int nd = MAXOFDISK, nt = MAXOFTOWERS;
    sHeader stateList;
    int **TowerInfo = 0;
    sNode node;
    initList(&node);
    char auxDate[MAXLENGTH30];
    
    int movemnt = 1;
    int depth = 0;
    int pass;

    showCommands();
    initHeaderInfo(&stateList, nd, nt);
    updateDate(&stateList, FIRST);

    do {
        pass = inputComands(&stateList);
    } while (pass != 0);

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
    writeInFile(stateList, node);
    
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

    return (0);
} // main

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