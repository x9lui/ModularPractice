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
    char c;
    printf("Que acción desea realizar:\n Modificar la materia: M\n Mostrar el listado de materias: m\n Volver atrás: 0\n");
    do{
        getc(c);
        switch(c){
            case 'M': ModdifMat();
                break;
            case 'm': MostrarMat();
                break;
            case '0':break;
            default:printf("Caracter introducido incorrecto, vuenla a intentarlo\n Recuerde, si quiere volver pulse el caracter 0\n");
                break;
        }
    }while(c!=0)
}

