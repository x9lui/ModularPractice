#include <stdio.h>
#include <string.h>
#include "lector.h"
#include "horarios.c"

void ListarMateriasDiariasProfesor(int, int);

int VerificacionImpartirMateria(int,char[4]);

int VerificacionGrupoProfesor(int, char[11]);

int main(){ 
    
    int idUsuario, perfil, dia;
    //Login(&idUsuario, &perfil);
    dia = 1;
    idUsuario =3;
    perfil = 1;
    if(perfil == 1){
        int salir = 0;
        do{
            int op;
            do{
                printf("1.Usuarios\n");
                printf("2.Alumnos\n");
                printf("3.Materias\n");
                printf("4.Horarios\n");
                printf("0.Salir\n");
                printf("Introduzca la opción:\n");
                scanf("%i",&op);
                if(op>4 && op<0){
                    printf("Número no válido\n");
                }
            }while(op>4 && op<0);
            switch(op){
                case 1:
                break;
                case 2:
                break;
                case 3:
                break;
                case 4:
                    MenuHorarios();
                break;
                case 0:
                    salir = 1;
                break;
            }

        }while(salir == 0);
    }else{
        int salir = 0;
        do{
            int dia;
            do{
                printf("Introduzca el día en el que está trabajando (0 para volver atrás):\n");
                fflush(stdin);
                scanf("%i",&dia);
                if((dia>5 || dia<1) && dia!=0){
                    printf("Día no válido, introduzca un día entre 1 y 5\n");
                }
            }while((dia>5 || dia<1) && dia !=0);
            
            if(dia == 0){
                salir = 1;
            }

            if(salir == 0){
                ListarMateriasDiariasProfesor(idUsuario, dia);
                int op;
                do{
                    int ver = 0;
                    char grupo[11];
                    ver = 0;
                    do{
                        printf("Introduzca el grupo con el que desea trabajar:\n");
                        fflush(stdin);
                        fgets(grupo,10,stdin);
                        for(int i = 0; i<10;i++){
                            if(grupo[i] == '\n'){
                                grupo[i] = '\0';
                            }
                        }
                        ver = VerificacionGrupoProfesor(idUsuario,grupo);
                    }while(ver == 0);
                    printf("Verificado\n");

                    char abr[4];
                    do{
                        printf("Introduzca la abreviatura de la materia con la que desea trabajar en el grupo %s:\n",grupo);
                        fflush(stdin);
                        scanf("%s",abr);
                        ver = VerificacionImpartirMateria(idUsuario,abr);
                    }while(ver == 0);
                    printf("Verificado\n");
                    
                    printf("Introduzca una opción\n");
                    printf("1.Lista de alumnos\n");
                    printf("2.Cambiar de grupo\n");
                    printf("3.Salir\n");
                    scanf("%i",&op);

                    if(op == 1){
                        MenuAlumnos(idUsuario,grupo,abr);
                    }
                }while(op !=3);
            }
        }while(salir == 0);
    }

}



void ListarMateriasDiariasProfesor(int idProf, int dia){
    Horario *horarios;
    int nHorarios = CargarHorarios(&horarios);
    Materia *materias;
    int nMaterias = CargarMaterias(&materias);


    for(int i = 0; i<nHorarios; i++){
        if(horarios[i].idProf == idProf && horarios[i].dia == dia){
            printf("GRUPO %s ",horarios[i].grupo);
            int enc = 0;
            for(int o = 0; o<nMaterias; o++){
                if(horarios[i].idMateria == materias[o].id){
                    printf("MATERIA %s\n", materias[o].abreviatura);
                    enc = 1;
                }
            }
            if(enc == 0){
                printf("*MATERIA NO REG ID: %i*\n",horarios[i].idMateria);
            }
        }
    }

    free(horarios);
    free(materias);
}

int VerificacionImpartirMateria(int idProf, char abr[4]){
    
    int imp = 0; //Si es 0 significa que el profesor ha introducido la abreviatura de una asignatura que no imparte 
    int enc = 0;
    Materia *materias;
    int nMaterias = CargarMaterias(&materias); 
    int idMateria;
    for(int i = 0; i<nMaterias; i++){
        if(strcmp(abr,materias[i].abreviatura) == 0){
            idMateria = materias[i].id;
            enc = 1;
        }
    }

    if(enc == 0){
        printf("La materia no ha sido encontrada\n");
        return 0;
    }


    Horario *horarios;
    int nHorarios = CargarHorarios(&horarios);
    for(int i = 0;i<nHorarios;i++){
        if(horarios[i].idProf == idProf && horarios[i].idMateria == idMateria){
            imp = 1;
        }
    }

    if(imp == 1){
        return 1;
    }else{
        printf("Usted no tiene permisos sobre la materia seleccionada\n");
        return 0;
    }


    free(horarios);
    free(materias);
}

int VerificacionGrupoProfesor(int idProf, char grupo[11]){
    
    int imp = 0; //Si es 0 significa que el profesor ha introducido la abreviatura de una asignatura que no imparte 
    int enc = 0;

    Horario *horarios;
    int nHorarios = CargarHorarios(&horarios);
    for(int i = 0;i<nHorarios;i++){
        if( strcmp(horarios[i].grupo,grupo) == 0){
            enc = 1;
            if(horarios[i].idProf == idProf){
                imp=1;
            }
        }

    }
    
    if(enc == 0){
        printf("El grupo seleccionado no ha sido encontrado\n");
        return 0;
    }

    if(imp == 1){
        return 1;
    }else{
        printf("Usted no imparte clase al grupo seleccionado\n");
        return 0;
    }


    free(horarios);
}