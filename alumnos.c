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

void ModDir(Alumno *st,int idA){
    char auxD[31];

    printf("Introduzca la nueva dirección del alumno\n;")
    fgets(auxD,31,stdin);

    strcpy(st[idA].direccion,auxD);
    if (strcmp(st[idA].direccion,auxD)== 0)
        printf("Se ha modificado la dirección correctarmente\n");
}

void ModLoc(Alumno +st, int idA){
    char auxL[31];

    printf("Introduzca la nueva localidad del alumno\n;")
    fgets(auxL,31,stdin);   

    strcpy(st[idA].localidad,auxL);
    if (strcmp(st[idA].localidad,auxL)== 0)
        printf("Se ha modificado la localidad correctarmente\n");  
}

void ModCur(Alumno *st,int idA){
    char auxC[31];

    printf("Introduzca el nuevo curso del alumno\n;")
    fgets(auxC,31,stdin);   

    strcpy(st[idA].curso,auxC);
    if (strcmp(st[idA].curso,auxC)== 0)
        printf("Se ha modificado el curso correctarmente\n");  
}

void ModGru(Alumno *st,int idA){ //Añadir un bucle si no se cumple el if (usar variable i++ dentro del if y terminar bucle cuando i<0)
    char auxG[11];

    printf("Introduzca el nuevo curso del alumno\n;")
    fgets(auxG,31,stdin);   

    strcpy(st[idA].grupo,auxG);
    if (strcmp(st[idA].grupo,auxG)== 0)
        printf("Se ha modificado el grupo correctarmente\n");
}

void GuardarCambios(Alumno st){ //Hacer función, explicación Luis

}

void MostarAlumnos(){
    Alumno a;
    int i, n = CargarAlumnos(&a);

        for(i=0;i<=n;i++)
        printf("%i - %s - %s - %s - %s - %s\n",a[i].id,a[i].nombre,a[i].direccion,a[i].localidad,a[i].curso,a[i].grupo);
}

