#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lector.h"
#include "escritor.h"

/*typedef struct{
    int id;
    char nombre[51];
    char abreviatura[4];
} Materia;*/

void ModdifMat(){
    Materia m;
    int id,i,numM = CargarMaterias(&m);
    char auxN[51], auxA[4]; //Nombre y abreviatura de la nueva materia

    printf("Introduzca la id de la asignatura a modificar\n");
    scanf("%i",&id);

    printf("Introduzca el nuevo nombre de la asignatura\n");
    fgets(auxN, 51, stdin);
    m[id].nombre = auxN;

    printf("Introduzca la nueva abreviatura de la asignatura\n");
    fgets(auxA, 4, stdin);
    m[id].abreviatura = auxA;

    printf("Se han modificado los datos de la asignatura con id %i\n",id);

    //Función borrar y añadir una nueva asignatura ?

    EscribirMaterias(m,numM);
}

void MostrarMat(){
    Materia m;
    int i, numM = CargarMaterias(&m);

    for(i=0;i<=numM;i++)
        printf("%i - %s - %s\n",m[i].id,m[i].nombre,m[i].abreviatura);
}

void SelecMat(){
    int s;
    do{
    printf("Que acción desea realizar:\n1. Modificar la materia\n2. Mostrar el listado de materias\n3. Volver atrás\n");
        scanf("%i",&s));
        switch(s){
            case 1: ModdifMat();
                break;
            case 2: MostrarMat();
                break;
            case 3:break;
            default:printf("Caracter introducido incorrecto, vuenla a intentarlo\n Recuerde, si quiere volver pulse 3\n");
                break;
        }
    }while(s!=3)
}

