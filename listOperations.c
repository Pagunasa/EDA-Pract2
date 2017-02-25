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
#include "structs.h"
#include "listOperations.h"

int move(int org, int dest, int *movemt, int depth, sHeader *stateList, sTowersState *towers) {

    int auxDisk = 0;
    int i = 0;
    int k = 0;
    int disks = MAXOFDISK -1;
    
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
    
    if (towers->TowerInfo[dest][k] == 0){
        do{
            if(towers->TowerInfo[dest][k] == 0 && towers->TowerInfo[dest][k+1] == 0){
            }else{
                if(towers->TowerInfo[dest][k] == 0){
                    towers->TowerInfo[dest][k] = auxDisk;
                }
            }
            
            if (k == disks && towers->TowerInfo[dest][k] == 0){
                towers->TowerInfo[dest][k] = auxDisk;
            }
            k++;
        }while(k < MAXOFDISK);
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

    int mvmNumb = (*movemt) -1;
    stateList->moveState[mvmNumb].depth = depth;
    stateList->moveState[mvmNumb].diskMoved = auxDisk;
    stateList->moveState[mvmNumb].towerDest = dest;
    stateList->moveState[mvmNumb].towerOrg = org;
    towers->moves = (*movemt);
    printf("Move one disc from %d to %d\n", org, dest);
    return 1;
}

int hanoi(int nd, int org, int dest, int aux, int *movemt, int depth, sHeader *stateList, sTowersState *towers) {
    if (nd == 1) {
        *movemt = (*movemt + 1);
        move(org, dest, movemt, depth, stateList, towers);
    } else {
        hanoi(nd - 1, org, aux, dest, movemt, depth+ 1, stateList, towers);
        *movemt = (*movemt + 1);
        move(org, dest, movemt, depth, stateList, towers);
        hanoi(nd - 1, aux, dest, org, movemt, depth+ 1, stateList, towers);
    }
    return 1;
}// hanoi

void initTowers(sTowersState *towers, sHeader *stateList) {
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

void initHeaderInfo(sHeader *stateList, int nd, int nt){
    stateList->diskNum = nd;
    strcpy(stateList->fileOperations, "ap");
    strcpy(stateList->ouputFilename, "NULL");
    stateList->towerNum = nt;
}