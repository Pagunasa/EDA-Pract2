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

    for (int i = 0; i < filas; i++) {
        (*TowerInfo)[i] = malloc(columnas * sizeof (int *));
        ERRORMEMORY(((*TowerInfo)[i] == NULL), (COLOR_RED STRERRORMEMORY COLOR_RESET));
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

void showMovement(sNode node, sHeader stateList, int mvmNumber) {
    sMovesState *movementAux; //sera nuestro auxiliar
    movementAux = node.firstElement;

    for (int i = 0; i < node.size; i++) {
        if (mvmNumber == movementAux->mvmNumb) {
            printf(STRSHWMVM, mvmNumber, movementAux->depth, movementAux->diskMoved, movementAux->towerOrg, movementAux->towerDest);
            showMtr(movementAux->towerStatus, stateList);
        }
        movementAux = movementAux->prev;
    }
}

//-----------------------------------------------------------------------------------//

void showMtr(int **MvmState, sHeader stateList) {
    int sizeOfString = stateList.diskNum * (stateList.towerNum * (stateList.diskNum + 1)) * 4;
    char myTxt[sizeOfString], myTxtAux[sizeOfString], myTxtAux1[sizeOfString], myTxtAux2[sizeOfString], myTxtAux3[sizeOfString];
    int e, pos0, pos1, pos2, rep, aux, aux2;
    strlcpy(myTxt, STRWHTSPACE, sizeof (myTxt));
    rep = stateList.diskNum - 1;

    //for (int i = 0; i < stateList.towerNum; i++) {
    //strlcpy(myTxt, STRWHTSPACE, sizeof(myTxt));
    e = 0;
    pos0 = 0;
    pos1 = 1;
    pos2 = 2;
    aux2 = 0;
    aux = 0;
    
    for (int j = 0; j < stateList.diskNum; j++) {
        strlcpy(myTxtAux1, STRWHTSPACE, sizeof (myTxtAux1));
        strlcpy(myTxtAux2, STRWHTSPACE, sizeof (myTxtAux2));
        strlcpy(myTxtAux3, STRWHTSPACE, sizeof (myTxtAux3));
        //            do {
        //                //strlcat(myTxt, STRWHTSPACE, sizeof (myTxt));
        //                //snprintf(myTxt, sizeof (myTxt), STRPROF, j);
        //                //strlcat(myTxt, STRPROF, sizeof (myTxt));
        //                if (e == rep / 2) {
        //                    strlcat(myTxt, STRSEPA, sizeof (myTxt));
        //                } else {
        //                    strlcat(myTxt, STREMPTY, sizeof (myTxt));
        //                }
        //                //strlcat(myTxt, STRWHTSPACE, sizeof (myTxt));
        //                 e++;
        //            } while (e <= rep);
        // strlcat(myTxt, STRJMP, sizeof (myTxt));
        PRINTSTRTOSTR((MvmState[pos0][j] == 0), myTxtAux1, MvmState[pos0][j], STREMPTY, e, stateList.diskNum, aux, aux2);
        PRINTSTRTOSTR((MvmState[pos1][j] == 0), myTxtAux2, MvmState[pos1][j], STREMPTY, e, stateList.diskNum, aux, aux2);
        PRINTSTRTOSTR((MvmState[pos2][j] == 0), myTxtAux3, MvmState[pos2][j], STREMPTY, e, stateList.diskNum, aux, aux2);

        //        if (MvmState[pos0][j] == 0) {
        //            do {
        //                strlcat(myTxtAux1, STREMPTY, sizeof (myTxtAux1));
        //                e++;
        //            } while (e < stateList.diskNum);
        //            strlcat(myTxtAux1, STRSEPA, sizeof (myTxtAux1));
        //            e = 0;
        //            do {
        //                strlcat(myTxtAux1, STREMPTY, sizeof (myTxtAux1));
        //                e++;
        //            } while (e < stateList.diskNum);
        //            e = 0;
        //        } else {
        //            do {
        //                strlcat(myTxtAux1, STRDSK, sizeof (myTxtAux1));
        //                e++;
        //            } while (e < stateList.diskNum);
        //            strlcat(myTxtAux1, STRSEPA, sizeof (myTxtAux1));
        //            e = 0;
        //            do {
        //                strlcat(myTxtAux1, STRDSK, sizeof (myTxtAux1));
        //                e++;
        //            } while (e < stateList.diskNum);
        //            e = 0;
        //        }
        //        do {
        //            strlcat(myTxtAux1, STREMPTY, sizeof (myTxtAux1));
        //            e++;
        //        } while (e < stateList.diskNum);
        //        strlcat(myTxtAux1, STRSEPA, sizeof (myTxtAux1));
        //        e = 0;
        //        do {
        //            strlcat(myTxtAux1, STREMPTY, sizeof (myTxtAux1));
        //            e++;
        //        } while (e < stateList.diskNum);
        //        e = 0;
        //
        //        do {
        //            strlcat(myTxtAux2, STREMPTY, sizeof (myTxtAux2));
        //            e++;
        //        } while (e < stateList.diskNum);
        //        strlcat(myTxtAux2, STRSEPA, sizeof (myTxtAux2));
        //        e = 0;
        //        do {
        //            strlcat(myTxtAux2, STREMPTY, sizeof (myTxtAux2));
        //            e++;
        //        } while (e < stateList.diskNum);
        //        e = 0;

        //        do {
        //            strlcat(myTxtAux3, STREMPTY, sizeof (myTxtAux3));
        //            e++;
        //        } while (e < stateList.diskNum);
        //        strlcat(myTxtAux3, STRSEPA, sizeof (myTxtAux3));
        //        e = 0;
        //        do {
        //            strlcat(myTxtAux3, STREMPTY, sizeof (myTxtAux3));
        //            e++;
        //        } while (e < stateList.diskNum);
        //        e = 0;

        //snprintf(myTxtAux, sizeof (myTxt), "H %i\t%i\t%i\t%i", rep, MvmState[pos0][j], MvmState[pos1][j], MvmState[pos2][j]);
        snprintf(myTxtAux, sizeof (myTxt), "H %i\t%s\t%s\t%s", rep, myTxtAux1, myTxtAux2, myTxtAux3);
        strlcat(myTxt, myTxtAux, sizeof (myTxt));
        //printf("H %i\t%i\t%i\t%i", rep,MvmState[pos0][j], MvmState[pos1][j], MvmState[pos2][j]);
        //printf("\n");
        strlcat(myTxt, STRJMP, sizeof (myTxt));
        rep--;

    }
    //strlcat(myTxt, STRJMP, sizeof (myTxt));
    //}


    printf("%s \n", myTxt);


    //strlcat(myTxt, "\t", sizeof (myTxt));
    //        for (int j = 0; j < stateList.diskNum; j++) {
    //            e = 0;
    //
    //            do {
    //                if (MvmState[i][j] != 0) {
    //                    if (e < MvmState[i][j]) {
    //                        printf(STRDSK);
    //                    } else {
    //                        printf(STREMPTY);
    //                    }
    //                } else {
    //                    printf(STREMPTY);
    //                }
    //                e++;
    //            } while (e < stateList.diskNum);
    //            printf(STRSEPA);
    //            e = 0;
    //            do {
    //                if (MvmState[i][j] != 0) {
    //                    if (e < MvmState[i][j]) {
    //                        printf(STRDSK);
    //                    } else {
    //                        printf(STREMPTY);
    //                    }
    //                } else {
    //                    printf(STREMPTY);
    //                }
    //                e++;
    //            } while (e < stateList.diskNum);
    //
    //            printf("\n");
    //
    //
    //        }
    // }

}
//-----------------------------------------------------------------------------------//

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