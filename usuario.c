#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lector.h"
#include "escritor.h"

void Login(int *idUsuario, int *perfil){
    char nU[6];
    char cU[9];
    Usuario *u;
    int numUs = CargarUsuarios(&u);
    int pos = -1;
    do{
        do{
            printf("Introduzca su nombre de usuario\n");
            fflush(stdin);
            scanf("%s",nU);
            for(int i=0;i<numUs ;i++){ //obtención posición 
                if(strcmp(nU,u[i].nombreUsuario)==0){
                pos = i;
                }
            }
            if(pos == -1){
                printf("Usuario no encontrado, intentelo de nuevo.\n");
            }
        }while(pos == -1);

        do{

            printf("Introduzca su contraseña\n");
            scanf("%s",cU);
            if(strcmp(cU,"0") != 0){
                if(strcmp(cU,u[pos].contraseña)!=0){
                    printf("\n Contraseña incorrecta, intentelo de nuevo (0 para cambiar el usuario).\n");
                }
            }
        }while(strcmp(cU,u[pos].contraseña)!=0 && strcmp(cU,"0")!=0); //comprobación contraseña
    }while(strcmp(cU,"0")==0);


    //Devoluciones
    *idUsuario=u[pos].id;
    *perfil = u[pos].perfil;
} //inicialización de usuario

/*
void MostrarU(){
    Usuario u;
    int i, n = CargarUsuarios(&u);

        for(i=0;i<=n;i++)
        printf("%i - %s - %i - %s - %s\n",u[i].id,u[i].nombre,u[i].perfil,u[i].nombreUsuario,u[i].contraseña);
}
 
void ModdifU(){ //Modificación de datos 
    int n,i;
    char d,aux;
    char pasw[9];
    Usuario *u;
    int numUs = CargarUsuarios(&u);
    printf("Introduzca la Id del usuario que quiere modificar\n");
    scanf("%i",&n); //Recoge los datos de busqueda del usuario concreto al que se le quiere modificar los datos

    do{
    printf("¿Que dato quiere modificar?\n");
    printf("Escriba N si quiere modificar el nombre,\n n si quiere modificar el nombre de usuario,\n C si quiere modificar la contraseña \n P si quiere cambiar el perfil del usuario\n");
    printf("\n\n Escriba 0 si quiere salir de la modificación de datos")

    do{
        getchar(d);
        switch(d){
            case 'N': //Modificación del nombre
                u[i].nombre=ModName();
                break;

            case 'n': //Modificación del nombre de usuario
                u[i].nombreUsuario=ModNickname();
                break;

            case 'C': //Modificación de contraseña
                u[i].contraseña=ModPasword();
                break;

            case 'P'://Modificación del perfil
                u[i].perfil=ModProfile(u[i].perfil);
                break;

            case '0':
                break;
            default:  printf("Caracter incorrecto, vuelva a intentarlo\n");
                        break;
        }
    } while(d != '0');  

    EscribirUsuarios(u,numUs);
}



char *ModName(){
    char n_name[21];
    printf("Introducir nuevo nombre, recuerde que solo puede tener 20 caracteres, si incluye más solo se guardadran los 20 primeros\n");
    fgets(n_name,21,stdin);
    fflush;
    return(n_name);
}

char *ModNickname(){
    char n_nickname[6];
    printf("Introducir nuevo nombre de usuario, recuerde que solo puede tener 5 caracteres, si incluye más solo se guardarán los 5 primeros\n");
    fgets(n_nickname,6,stdin);
    fflush;
    return(n_nickname);
}

char *ModPasword(){
    char n_pasword[9];
    printf("Introducir nueva contraseña, recuerde que solo puede tener 8 caracteres, si incluye más solo se guardarán los 8 primeros\n");
    fgets(n_pasword,9,stdin);
    fflush;
    printf("Su nueva contraseña es %c\n",n_pasword);
    return(n_pasword);
}

int ModProfile(int p){
    if(p==0){
        p=1;
        printf("El profesor ahora es administrador.\n");
    }
     if(p==1){
        p=0;
        printf("El administrador ahora es profesor.\n");
    }
    return(p);
}

void SelectorU(){
    int s;
    do{
        printf("¿Qué acción desea realizar?\n1. Listar usuarios\n2. Modificar usuarios\n3. Volver");
        scanf("%i",&s);
    
        switch (s){
            case 1:
                MostrarU();
                break;

            case 2:
                ModdifU();
                break;

            case 3:
                break;
    
            default:
                printf("Caracter incorrecto. Vuelva a intentarlo\n");
                break;
        }
    }while(s != 3);

}
*/