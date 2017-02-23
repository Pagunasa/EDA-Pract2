#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "filesOperations.h"

void showCommands() {
    printf( "Los commandos para operar son: \n" );
    printf(COLOR_MAGENTA "hanoiplus" COLOR_RESET);
    printf(COLOR_CYAN " -d <numero de discos>" COLOR_RESET);
    printf(COLOR_YELLOW " -f <nombre del fichero>" COLOR_RESET);
    printf(COLOR_GREEN " -o <codigo de operación> \n\n" COLOR_RESET);

    printf("Los codigos de operacion son: \n");
    printf(COLOR_GREEN "ap -> Guardar la informacion en un fichero existente\n");
    printf( "w -> Crear un nuevo fichero o aplastar uno existente\n\n"COLOR_RESET);
}

void inputComands(){
    char cmd[MAXLENGTH500];
    
    printf( "Introduce el comando: \n" );
    scanf("%s", cmd);
}