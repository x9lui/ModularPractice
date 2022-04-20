#include <stdio.h>
#include <string.h>
#include "lector.h"
#include "escritor.h"

void AnadirHora(int idProf){
    int dia,hora,h;
    int val; //valido
    int rep; //repetido
    int idMat;
    char grupo[11];
    Horario *horarios;
    int nHorarios = CargarHorarios(&horarios);

    do{
        do{
            val = 0;
            printf("Introduzca el día:\n");
            fflush(stdin);
            scanf("%i",&dia);

            if(dia>=1 && dia<=5){
                for(int i=0;i<nHorarios;i++){
                    h = 0;
                    if(horarios[i].idProf == idProf && horarios[i].dia == dia){
                        h++;
                    }
                }
                if(h == 6){
                    printf("Ese día tiene todas las horas ocupadas\n");
                }else{
                    val = 1;
                }
            }else{
                printf("Día incorrecto, introduzca un número entre 1 y 5\n");
            }
        }while(val == 0 || h==6);

        do{
            printf("Introduzca la hora:\n");
            fflush(stdin);
            scanf("%i",&hora);
            rep = 0;
            val = 1;
            if(hora>=1 && hora<=6){
                for(int i=0;i<nHorarios;i++){
                    if(horarios[i].dia == dia && horarios[i].hora == hora){
                        rep = 1;
                    }
                }
            }else{
                printf("Hora incorrecta, introduzca un número entre 1 y 6\n");
                val = 0;
            }
            if(rep == 1){
                printf("Ya hay una clase asignada el dia %i a %ia hora\n",dia,hora);
            }
        }while(val == 0);
    }while(rep == 1);

    do{
        printf("Introduce el id de la materia que desea impartir\n");
        fflush(stdin);
        scanf("%i",&idMat);
        if(idMat>9999){
            printf("El id de la materia ha de tener como máximo 4 cifras\n");
        }else if(idMat<0){
            printf("Los números negativos no son válidos\n");
        }
    }while(idMat>9999 || idMat<0);

    
    printf("Introduzca el grupo con el que se trabajará:\n");
    fflush(stdin);
    fgets(grupo,10,stdin);
    fflush(stdin);
    for(int i=0;i<10;i++){
        if(grupo[i] == '\n'){
            grupo[i] = '\0';
        }
    }

    FILE *f;
    f = fopen("Horarios.txt","r+");
    char ch;
    do{
        ch = fgetc(f);
    }while(ch != EOF);

    fprintf(f,"\n");
    EscribirNumero(f,idProf,3);
    fprintf(f,"-%i-%i-",dia,hora);
    EscribirNumero(f,idMat,4);
    fprintf(f,"-%s",grupo);

    free(horarios);
    fclose(f);
}

void EliminarHora(int idProf){
    int dia,hora;
    int enc = 0;
    int pos = -1;
    Horario *horarios;
    int nHorarios = CargarHorarios(&horarios);
    do{
        do{
            do{
                printf("Introduzca el dia que desea eliminar:\n");
                fflush(stdin);
                scanf("%i",&dia);
                if(dia>5 || dia<1){
                    printf("Día incorrecto, introduzca un número entre 1 y 5\n");
                }
            }while(dia>5 || dia<1);

            for(int i = 0;i<nHorarios;i++){
                if(horarios[i].dia == dia){
                    enc = 1;
                }
            }
        }while(enc == 0);


        do{
            printf("Introduzca la hora que desea eliminar:\n");
            fflush(stdin);
            scanf("%i",&hora);
            if(hora>6 || hora<1){
                printf("Hora incorrecta, introduzca un número entre 1 y 6\n");
            }
        }while(hora>6 || hora<1);

        pos = -1; // si pos se mantiene en -1 es que no se ha encontrado ninguna hora
        for(int i = 0; i<nHorarios;i++){
            if(horarios[i].dia == dia && horarios[i].hora == hora && horarios[i].idProf == idProf){
                pos = i;
            }
        }
        if(pos ==-1){
            printf("No se ha encontrado ninguna clase asignada el dia %i a %ia hora\n",dia,hora);
        }

    }while(pos ==-1);

    if(pos !=-1){
        if(pos != nHorarios-1){
            for(int i = pos;i<nHorarios-1;i++){
                horarios[i].idProf = horarios[i+1].idProf;
                horarios[i].dia = horarios[i+1].dia;
                horarios[i].hora = horarios[i+1].hora;
                horarios[i].idMateria = horarios[i+1].idMateria;
                strcpy(horarios[i].grupo,horarios[i+1].grupo);
                
                EscribirHorarios(horarios,nHorarios-1);
            }
        }else{
            EscribirHorarios(horarios,nHorarios-1);
        }
    }
    free(horarios);
}

void ModificarHora(int idProf){
    int dia,hora;
    int enc = 0;
    int pos = -1;
    Horario *horarios;
    int nHorarios = CargarHorarios(&horarios);
    do{
        do{
            do{
                printf("Introduzca el dia de la hora que desea modificar:\n");
                fflush(stdin);
                scanf("%i",&dia);
                if(dia>5 || dia<1){
                    printf("Día incorrecto, introduzca un número entre 1 y 5\n");
                }
            }while(dia>5 || dia<1);

            for(int i = 0;i<nHorarios;i++){
                if(horarios[i].dia == dia){
                    enc = 1;
                }
            }
        }while(enc == 0);


        do{
            printf("Introduzca la hora que desea modificar:\n");
            fflush(stdin);
            scanf("%i",&hora);
            if(hora>6 || hora<1){
                printf("Hora incorrecta, introduzca un número entre 1 y 6\n");
            }
        }while(hora>6 || hora<1);

        pos = -1; // si pos se mantiene en -1 es que no se ha encontrado ninguna hora
        for(int i = 0; i<nHorarios;i++){
            if(horarios[i].dia == dia && horarios[i].hora == hora && horarios[i].idProf == idProf){
                pos = i;
            }
        }
        if(pos ==-1){
            printf("No se ha encontrado ninguna clase asignada el dia %i a %ia hora\n",dia,hora);
        }

    }while(pos ==-1);

    int rep,val,h;
    int idMat;
    char grupo[11];
    //Tenemos la posicion del vector en el cual está ubicada la hora que queremos cambiar
    if(pos !=-1){
        do{
            do{
                val = 0;
                printf("Introduzca el día:\n");
                fflush(stdin);
                scanf("%i",&dia);

                if(dia>=1 && dia<=5){
                    for(int i=0;i<nHorarios;i++){
                        h = 0;
                        if(horarios[i].idProf == idProf && horarios[i].dia == dia && i!=pos){
                            h++;
                        }
                    }
                    if(h == 6){
                        printf("Ese día tiene todas las horas ocupadas\n");
                    }else{
                        val = 1;
                    }
                }else{
                    printf("Día incorrecto, introduzca un número entre 1 y 5\n");
                }
            }while(val == 0 || h==6);

            do{
                printf("Introduzca la hora:\n");
                fflush(stdin);
                scanf("%i",&hora);
                rep = 0;
                val = 1;
                if(hora>=1 && hora<=6){
                    for(int i=0;i<nHorarios;i++){
                        if(horarios[i].dia == dia && horarios[i].hora == hora && i != pos){
                            rep = 1;
                        }
                    }
                }else{
                    printf("Hora incorrecta, introduzca un número entre 1 y 6\n");
                    val = 0;
                }
                if(rep == 1){
                    printf("Ya hay una clase asignada el dia %i a %ia hora\n",dia,hora);
                }
            }while(val == 0);
        }while(rep == 1);

        do{
            printf("Introduce el id de la materia que desea impartir\n");
            fflush(stdin);
            scanf("%i",&idMat);
            if(idMat>9999){
                printf("El id de la materia ha de tener como máximo 4 cifras\n");
            }else if(idMat<0){
                printf("Los números negativos no son válidos\n");
            }
        }while(idMat>9999 || idMat<0);

        
        printf("Introduzca el grupo con el que se trabajará:\n");
        fflush(stdin);
        fgets(grupo,10,stdin);
        fflush(stdin);
        for(int i=0;i<10;i++){
            if(grupo[i] == '\n'){
                grupo[i] = '\0';
            }
        }

        horarios[pos].dia = dia;
        horarios[pos].hora = hora;
        horarios[pos].idMateria = idMat;
        strcpy(horarios[pos].grupo, grupo);
        EscribirHorarios(horarios,nHorarios);
        free(horarios);
    }


}

void MenuHorarios(){
    int idProf;
    char nombre[21];
    int enc;
    int salir = 0;
    Usuario *usuarios;
    int nUsuarios = CargarUsuarios(&usuarios);
    do{
        do{
            enc = 0; //Si se encuentra un profesor con mismo id que el buscado pasa a valer 1
            
            for(int i = 0; i<nUsuarios; i++){
                //if(usuarios[i].perfil == 0){ //Imprime todos los usuarios juntos sus ids salvo los que son administradores
                    printf("\t%i %s\n", usuarios[i].id, usuarios[i].nombre);
                //}
            }        


            printf("Introduzca el id del profesor el cual quiera editar su horario (0 para salir):\n");
            fflush(stdin);
            scanf("%i",&idProf);

            if(idProf == 0){
                salir = 1;
            }else if(idProf>999){
                printf("El id ha de tener como máximo 3 cifras\n");
            }else if(idProf<0){
                printf("Los números negativos no son válidos\n");
            }else{
                for(int i = 0; i <nUsuarios; i++){
                    if(usuarios[i].id == idProf){
                        enc = 1; //Se ha encontrado un id que coincide con el buscado
                        strcpy(nombre,usuarios[i].nombre);
                    }
                }
                if(enc == 0){
                    printf("No se ha encontrado ningún profesor con el id %i\n", idProf);
                }
            }
        }while((idProf>999 || enc == 0) && salir == 0);
        fflush(stdin);

        int salir2 = salir;
        while(salir2 == 0){
            int horEnc = 0; //Si el profesor imparte al menos una hora de clase cambia a 1
            printf("Estos son los horarios del profesor %s:\n", nombre);
            Horario *horarios;
            int nHorarios = CargarHorarios(&horarios);
            Materia *materias;
            int nMaterias = CargarMaterias(&materias);
            char nomMateria[51];
            int matEnc; //Si se encuentra una materia con id coincidente cambia a 1


            for(int i = 0; i<nHorarios; i++){
                if(horarios[i].idProf == idProf){
                    matEnc = 0;
                    horEnc = 1;
                    for(int o = 0; o<nMaterias;o++){
                        if(horarios[i].idMateria == materias[o].id){
                            matEnc = 1;
                            strcpy(nomMateria,materias[o].nombre);
                        }
                    }
                    if(matEnc == 0){
                        strcpy(nomMateria,"(Materia no registrada)");
                    }

                    printf("El día %i a %ia hora imparte la materia %s con el grupo %s\n",horarios[i].dia, horarios[i].hora, nomMateria, horarios[i].grupo);
                    matEnc = 0;
                }
            }
            if(horEnc == 0){
                printf("No se han encontrado horarios asignados al profesor %s",nombre);
            }
            free(horarios);
            free(materias);

        
            int op;
            printf("Teclee la acción que desee realizar:\n");
            printf("\t1. Añadir hora\n");
            if(horEnc == 1){
                printf("\t2. Eliminar hora\n");
                printf("\t3. Modificar hora\n");
            }
            printf("\t0. Atrás\n");
            fflush(stdin);
            scanf("%i",&op);

            //Dos menús diferentes, uno si tiene horas y otro si no.
            if(horEnc == 1){

                switch(op){
                    case 0:
                        salir2 = 1;
                    break;
                    case 1:
                        AnadirHora(idProf);
                    break;
                    case 2:
                        EliminarHora(idProf);
                    break;
                    case 3:
                        ModificarHora(idProf);
                    break;
                    default:
                        printf("Número no válido, teclee uno entre 0 y 3\n");
                    break;
                }
            }else{
                switch(op){
                    case 0:
                        salir2 = 1;
                    break;
                    case 1:
                        AnadirHora(idProf);
                    break;
                    default:
                        printf("Número no válido, teclee uno entre 0 y 3\n");
                    break;
                }
            }
            
        }
    }while(salir ==0);
    free(usuarios);
    fflush(stdin);

}