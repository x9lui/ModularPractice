#include <stdio.h>
#include <stdlib.h>
#include "lector.h"

typedef struct{
    int id_usuario//3+1
    char nomb_usuario[21] //20+1
    int p_usuario //admin 1, prof 0
    char nickname[6] //5+1
    char contraseña[9] //8+1 
}usuarios;

//usuarios u[500]; //numero aletaorio, introducir 

void login(){ 
    char n_u[6];
    char c_u[9];
    int browser;
    usuarios u[500];

    do{
    printf("Introduzca su nombre de usuario\n");
    fgets(n_u,6,stdin);
        for(browser=0;(strcmp(n_u,u[browser].nickname))!=0 && browser<500 ;browser++){ //obtención posición 
            if(browser=500) //volver a intoduzca nombre de usuario
                printf("Usuario no encontrado, intentelo de nuevo.\n");
        }
    fflush(stdin);
    }while(browser==500); //inicio usuario

    do{
    printf("Introduzca su contraseña\n");
    fgets(c_u,9,stdin);
    if(strcmp(c_u,u[browser].contraseña)!=0)
        printf("\n Contraseña incorrecta, intentelo de nuevo.\n");
    fflush(stdin);
    }while(strcmp(c_u,u[browser].contraseña)==0); //comprobación contraseña
} //inicialización de usuario
 
void moddif(){
    int n,i;
    char d
    printf("Introduzca la Id del usuario que quiere modificar\n");
    scanf("%i",&n);

    do{
    printf("¿Que dato quiere modificar?\n");
    printf("Escriba N si quiere modificar el nombre,\n n si quiere modificar el nombre de usuario,\n C si quiere modificar la contraseña \n P si quiere cambiar el perfil del usuario\n");
    printf("\n\n Escriba 0 si quiere salir de la modificación de datos")
    scanf("c",&d);
    if(d!="N",d!="n",d!="C",d!="c",d!="P",d!="p"){
        printf("Caracter incorrecto, vuelva a intentarlo\n");
    }
    }while(d!="N",d!="n",d!="C",d!="c",d!="P",d!="p",d!="0");

    if(d==N){

        
    }
    do{
        //fgets
        switch(d){
            case 'N':

        

            case '0':break;

        }
    } while(d != '0');   
}