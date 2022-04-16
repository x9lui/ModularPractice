#include <stdio.h>
#include <stdlib.h>
#include "lector.h"

/*typedef struct{
    int id;
    char nombre[21];
    char direccion[31];
    char localidad[31];
    char curso[31];
    char grupo[11];
} Alumno;*/

void ModdifAlum(){
    Alumno a;
    int id, n = CargarAlumnos(&a);
    char c;

    printf("Escriba la id del alumno que desea modificar\n");
    scanf("%i",&id);

    do{
        printf("¿Que dato desea modificar?\nIntoduzca el carcarter N si quiere modificicar el nombre\nIntoduzca el carcarter D si quiere modificicar la dirección\nIntoduzca el carcarter L si quiere modificicar la localidad\nIntoduzca el carcarter C si quiere modificicar el curso\nIntoduzca el carcarter G si quiere modificicar el grupo\nIntroduzca 0 si desea terminar de modificar\n\n");
        scanf("%c",&c);

        switch (c){
        case 'N':
            ModNom(&a,id);//Crear función
            break;

        case 'D':
            ModDir(&a,id);//Crear función
            break;

        case 'L':
            ModLoc(&a,id);//Crear función
            break;

        case 'C':
            ModCur(&a,id);//Crear función
            break;

        case 'G':
            ModGru(&a,id);//Crear función
            break;

        case '0': break;

        default:
            printf("El caracter introducido no es correcto, por favor intentelo de nuevo\n");
            break;
        }
    }while(c != '0');
    //Guardar cambios
    printf("Se han guardado los cambios correctamente\n");
}

void ModNom(Alumno *st,int idA){
    char auxN[21];

    printf("Introduzca el nuevo nombre del alumno\n;")
    fgets(auxN,21,stdin);

    strcpy(st[idA].nombre,auxN);
    if (strcmp(st[idA].nombre,auxN)== 0)
        printf("Se ha modificado el nombre correctarmente\n");
}

void ModDir

