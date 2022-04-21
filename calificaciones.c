#include <stdio.h>
#include <string.h>
#include "lector.h"
#include "escritor.h"

void ListarCalificacionesAlumno(int idAlum, int idMat){
    Calificacion *calificaciones;
    int nCalificaciones = CargarCalificaciones(&calificaciones);

    int enc = 0;
    for(int i = 0;i<nCalificaciones;i++){
        if(calificaciones[i].idMateria == idMat && calificaciones[i].idAlumno == idAlum){
            printf("%i/%i/%i %s %i\n",calificaciones[i].fecha.dia, calificaciones[i].fecha.mes, calificaciones[i].fecha.año, calificaciones[i].descripcion, calificaciones[i].calificacion);
            enc = 1;
        }
    }
    if(enc == 0){
        printf("No se han encontrado calificaciones");
    }
}