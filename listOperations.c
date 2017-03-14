/* 2016-17 Estructures de Dades i Algorismes I
 * 
 * Practice assignment 2: Hanoi Towers Game 
 * File: listOperations.c
 * 
 * This file contains the initalation and the logic of hanoi game. 
 * It only have twelve functions for moving the disks and the hanoi function
 * who works recursively and calls move for resolve the game, we have 
 * initMatrix who inicialize the dinamic matrix, initHeaderInfo who set a default 
 * values for the struct SHeader, showMovement who shows a movement, initList 
 * who inicialize the dinamic list, pushList who add one movement to the list,
 * showList who show all the basic information of all of the movements, 
 * freeTheMemoryMatrix who free the memory reserved for the dinamic matrix, 
 * cpyMtr who copy the matrix after one momvement to the struct of his associate
 * movement, showMtr who show the drawing of the hanoi towers and his disks and 
 * the updateDate who update the date for showing it in the header.
 * 
 * Prepared by: 
 * Modified: February 2017
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"
#include "listOperations.h"

/*This function have 7 parameters and his function is move one disk from the 
 * origin tower (org) to the destiny tower (dest), and another parameters are 
 * the depth for add to the sMoveState struct, we also pass stateList pointer 
 * for get the number of disk and movement pointer for getting the movement 
 * number, the sNode pointer is for get the first movement and add to the list 
 * one more, and, for finish we pass the pointer os the array of the disks for
 * update his status.  
 */
int move(int org, int dest, int *movemt, int depth, sHeader *stateList, sNode *node, int ***TowerInfo) {

    int auxDisk = 0;
    int i = 0;
    int k = 0;
    int disks = stateList->diskNum - 1;

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

    int mvmNumb = (*movemt) - 1; 
    
    if (DEBUG == TRUE) {
        printf(STRDBG1, auxDisk, org, dest);
    }

    pushList(node, depth, org, dest, auxDisk, mvmNumb, (*TowerInfo), stateList);

    return 1;
}

/*This is a recursive function who is finality is to move a disk from the origin
 * to the destiny using the auxiliar, it calls himself unless the nd is equals to
 * 1 in this case the recursion ends and move the disk, then return and move 
 * another time  and for finish the hanoi function recall himself.
 */
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
}

/*This function gets three parameters, the pointer os the matrix, the number of
 * collumns and of rows, the objective of this function is to reserve space in 
 * memory for the matrix and inicialize the first row with the number of the 
 * disk and the others with 0. 
 */
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

/*This function have three parameters, a pointer of sHeader for update the header
 * and the number of towers and disks, this function is for inicialize te header
 * with a default values before it was update with the user command.
 */
void initHeaderInfo(sHeader *stateList, int nd, int nt) {
    stateList->diskNum = nd;
    strcpy(stateList->fileOperations, "ap");
    strcpy(stateList->ouputFilename, "NULL");
    stateList->towerNum = nt;
}

/*This function have four parameters, the sNode for get the first movement, the 
 * stateList for pass it to showMtr, the movement number for compare with the 
 * number of every SmoveState and the file for print in that.
 */
void showMovement(sNode node, sHeader stateList, int mvmNumber, FILE *fp) {
    sMovesState *movementAux; //sera nuestro auxiliar
    movementAux = node.firstElement;

    for (int i = 0; i < node.size; i++) {
        if (mvmNumber == movementAux->mvmNumb) {
            fprintf(fp, STRSHWMVM, mvmNumber, movementAux->depth, movementAux->diskMoved, movementAux->towerOrg, movementAux->towerDest);
            showMtr(movementAux->towerStatus, stateList, fp);
        }
        movementAux = movementAux->prev;
    }
}

//-----------------------------------------------------------------------------------//

/*This function gets a matrix of ints, the sHeader struct and a file, is 
 * objective is to show the matrix who is introduced, and we need the sHeader 
 * because in this struct we save the number of towers and disks.
 */
void showMtr(int **MvmState, sHeader stateList, FILE * fp) {
    int sizeOfString = stateList.diskNum * (stateList.towerNum * (stateList.diskNum + 1)) * 4;
    char myTxt[sizeOfString], myTxtAux[sizeOfString], myTxtAux1[sizeOfString], myTxtAux2[sizeOfString], myTxtAux3[sizeOfString];
    int e, pos0, pos1, pos2, rep, aux, aux2, endLine, loopSize;

    strlcpy(myTxt, STRWHTSPACE, sizeof (myTxt));
    rep = stateList.diskNum - 1;

    e = 0;
    pos0 = 0;
    pos1 = 1;
    pos2 = 2;
    aux2 = 0;
    aux = 0;
    endLine = 0;
    strlcat(myTxt, STRJMPESP, sizeof (myTxt));
    
    for (int j = 0; j < stateList.diskNum; j++) {
        strlcpy(myTxtAux1, STRWHTSPACE, sizeof (myTxtAux1));
        strlcpy(myTxtAux2, STRWHTSPACE, sizeof (myTxtAux2));
        strlcpy(myTxtAux3, STRWHTSPACE, sizeof (myTxtAux3));
        
        PRINTSTRTOSTR((MvmState[pos0][j] == 0), myTxtAux1, MvmState[pos0][j], STREMPTY, e, stateList.diskNum, aux, aux2);
        PRINTSTRTOSTR((MvmState[pos1][j] == 0), myTxtAux2, MvmState[pos1][j], STREMPTY, e, stateList.diskNum, aux, aux2);
        PRINTSTRTOSTR((MvmState[pos2][j] == 0), myTxtAux3, MvmState[pos2][j], STREMPTY, e, stateList.diskNum, aux, aux2);
       
        snprintf(myTxtAux, sizeof (myTxt), STRPROF, rep, myTxtAux1, myTxtAux2, myTxtAux3);
        strlcat(myTxt, myTxtAux, sizeof (myTxt));

        strlcat(myTxt, STRJMPESP, sizeof (myTxt));
        rep--;
    }

    loopSize = (((stateList.diskNum * TWOO) + ONE) * stateList.towerNum) + FOUR;

    strlcat(myTxt, TAB, sizeof (myTxt));
    do {
        strlcat(myTxt, ENDLINE, sizeof (myTxt));
        endLine++;
    } while (endLine <= loopSize);

    fprintf(fp, "%s \n", myTxt);
}
//-----------------------------------------------------------------------------------//

/*This function gets the origin matix, the destiny matrix, the numbers of rows 
 * and of the columns,the objective is to copy in the destiny the origin.
 */
void cpyMtr(int ***TowerInfo, int **TowerTCpy, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            (*TowerInfo)[i][j] = TowerTCpy[i][j];
        }
    }
}

/*This function get eigth parameters, all of the parameters is for update the 
 * information of the movements, and we also pass the SHeader because we need
 * for call tje init and copy Matrix.
 */
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

/*This function only have one parameter who is a pointer of sNode who update the
 * list with a default values for no have any problem when we want to add a new
 * movement to the list.
 */
void initList(sNode *node) {
    node->firstElement = NULL;
    node->size = 0;
}

/*This fucntion gets a pointer of sNode and his objective is show only the basic
 * information of the movements, is a debug fucntion.
 */
void showList(sNode *node) {
    sMovesState *movement;
    movement = node->firstElement;

    for (int i = 0; i < node->size; i++) {
        printf(STRSHWMVM, movement->mvmNumb, movement->depth, movement->diskMoved, movement->towerOrg, movement->towerDest);
        movement = movement->prev;
    }
}

/*This function get the pointer of the matrix and  the numner of rows, and his 
 * objective is free the memory wo was reserved to the matrix.
 */
void freeTheMemoryMatrix(int ***TowerInfo, int filas) {
    for (int i = 0; i < filas; i++)
        free((*TowerInfo)[i]);
    free(*TowerInfo);
    *TowerInfo = 0;
}

/*This function get a pòinter od sHeader who we want to save the date and a int
 * for loock if it was the init of the end date, id the number is equals to one
 * is the initDate else is the endDate.
 */
void updateDate(sHeader *stateList, int FirstOSec){
    time_t result = time(NULL);
    if(FirstOSec == FIRST){
        if(result != -1)
           strlcpy(stateList->initDate, asctime(gmtime(&result)), sizeof(stateList->initDate));  
    }else{
        if(result != -1)
           strlcpy(stateList->endDate, asctime(gmtime(&result)), sizeof(stateList->endDate));  
    }
}