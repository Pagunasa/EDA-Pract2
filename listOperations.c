/* 2016-17 Estructures de Dades i Algorismes I
 * 
 * Practice assignment 2: Hanoi Towers Game 
 * File: listOperations.c
 * 
 * This file contains the initalation and the logic of hanoi game. 
 * It only have four functions for moving the disks and the hanoi function
 * who works recursively and calls move for resolve the game, and we have 
 * initTowers and initHeaderInfo who set a default values for the structs
 * 
 * Prepared by: 
 * Modified: February 2017
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"
#include "listOperations.h"

int move(int org, int dest, int *movemt, int depth, sHeader *stateList, sNode *node, int ***TowerInfo) {

    int auxDisk = 0;
    int i = 0;
    int k = 0;
    int disks = stateList->diskNum - 1; //MAXOFDISK se convertiria en stateList->diskNum

    if ((*TowerInfo)[org][i] == 0) {
        do {
            i++;
            auxDisk = (*TowerInfo)[org][i];
        } while ((*TowerInfo)[org][i] == 0);
        (*TowerInfo)[org][i] = 0;
    } else {
        auxDisk = (*TowerInfo)[org][i];
        (*TowerInfo)[org][i] = 0;
    }

    if ((*TowerInfo)[dest][k] == 0) {
        do {
            if ((*TowerInfo)[dest][k] == 0 && (*TowerInfo)[dest][k + 1] == 0) {
            } else {
                if ((*TowerInfo)[dest][k] == 0) {
                    (*TowerInfo)[dest][k] = auxDisk;
                }
            }

            if (k == disks && (*TowerInfo)[dest][k] == 0) {
                (*TowerInfo)[dest][k] = auxDisk;
            }
            k++;
        } while (k < stateList->diskNum);
    }

    //    if (towers->TowerInfo[org][i] == 0) {
    //        do {
    //            i++;
    //            auxDisk = towers->TowerInfo[org][i];
    //        } while (towers->TowerInfo[org][i] == 0);
    //        towers->TowerInfo[org][i] = 0;
    //    } else {
    //        auxDisk = towers->TowerInfo[org][i];
    //        towers->TowerInfo[org][i] = 0;
    //    }
    //
    //    if (towers->TowerInfo[dest][k] == 0) {
    //        do {
    //            if (towers->TowerInfo[dest][k] == 0 && towers->TowerInfo[dest][k + 1] == 0) {
    //            } else {
    //                if (towers->TowerInfo[dest][k] == 0) {
    //                    towers->TowerInfo[dest][k] = auxDisk;
    //                }
    //            }
    //
    //            if (k == disks && towers->TowerInfo[dest][k] == 0) {
    //                towers->TowerInfo[dest][k] = auxDisk;
    //            }
    //            k++;
    //        } while (k < stateList->diskNum - 1); //MAXOFDISK se convertiria en stateList->diskNum
    //    } 

    //else {
    //        do {
    //            k++;
    //        } while (towers->TowerInfo[dest][k] != 0);
    //        towers->TowerInfo[dest][k] = auxDisk;
    //    }

    //    sTowersState *previous = &towers[(*movemt - 1)];
    //    sTowersState *current = &towers[(*movemt)];
    //    
    //    int orgLast;
    //    int destLast;
    //    for (int k = 0; k < MAXOFTOWERS; k++) {
    //        for (int i = 0; i < MAXOFDISK; i++) {
    //            current->TowerInfo[k][i] = previous->TowerInfo[k][i];
    //            if (i == org && current->TowerInfo[k][i] != 0) {
    //                orgLast = i;
    //            } else if (i == dest && current->TowerInfo[k][i] != 0) {
    //                destLast = i;
    //            }
    //        }
    //    }
    //    int temp = current->TowerInfo[org][orgLast];
    //    current->TowerInfo[org][orgLast + 1] = 0;
    //    current->TowerInfo[dest][destLast + 1] = 0;

    int mvmNumb = (*movemt) - 1; //esto no hara falta 
//    stateList->moveState[mvmNumb].depth = depth; //esto no hara falta 
//    stateList->moveState[mvmNumb].diskMoved = auxDisk; //esto no hara falta 
//    stateList->moveState[mvmNumb].towerDest = dest; //esto no hara falta 
//    stateList->moveState[mvmNumb].towerOrg = org; //esto no hara falta 
// towers->moves = (*movemt); //esto no hara falta 

    if (DEBUG == TRUE) {
        printf(STRDBG1, auxDisk, org, dest);
    }

    pushList(node, depth, org, dest, auxDisk, mvmNumb, (*TowerInfo), stateList);

    return 1;
}

int hanoi(int nd, int org, int dest, int aux, int *movemt, int depth, sHeader *stateList, sNode *node, int ***TowerInfo) {
    if (nd == 1) {
        *movemt = (*movemt + 1);
        move(org, dest, movemt, depth, stateList, node, TowerInfo);
    } else {
        hanoi(nd - 1, org, aux, dest, movemt, depth + 1, stateList, node, TowerInfo);
        *movemt = (*movemt + 1);
        move(org, dest, movemt, depth, stateList, node, TowerInfo);
        hanoi(nd - 1, aux, dest, org, movemt, depth + 1, stateList, node, TowerInfo);
    }
    return 1;
}// hanoi

void initMatrix(int ***TowerInfo, int columnas, int filas) {
    *TowerInfo = malloc(filas * sizeof (int *));

    ERRORMEMORY((*TowerInfo == NULL), (COLOR_RED STRERRORMEMORY COLOR_RESET));
//    if (*TowerInfo == NULL) {
//        printf(COLOR_RED STRERRORMEMORY COLOR_RESET);
//        exit(0);
//    }

    for (int i = 0; i < filas; i++) {
        (*TowerInfo)[i] = malloc(columnas * sizeof (int *));
        
        ERRORMEMORY(((*TowerInfo)[i] == NULL), (COLOR_RED STRERRORMEMORY COLOR_RESET));
//        if ((*TowerInfo)[i] == NULL) {
//            printf(COLOR_RED STRERRORMEMORY COLOR_RESET);
//            exit(0);
//        }
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (i == 0) {
                (*TowerInfo)[i][j] = j + 1;

            } else {
                (*TowerInfo)[i][j] = 0;
            }
        }
    }
}

void initHeaderInfo(sHeader *stateList, int nd, int nt) {
    stateList->diskNum = nd;
    strcpy(stateList->fileOperations, "ap");
    strcpy(stateList->ouputFilename, "NULL");
    stateList->towerNum = nt;
}

void showMovement(sNode node, int mvmNumber) {

    sMovesState *movementAux; //sera nuestro auxiliar
    movementAux = node.firstElement;

    for (int i = 0; i < node.size; i++) {
        if (mvmNumber == movementAux->mvmNumb) {
            printf(STRSHWMVM, mvmNumber, movementAux->depth, movementAux->diskMoved, movementAux->towerOrg, movementAux->towerDest);
            //            for (int i = 0; i < 3; i++) {
            //                printf("\n");
            //                for (int j = 0; j < 6; j++)
            //                    printf("%d \n", movementAux->towerStatus[i][j]);
            //            }
        }
        movementAux = movementAux->prev;
    }
}

void cpyMtr(int ***TowerInfo, int **TowerTCpy, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            (*TowerInfo)[i][j] = TowerTCpy[i][j];
        }
    }
}

void pushList(sNode *node, int depth, int towerOrg, int towerDest, int diskMoved, int mvmNumb, int **towerStatus, sHeader *stateList) {
    sMovesState *movement;
    movement = (sMovesState *) malloc(sizeof (sMovesState));
    
    ERRORMEMORY((movement == NULL), (COLOR_RED STRERRORMEMORY COLOR_RESET));
//
//    if(movement == NULL){
//        printf(COLOR_RED STRERRORMEMORY COLOR_RESET);
//        exit(0);
//    }
    
    movement->mvmNumb = mvmNumb;
    movement->depth = depth;
    movement->towerOrg = towerOrg;
    movement->towerDest = towerDest;
    movement->diskMoved = diskMoved;
    initMatrix(&movement->towerStatus, stateList->diskNum, stateList->towerNum);
    cpyMtr(&movement->towerStatus, towerStatus, stateList->towerNum, stateList->diskNum);

    if (node->firstElement == NULL) {
        node->firstElement = movement;
        movement->next = NULL;
        movement->prev = NULL;
    } else {
        movement->next = NULL;
        movement->prev = node->firstElement;
        node->firstElement->next = movement;
        node->firstElement = movement;
    }
    node->size++;
}

void initList(sNode *node) {
    node->firstElement = NULL;
    node->size = 0;
}

void showList(sNode *node) {
    sMovesState *movement;
    movement = node->firstElement;

    for (int i = 0; i < node->size; i++) {
        printf(STRSHWMVM, movement->mvmNumb, movement->depth, movement->diskMoved, movement->towerOrg, movement->towerDest);
        movement = movement->prev;
    }
}

void freeTheMemoryMatrix(int ***TowerInfo, int filas) {
    for (int i = 0; i < filas; i++)
        free((*TowerInfo)[i]);
    free(*TowerInfo);
    *TowerInfo = 0;
}