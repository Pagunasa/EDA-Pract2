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
    int debug = FALSE;
    int nd = MAXOFDISK, nt = MAXOFTOWERS;
    sHeader stateList;
    sTowersState tower;
    int **TowerInfo = 0;

    //Inicio del primer intento de recursividad
    sNode node;
    initList(&node);

    int movemnt = 1;
    int depth = 0;
    int pass;

    showCommands();
    initHeaderInfo(&stateList, nd, nt);

    do {
        pass = inputComands(&stateList);
    } while (pass != 0);

    initMatrix(&TowerInfo, stateList.diskNum, stateList.towerNum);

    if (debug == TRUE) {
        for (int i = 0; i < stateList.towerNum; i++) {
            printf("\n");
            for (int j = 0; j < stateList.diskNum; j++)
                printf("%d \n", TowerInfo[i][j]);
        }
    }

    //initTowers(&tower, &stateList);
    hanoi(stateList.diskNum, TOWERORIGIN, TOWERAUXILIAR, TOWERDESTINY, &movemnt, depth, &stateList, &tower, &node, debug, &TowerInfo);
    printf("\nMovimientos completados correctamente. \n\n");

    if (debug == TRUE) {
        for (int i = 0; i < stateList.towerNum; i++) {
            printf("\n");
            for (int j = 0; j < stateList.diskNum; j++)
                printf("%d \n", TowerInfo[i][j]);
        }
    }

    freeTheMemoryMatrix(&TowerInfo, stateList.towerNum);

    if (debug == TRUE) {
        showList(&node);
    }

    writeMenu(node);

    return (0);
} // main

void writeMenu(sNode Node) {
    char option;
    int mov;
    int mvmNumber;

    do {

        printf("Desea visualizar un movimiento?\n");
        printf("s-\t Elija un movimiento\n");
        printf("n-\t Salir \n");
        scanf("%c", &option);
        dump_line(stdin);

        switch (option) {
            case 's':
                // funcion mostrar
                printf("Total de movimentos: %i\n", Node.size);
                printf("Introduce numero de movimiento: ");
                scanf("%i", &mvmNumber);
                dump_line(stdin);

                if (mvmNumber != 0) {
                    showMovement(Node, mvmNumber);
                }
                //            }else {
                //                printf("Gracias por usar el programa\n");
                //            } 
                break;
            case 'n':
                //salir
                printf("Gracias por usar el programa\n");
                break;
            default:
                printf("La opcion introducida es incorrecta\n");
        }
    } while (option != 'n');

}
#endif 