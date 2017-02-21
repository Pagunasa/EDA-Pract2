
#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "listOperations.h"

int move(int org, int dest, int move, int depth, sMovesState *stateList, sTowersState *towers){
    
    printf("Move one disc from %d to %d\n", 
            org, dest);
    return 1;
}

int hanoi(int nd, int org, int dest, int aux, int movemt, int depth, sMovesState *stateList, sTowersState *towers){
    if (nd == 1){
        move(org, dest, movemt, depth, stateList, towers);
    }
    else{
        hanoi(nd - 1, org, aux, dest, move, depth, stateList, towers);
        move(org, dest, movemt, depth, stateList, towers);
        hanoi(nd - 1, aux, dest, org, move, depth, stateList, towers);
    }      
    return 1;
}// hanoi


