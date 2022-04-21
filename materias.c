#include <stdio.h>
#include <string.h>
#include "lector.h"
#include "escritor.h"

void MenuMaterias(int idUsuario,int dia){
    ListarMateriasDiariasProfesor(idUsuario, dia);
    char abr[4];
    int ver = 0;
    do{
        printf("Introduzca la abreviatura de la materia con la que desea trabajar:\n");
        fflush(stdin);
        scanf("%s",abr);
        ver = VerificacionImpartirMateria(idUsuario,abr);
    }while(ver == 0);
    printf("Verificado\n");
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