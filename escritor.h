#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lector.h"

#ifndef ESCRITOR
#define ESCRITOR


void EscribirNumero(FILE *f,int n, int nCifras){
    nCifras--;
    while(n<pow(10,nCifras)){
        fprintf(f,"0");
        nCifras--;
    }
    fprintf(f,"%i",n);
}

void EscribirFecha(FILE *f, Fecha fecha){
    if(fecha.dia < 10){
        fprintf(f,"0%i/",fecha.dia);
    }else{
        fprintf(f,"%i/",fecha.dia);
    }
    if(fecha.mes<10){
        fprintf(f,"0%i/",fecha.mes);
    }else{
        fprintf(f,"%i/",fecha.mes);
    }
    fprintf(f,"%i",fecha.año);
}

//Escribe el vector de estructuras Usuario en su fichero correspondiente, importante prestar especial atención a nUsuarios ya que puede variar si se eliminan o se añaden nuevos usuarios
void EscribirUsuarios(Usuario *usuarios,int nUsuarios){
    FILE *f;
    f = fopen("Usuarios.txt","w");

    for(int i = 0;i<nUsuarios;i++){
        EscribirNumero(f,usuarios[i].id,3);
        fprintf(f,"-%s-",usuarios[i].nombre);
        if(usuarios[i].perfil == 1){
            fprintf(f,"administrador-");
        }else{
            fprintf(f,"profesor-");
        }
        fprintf(f,"%s-%s",usuarios[i].nombreUsuario,usuarios[i].contraseña);
        if(i != nUsuarios-1){
            fprintf(f,"\n");
        }
    }
    fclose(f);
}

//Escribe el vector de estructuras Alumno en su fichero correspondiente, importante prestar especial atención a nAlumnos ya que puede variar si se eliminan o se añaden nuevos alumnos
void EscribirAlumnos(Alumno *alumnos,int nAlumnos){
    FILE *f;
    f = fopen("Alumnos.txt","w");

    for(int i = 0; i<nAlumnos;i++){
        EscribirNumero(f,alumnos[i].id,6);
        fprintf(f,"-%s-%s-%s-%s-%s",alumnos[i].nombre, alumnos[i].direccion, alumnos[i].localidad, alumnos[i].curso, alumnos[i].grupo);
        if(i != nAlumnos-1){
            fprintf(f,"\n");
        }
    }
    fclose(f);
}

//Escribe el vector de estructuras Materia en su fichero correspondiente, importante prestar especial atención a nMaterias ya que puede variar si se eliminan o se añaden nuevas materias
void EscribirMaterias(Materia *materias, int nMaterias){
    FILE *f;
    f = fopen("Materias.txt","w");

    for(int i = 0; i<nMaterias;i++){
        EscribirNumero(f,materias[i].id,4);
        fprintf(f,"-%s-%s", materias[i].nombre, materias[i].abreviatura);
        if(i != nMaterias-1){
            fprintf(f,"\n");
        }
    }
    fclose(f);
}

//Escribe el vector de estructuras Matricula en su fichero correspondiente, importante prestar especial atención a nMatriculas ya que puede variar si se eliminan o se añaden nuevas matriculas
void EscribirMatriculas(Matricula *matriculas, int nMatriculas){
    FILE *f;
    f = fopen("Matriculas.txt","w");

    for(int i = 0; i<nMatriculas; i++){
        EscribirNumero(f,matriculas[i].idMateria,4);
        fprintf(f,"-");
        EscribirNumero(f,matriculas[i].idAlum,6);
        if(i != nMatriculas-1){
            fprintf(f,"\n");
        }
    }
}

//Escribe el vector de estructuras Calificacion en su fichero correspondiente, importante prestar especial atención a nCalificaciones ya que puede variar si se eliminan o se añaden nuevas calificaciones
void EscribirCalificaciones(Calificacion *calificaciones, int nCalificaciones){
    FILE *f;
    f = fopen("Calificaciones.txt","w");

    for(int i = 0; i<nCalificaciones; i++){
        EscribirFecha(f,calificaciones[i].fecha);
        fprintf(f,"-%s-",calificaciones[i].descripcion);
        EscribirNumero(f,calificaciones[i].idMateria,4);
        fprintf(f,"-");
        EscribirNumero(f,calificaciones[i].idAlumno,6);
        fprintf(f,"-%i",calificaciones[i].calificacion);
        if(i != nCalificaciones){
            fprintf(f,"\n");
        }
    }
}

//Escribe el vector de estructuras Horario en su fichero correspondiente, importante prestar especial atención a nHorarios ya que puede variar si se eliminan o se añaden nuevos horarios
void EscribirHorarios(Horario *horarios, int nHorarios){
    FILE *f;
    f = fopen("Horarios.txt","w");

    for(int i = 0; i<nHorarios;i++){
        EscribirNumero(f,horarios[i].idProf,3);
        fprintf(f,"-%i-%i-", horarios[i].dia, horarios[i].hora);
        EscribirNumero(f,horarios[i].idMateria,4);
        fprintf(f,"-%s",horarios[i].grupo);
        if(i != nHorarios-1){
            fprintf(f,"\n");
        }
    }
    fclose(f);
}


#endif