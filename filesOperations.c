#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "filesOperations.h"

void showCommands() {
    printf("Los commandos para operar son: \n");
    printf(COLOR_MAGENTA "hanoiplus" COLOR_RESET);
    printf(COLOR_CYAN " -d <numero de discos>" COLOR_RESET);
    printf(COLOR_YELLOW " -f <nombre del fichero>" COLOR_RESET);
    printf(COLOR_GREEN " -o <codigo de operacion> \n\n" COLOR_RESET);

    printf("Los codigos de operacion son: \n");
    printf(COLOR_GREEN "ap -> Guardar la informacion en un fichero existente\n");
    printf("w -> Crear un nuevo fichero o aplastar uno existente\n\n"COLOR_RESET);
}

void inputComands(sHeader *stateList) {
    char cmd[MAXLENGTH100];
    char cmdAux[MAXLENGTH100];

    printf("Introduce el comando: \n");
    scanf("%[^\n]", cmd);

    int i = 0, j = 0, intAux;
    int moreCmds = 0;

    while (i < strlen(cmd)) {
        if (cmd[i] != ' ') {
            cmdAux[i] = cmd[i];
        } else {
            cmdAux[i] = '\0';
            moreCmds = 1;
            if (strcmp(cmdAux, "hanoiplus") == 0) {
                i++;
                j = 0;
                memset(cmdAux, '\0', strlen(cmdAux));

                while (i < strlen(cmd)) {
                    if (cmd[i] != ' ') {
                        cmdAux[j] = cmd[i];
                    } else {
                        i++;
                        int e = 0;
                        if (strcmp(cmdAux, "-d") == 0) {
                            memset(cmdAux, '\0', strlen(cmdAux));
                            while (e < strlen(cmd)) {
                                if (cmd[i] != '\0' || cmd[i] != ' ') {
                                    cmdAux[e] = cmd[i];
                                    e++;
                                } else {
                                    e = strlen(cmd);
                                }
                                i++;
                            }
                            intAux = atoi(cmdAux);
                            if (intAux != 0) {
                                stateList->diskNum = intAux;
                            }
                            printf(COLOR_RED "Comando no valido, no se puede introducir -d %s \n" COLOR_RESET, cmdAux);

                        } else if (strcmp(cmdAux, "-f") == 0) {
                            memset(cmdAux, '\0', strlen(cmdAux));
                            while (e < strlen(cmd)) {
                                
                            }
                        } else if (strcmp(cmdAux, "-o") == 0) {
                            while (cmd[i] != ' ') {

                            }
                        } else {
                            printf(COLOR_RED "Comando no valido, no se puede introducir %s \n" COLOR_RESET, cmdAux);
                            i = strlen(cmd);
                        }
                    }
                    i++;
                    j++;
                }

            } else {
                printf(COLOR_RED "Comando no valido, no se puede introducir %s \n" COLOR_RESET, cmdAux);
                i = strlen(cmd);
            }

        }
        i++;
    }

    if (moreCmds == 0) {
        if (strcmp(cmd, "hanoiplus") == 0) {
            strcpy(stateList->cmdLine, cmd);
        }
    }
}