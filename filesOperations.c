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

int inputComands(sHeader *stateList) {
    char cmd[MAXLENGTH100];
    char cmdAux[MAXLENGTH100];

    printf("Introduce el comando: \n");
    scanf("%[^\n]", cmd);
    dump_line(stdin);

    int i = 0, j = 0, e = 0, a = 0, intAux, fail = 0;
    int moreCmds = 0;

    while (i < strlen(cmd)) {
        if (cmd[i] != ' ' && cmd[i] != '\0') {
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
                        a = i;
                        e = 0;
                        if (strcmp(cmdAux, "-d") == 0) {
                            memset(cmdAux, '\0', strlen(cmdAux));
                            while (e < strlen(cmd)) {
                                if (cmd[a] != '\0' && cmd[a] != ' ') {
                                    cmdAux[e] = cmd[a];
                                    e++;
                                } else {
                                    e = strlen(cmd);
                                }
                                a++;
                            }
                            intAux = atoi(cmdAux);

                            if (intAux != 0) {
                                stateList->diskNum = intAux;
                            } else {
                                printf(COLOR_RED "Comando no valido, el numero de discos no se puede ser -d %s \n" COLOR_RESET, cmdAux);
                                fail = 1;
                            }
                            i = a - 1;
                            memset(cmdAux, '\0', strlen(cmdAux));
                            j = -1;
                        } else if (strcmp(cmdAux, "-f") == 0) {
                            memset(cmdAux, '\0', strlen(cmdAux));
                            while (e < strlen(cmd)) {
                                if (cmd[a] != '\0' && cmd[a] != ' ') {
                                    cmdAux[e] = cmd[a];
                                    e++;
                                } else {
                                    e = strlen(cmd);
                                }
                                a++;
                            }

                            if (strcmp(cmdAux, "-d") == 0 || strcmp(cmdAux, "-o") == 0 || strcmp(cmdAux, "-f") == 0) {
                                printf(COLOR_RED "Comando no valido, no se puede llamar al fichero %s \n" COLOR_RESET, cmdAux);
                                fail = 1;
                            } else {
                                strcpy(stateList->ouputFilename, cmdAux);
                            }
                            i = a - 1;
                            memset(cmdAux, '\0', strlen(cmdAux));
                            j = -1;
                        } else if (strcmp(cmdAux, "-o") == 0) {
                            memset(cmdAux, '\0', strlen(cmdAux));
                            while (e < strlen(cmd)) {
                                if (cmd[a] != '\0' && cmd[a] != ' ') {
                                    cmdAux[e] = cmd[a];
                                    e++;
                                } else {
                                    e = strlen(cmd);
                                }
                                a++;
                            }

                            intAux = 0;
                            if (strcmp(cmdAux, "ap") != 0) {
                                intAux++;
                            }
                            if (strcmp(cmdAux, "w") != 0){
                                intAux++;
                            }
                            if(intAux == 2){
                                printf(COLOR_RED "Comando no valido, no se puede introducir -o %s \n" COLOR_RESET, cmdAux);
                                fail = 1;
                            }else{
                                strcpy(stateList->fileOperations, cmdAux);
                            }

                            i = a - 1;
                            memset(cmdAux, '\0', strlen(cmdAux));
                            j = -1;
                        } else {
                            printf(COLOR_RED "Comando no valido, no se puede introducir %s \n" COLOR_RESET, cmdAux);
                            fail = 1;
                            i = strlen(cmd);
                        }
                    }
                    i++;
                    j++;
                }

            } else {
                printf(COLOR_RED "Comando no valido, no se puede introducir %s \n" COLOR_RESET, cmdAux);
                fail = 1;
                i = strlen(cmd);
            }

        }
        i++;
    }

    if (moreCmds == 0) {
        if (strcmp(cmd, "hanoiplus") == 0) {
            printf(COLOR_GREEN "Comando valido, introducion correcta! \n" COLOR_RESET);      
        } else {
            printf(COLOR_RED "Comando no valido, no se puede introducir %s \n" COLOR_RESET, cmd);
            fail = 1;
        }
    }
    
    if(fail == 0){
         strcpy(stateList->cmdLine, cmd);
    }

    return fail;
}

void dump_line(FILE * fp){
  int ch;

  while( (ch = fgetc(fp)) != EOF && ch != '\n' )
    /* null body */;
}
