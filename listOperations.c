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

int move(int org, int dest, int *movemt, int depth, sHeader *stateList, sTowersState *towers, sNode *node, int debug) {

    int auxDisk = 0;
    int i = 0;
    int k = 0;
    int disks = MAXOFDISK - 1; //MAXOFDISK se convertiria en stateList->diskNum

    if (towers->TowerInfo[org][i] == 0) {
        do {
            i++;
            auxDisk = towers->TowerInfo[org][i];
        } while (towers->TowerInfo[org][i] == 0);
        towers->TowerInfo[org][i] = 0;
    } else {
        auxDisk = towers->TowerInfo[org][i];
        towers->TowerInfo[org][i] = 0;
    }

    if (towers->TowerInfo[dest][k] == 0) {
        do {
            if (towers->TowerInfo[dest][k] == 0 && towers->TowerInfo[dest][k + 1] == 0) {
            } else {
                if (towers->TowerInfo[dest][k] == 0) {
                    towers->TowerInfo[dest][k] = auxDisk;
                }
            }

            if (k == disks && towers->TowerInfo[dest][k] == 0) {
                towers->TowerInfo[dest][k] = auxDisk;
            }
            k++;
        } while (k < MAXOFDISK); //MAXOFDISK se convertiria en stateList->diskNum
    } //else {
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
    stateList->moveState[mvmNumb].depth = depth; //esto no hara falta 
    stateList->moveState[mvmNumb].diskMoved = auxDisk; //esto no hara falta 
    stateList->moveState[mvmNumb].towerDest = dest; //esto no hara falta 
    stateList->moveState[mvmNumb].towerOrg = org; //esto no hara falta 
    towers->moves = (*movemt); //esto no hara falta 

    if (debug == TRUE) {
        printf("Move one disc from %d to %d\n", org, dest);
    }

    pushList(node, depth, org, dest, auxDisk, mvmNumb);

    return 1;
}

int hanoi(int nd, int org, int dest, int aux, int *movemt, int depth, sHeader *stateList, sTowersState *towers, sNode *node, int debug) {
    if (nd == 1) {
        *movemt = (*movemt + 1);
        move(org, dest, movemt, depth, stateList, towers, node, debug);
    } else {
        hanoi(nd - 1, org, aux, dest, movemt, depth + 1, stateList, towers, node, debug);
        *movemt = (*movemt + 1);
        move(org, dest, movemt, depth, stateList, towers, node, debug);
        hanoi(nd - 1, aux, dest, org, movemt, depth + 1, stateList, towers, node, debug);
    }
    return 1;
}// hanoi

void initTowers(sTowersState *towers, sHeader *stateList) { //la matriz se converiria a una dinamica!!
    towers->moves = 0;
    int diskValue = 0;
    for (int k = 0; k < stateList->towerNum; k++) {
        for (int i = 0; i < stateList->diskNum; i++) {
            if (k == 0) {
                diskValue++;
                towers->TowerInfo[k][i] = diskValue;
            } else {
                towers->TowerInfo[k][i] = 0;
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

void showMovement(sHeader stateList, int mvmNumber) { //ya no se podra hacer asi por el dinamismo
    int movement = mvmNumber - 1;
    printf("Move count %i , Rec Depth %i: it moves disc %i from T%i to T%i \n", mvmNumber, stateList.moveState[movement].depth, stateList.moveState[movement].diskMoved, stateList.moveState[movement].towerOrg, stateList.moveState[movement].towerDest);
}

void pushList(sNode *node, int depth, int towerOrg, int towerDest, int diskMoved, int mvmNumb) {
    sMovesState *movement;
    movement = (sMovesState *) malloc(sizeof (sMovesState));
    movement->mvmNumb = mvmNumb;
    movement->depth = depth;
    movement->towerOrg = towerOrg;
    movement->towerDest = towerDest;
    movement->diskMoved = diskMoved;

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
    node->moveState = NULL;
    node->size = 0;
}

void showList(sNode *node) {
    sMovesState *movement;
    movement = node->firstElement;

    for (int i = 0; i < node->size; i++) {
        printf("Move count %i, Rec Depth %i: it moves disc %i from T%i to T%i \n", movement->mvmNumb, movement->depth, movement->diskMoved, movement->towerOrg, movement->towerDest);
        movement = movement->prev;
    }
}