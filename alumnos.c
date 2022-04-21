#include <stdio.h>
#include <string.h>
#include "lector.h"
#include "calificaciones.c"

void FichaAlumno(int idAlum){
    Alumno *alumnos;
    int nAlumnos = CargarAlumnos(&alumnos);
    int pos; //posicion en el vector que ocupa el alumno
    for(int i=0;i<nAlumnos;i++){
        if(alumnos[i].id == idAlum){
            printf("%i %s %s %s %s %s\n",alumnos[i].id, alumnos[i].nombre, alumnos[i].direccion, alumnos[i].localidad, alumnos[i].curso, alumnos[i].grupo);
            pos = i;
        }
    }

    int op;
    do{
        do{
            printf("1.Modificar datos del alumno\n");
            printf("2.salir\n");
            printf("Teclee una opción:\n");
            scanf("%i",&op);
            if(op != 1 && op != 2){
                printf("Número no válido\n");
            }
        }while(op != 1 && op != 2);

        if(op==1){
            int id;
            char nombre[21];
            char direccion[31];
            char localidad[31];
            char curso[31];
            char grupo[11];


            printf("Introduce el nombre:\n");
            fflush(stdin);
            fgets(nombre,20,stdin);
            for(int i = 0; i<20;i++){
                if(nombre[i] == '\n'){
                    nombre[i] = '\0';
                }
            }
            printf("Introduce la dirección:\n");
            fflush(stdin);
            fgets(direccion,30,stdin);
            for(int i = 0; i<30;i++){
                if(direccion[i] == '\n'){
                    direccion[i] = '\0';
                }
            }
            printf("Introduce la localidad:\n");
            fflush(stdin);
            fgets(localidad,30,stdin);
            for(int i = 0; i<30;i++){
                if(localidad[i] == '\n'){
                    localidad[i] = '\0';
                }
            }
            printf("Introduce el curso:\n");
            fflush(stdin);
            fgets(curso,30,stdin);
            for(int i = 0; i<30;i++){
                if(curso[i] == '\n'){
                    curso[i] = '\0';
                }
            }
            printf("Introduce el grupo:\n");
            fflush(stdin);
            fgets(grupo,10,stdin);
            for(int i = 0; i<10;i++){
                if(grupo[i] == '\n'){
                    grupo[i] = '\0';
                }
            }
            strcpy(alumnos[pos].nombre,nombre);
            strcpy(alumnos[pos].direccion,direccion);
            strcpy(alumnos[pos].localidad,localidad);
            strcpy(alumnos[pos].curso,curso);
            strcpy(alumnos[pos].grupo,grupo);
            EscribirAlumnos(alumnos,nAlumnos);

        }

    }while(op!=2);
    free(alumnos);
}

void MenuAlumnos(int idProf,char grupo[11],char abr[4]){
    //De materias con mat.abr obtenemos el mat.id, de matriculas con mat.id obtnemos el alumno.id, y de alumnos con alumnos.id obtenemos alumnos.nombre
    int idMat;
    //Obtenemos idMat con matAbr
    Materia *materias;
    int nMaterias = CargarMaterias(&materias);
    for(int i = 0; i<nMaterias;i++){
        if(strcmp(abr,materias[i].abreviatura)){
            idMat = materias[i].id;
        }
    }
    free(materias);

    int op;
    do{
        int idAlum;
        int imp = 0; // si imp = 0 no imparte clases a dicho alumno
        do{
            //Imprimimos los alumnos que tiene el profesor en el grupo y materia seleccionada
            Matricula *matriculas;
            int nMatriculas = CargarMatriculas(&matriculas);

            Alumno *alumnos;
            int nAlumnos = CargarAlumnos(&alumnos);
            printf("Lista de alumnos:\n");
            for(int i=0; i<nMatriculas;i++){
                if(matriculas[i].idMateria == idMat){
                    for(int o=0;o<nAlumnos;o++){
                        if(matriculas[i].idAlum == alumnos[o].id && strcmp(alumnos[o].grupo,grupo)==0){
                            printf("\t%i %s\n",alumnos[o].id, alumnos[o].nombre);
                        }
                    }
                }
            }
            free(matriculas); 

            printf("Introduzca el id del alumno:\n");
            scanf("%i",&idAlum);
            char grupoAlumno[11];
            for(int i = 0;i<nAlumnos;i++){
                if(idAlum == alumnos[i].id){
                    strcpy(grupoAlumno,alumnos[i].grupo);
                }
            }
            free(alumnos);
            //Verificar que el profesor imparte al grupo del alumno
            Horario *horarios;
            int nHorarios = CargarHorarios(&horarios);
            int enc = 0;
            for(int i = 0;i<nHorarios;i++){
                if(strcmp(grupoAlumno,horarios[i].grupo) == 0){
                    enc = 1;
                    if(idProf == horarios[i].idProf){
                        imp = 1;
                    }
                }
            }
            if(enc == 0){
                printf("No se ha encontrado dicho alumno\n");
            }else if(imp==0){
            printf("Usted no imparte clase a dicho alumno\n");
            }
            
        }while(imp == 0);

        do{
            printf("1.Ficha del alumno\n");
            printf("2.Calificaciones del alumno\n");
            printf("3.Volver\n");
            printf("Introduzca la opción\n");
            scanf("%i",&op);
            if(op!=1 && op!=2 && op!=3){
                printf("Número no válido\n");
            }
        }while(op!=1 && op!=2 && op!=3);

        switch(op){
            case 1:
                FichaAlumno(idAlum);
            break;
            case 2:
                ListarCalificacionesAlumno(idAlum,idMat);
                
            break;
            case 3:
            //Es la salida
            break;
        }
    }while(op!=3);
}