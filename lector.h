#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LECTOR
#define LECTOR
//Lee un elemento del archivo y lo guarda en la cadena de caracteres
//La cadena de caracteres tiene que tener espacio suficiente para alojar el elemento del archivo + 1 (para el caracter nulo '\0')
void LecturaElemento(FILE *f,char *string, int longitudMaxima){
    char ch = fgetc(f);
    int i = 0;
    do{
        string[i] = ch;
        i++;
        ch=fgetc(f);
    }while(ch != '-' && ch != '\n' && ch != EOF && i != (longitudMaxima-1));
    string[i] = '\0';

    //Si la transmision de lectura a cadena termina al llegar al limite de capacidad de cadena, deja el cursor preparado para la siguiente lectura
    if (ch != '-' && ch != '\n' && ch !=EOF){
        do{
            ch=fgetc(f);
        }while(ch != '-' && ch != '\n' && ch != EOF);
    }
}

int CaracterANumero(int ch){
    switch(ch){
        case '0':
            return 0;
        break;
        case '1':
            return 1;
        break;
        case '2':
            return 2;
        break;
        case '3':
            return 3;
        break;
        case '4':
            return 4;
        break;
        case '5':
            return 5;
        break;
        case '6':
            return 6;
        break;
        case '7':
            return 7;
        break;
        case '8':
            return 8;
        break;
        case '9':
            return 9;
        break;
        default:
            return 10; //Significa que el caracter no es numérico
        break;
        }
}

void LecturaElementoNumerico(FILE *f,int *numero){
    char ch = fgetc(f);
    int sumatorio = 0;
    do{
        sumatorio *= 10;
        sumatorio += CaracterANumero(ch);
        ch=fgetc(f);
    }while(ch != '-' && ch != '\n' && ch != EOF);
    *numero = sumatorio;
}


//Saltar un elemento del archivo
void LecturaSalto(FILE *f){
    char ch;
    do{
        ch = fgetc(f);
    }while(ch != '-' && ch != '\n' && ch != EOF);
}

//El numero será 1 si el usuario es administrador y si no 0
void LecturaAdministrador(FILE *f,int *numero){
    char ch = fgetc(f);
    char string[14];
    int i = 0;
    do{
        string[i] = ch;
        i++;
        ch=fgetc(f);
    }while(ch != '-' && ch != '\n' && ch != EOF);
    string[i] = '\0';
    if(strcmp(string,"administrador") == 0){
        *numero = 1;
    }else{
        *numero = 0;
    }
}

typedef struct{
    int dia;
    int mes;
    int año;
} Fecha;

void LecturaFecha(FILE *f,Fecha *fecha){

    int numero;
    char ch = getc(f);
    numero = 10*CaracterANumero(ch);
    ch = fgetc(f);
    numero += CaracterANumero(ch);
    fecha->dia = numero;
    fseek(f,1L,SEEK_CUR); //Saltar "/"

    numero = 0;
    ch = fgetc(f);
    numero = 10*CaracterANumero(ch);
    ch = fgetc(f);
    numero += CaracterANumero(ch);
    fecha->mes = numero;
    fseek(f,1L,SEEK_CUR); //Saltar "/"

    numero = 0;
    for (int i=0;i<4;i++){
    ch = fgetc(f);
    numero = numero*10 + CaracterANumero(ch);
    }
    fecha->año = numero;
    fseek(f,1L,SEEK_CUR); //Saltar "-", dado que al final de cada lectura de un elemento siempre debemos dejar el cursor preparado para leer el elemento después de "-"
}

typedef struct{
    int id;
    char nombre[21];
    int perfil;
    char nombreUsuario[6];
    char contraseña[9];
} Usuario;

//Carga los usuarios en un vector de estructuras y devuelve el numero de usuarios
//El numero de usuarios nos será de utilidad cuando tengamos que hacer bucles que recorran todo el vector
int CargarUsuarios(Usuario **ptr){
    Usuario *usuario;
    usuario = malloc(sizeof(Usuario));

    FILE *f;
    f = fopen("Usuarios.txt","r");
    char ch;
    int numeroUsuarios = 0;
    while((ch = fgetc(f)) != EOF){
        fseek(f,-1L,SEEK_CUR);
        usuario = realloc(usuario,(numeroUsuarios+1) * sizeof(Usuario));
        LecturaElementoNumerico(f,&usuario[numeroUsuarios].id);
        LecturaElemento(f,usuario[numeroUsuarios].nombre, 21);
        LecturaAdministrador(f,&usuario[numeroUsuarios].perfil);
        LecturaElemento(f,usuario[numeroUsuarios].nombreUsuario, 6);
        LecturaElemento(f,usuario[numeroUsuarios].contraseña, 9);
        numeroUsuarios++;
    }
    fclose(f);
    *ptr = usuario;
    return numeroUsuarios;
}



typedef struct{
    int id;
    char nombre[21];
    char direccion[31];
    char localidad[31];
    char curso[31];
    char grupo[11];
} Alumno;

//Carga los alumnos en un vector de estructuras y devuelve el numero de usuarios
//El numero de alumnos nos será de utilidad cuando tengamos que hacer bucles que recorran todo el vector
int CargarAlumnos(Alumno **ptr){
    Alumno *alumno;
    alumno = malloc(sizeof(Alumno));

    FILE *f;
    f = fopen("Alumnos.txt","r");
    char ch;
    int numeroAlumnos = 0;
    while((ch = fgetc(f)) != EOF){
        fseek(f,-1L,SEEK_CUR);
        alumno = realloc(alumno,(numeroAlumnos+1) * sizeof(Alumno));
        LecturaElementoNumerico(f,&alumno[numeroAlumnos].id);
        LecturaElemento(f,alumno[numeroAlumnos].nombre, 21);
        LecturaElemento(f,alumno[numeroAlumnos].direccion, 31);
        LecturaElemento(f,alumno[numeroAlumnos].localidad, 31);
        LecturaElemento(f,alumno[numeroAlumnos].curso, 31);
        LecturaElemento(f,alumno[numeroAlumnos].grupo, 11);
        numeroAlumnos++;
    }
    fclose(f);
    *ptr = alumno;
    return numeroAlumnos;
}



typedef struct{
    int id;
    char nombre[51];
    char abreviatura[4];
} Materia;

//Carga las materias en un vector de estructuras y devuelve el numero de materias
//El numero de materias nos será de utilidad cuando tengamos que hacer bucles que recorran todo el vector
int CargarMaterias(Materia **ptr){
    Materia *materia;
    materia = malloc(sizeof(Materia));

    FILE *f;
    f = fopen("Materias.txt","r");
    char ch;
    int numeroMaterias = 0;
    while((ch = fgetc(f)) != EOF){
        fseek(f,-1L,SEEK_CUR);
        materia = realloc(materia,(numeroMaterias+1) * sizeof(Materia));
        LecturaElementoNumerico(f,&materia[numeroMaterias].id);
        LecturaElemento(f,materia[numeroMaterias].nombre, 51);
        LecturaElemento(f,materia[numeroMaterias].abreviatura, 4);
        numeroMaterias++;
    }
    fclose(f);
    *ptr = materia;
    return numeroMaterias;
}



typedef struct{
    int idMateria;
    int idAlum;
} Matricula;

//Carga las matriculas en un vector de estructuras y devuelve el numero de matriculas
//El numero de matriculas nos será de utilidad cuando tengamos que hacer bucles que recorran todo el vector
int CargarMatriculas(Matricula **ptr){
    Matricula *matricula;
    matricula = malloc(sizeof(Matricula));

    FILE *f;
    f = fopen("Matrículas.txt","r");
    char ch;
    int numeroMatriculas = 0;
    while((ch = fgetc(f)) != EOF){
        fseek(f,-1L,SEEK_CUR);
        matricula = realloc(matricula,(numeroMatriculas+1) * sizeof(Matricula));
        LecturaElementoNumerico(f,&matricula[numeroMatriculas].idMateria);
        LecturaElementoNumerico(f,&matricula[numeroMatriculas].idAlum);
        numeroMatriculas++;
    }
    fclose(f);
    *ptr = matricula;
    return numeroMatriculas;
}



typedef struct{
    Fecha fecha;
    char descripcion[31];
    int idMateria;
    int idAlumno;
    int calificacion;
} Calificacion;

//Carga las calificaciones en un vector de estructuras y devuelve el numero de calificaciones
//El numero de calificaciones nos será de utilidad cuando tengamos que hacer bucles que recorran todo el vector
int CargarCalificaciones(Calificacion **ptr){
    Calificacion *calificacion;
    calificacion = malloc(sizeof(Calificacion));

    FILE *f;
    f = fopen("Calificaciones.txt","r");
    char ch;
    int numeroCalificaciones = 0;
    while((ch = fgetc(f)) != EOF){
        fseek(f,-1L,SEEK_CUR);
        calificacion = realloc(calificacion,(numeroCalificaciones+1) * sizeof(Calificacion));
        LecturaFecha(f,&calificacion[numeroCalificaciones].fecha);
        LecturaElemento(f,calificacion[numeroCalificaciones].descripcion, 31);
        LecturaElementoNumerico(f,&calificacion[numeroCalificaciones].idMateria);
        LecturaElementoNumerico(f,&calificacion[numeroCalificaciones].idAlumno);
        LecturaElementoNumerico(f,&calificacion[numeroCalificaciones].calificacion);
        numeroCalificaciones++;
    }
    fclose(f);
    *ptr = calificacion;
    return numeroCalificaciones;
}



typedef struct{
    int idProf;
    int dia;
    int hora;
    int idMateria;
    char grupo[11];
} Horario;

//Carga los horarios en un vector de estructuras y devuelve el numero de horarios
//El numero de horarios nos será de utilidad cuando tengamos que hacer bucles que recorran todo el vector
int CargarHorarios(Horario **ptr){
    Horario *horario;
    horario = malloc(sizeof(Horario));

    FILE *f;
    f = fopen("Horarios.txt","r");
    char ch;
    int numeroHorarios = 0;
    while((ch = fgetc(f)) != EOF){
        fseek(f,-1L,SEEK_CUR);
        horario = realloc(horario,(numeroHorarios+1) * sizeof(Horario));
        LecturaElementoNumerico(f,&horario[numeroHorarios].idProf);
        LecturaElementoNumerico(f,&horario[numeroHorarios].dia);
        LecturaElementoNumerico(f,&horario[numeroHorarios].hora);
        LecturaElementoNumerico(f,&horario[numeroHorarios].idMateria);
        LecturaElemento(f,horario[numeroHorarios].grupo, 11);
        numeroHorarios++;
    }
    fclose(f);
    *ptr = horario;
    return numeroHorarios;
}

#endif