#include <stdio.h>
#include <stdlib.h>
#include "lector.h"

void login(){ 
    char nU[6];
    char cU[9];
    int browser;
    Usuario *u;
    int numUs = CargarUsuarios(&u);

    do{
    printf("Introduzca su nombre de usuario\n");
    fgets(nU,6,stdin);
        for(browser=0;(strcmp(nU,u[browser].nombreUsuario))!=0 && browser<numUs ;browser++){ //obtención posición 
            if(browser==numUs) //volver a intoduzca nombre de usuario
                printf("Usuario no encontrado, intentelo de nuevo.\n");    
        }
    fflush(stdin);
    }while(browser==numUs); //inicio usuario

    do{
    printf("Introduzca su contraseña\n");
    fgets(c_u,9,stdin);
    if(strcmp(c_u,u[browser].contraseña)!=0)
        printf("\n Contraseña incorrecta, intentelo de nuevo.\n");
    fflush(stdin);
    }while(strcmp(cU,u[browser].contraseña)==0); //comprobación contraseña
} //inicialización de usuario
 
void moddif_u(){ //Modificación de datos 
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
                u[i].nombre=mod_name();
                break;

            case 'n': //Modificación del nombre de usuario
                u[i].nombreUsuario=mod_nickname();
                break;

            case 'C': //Modificación de contraseña
                printf("Escriba la contraseña actual\n");
                do{
                fgets(pasw);
                if(strcmp(pasw,u[i].contraseña)==0){
                u[i].contraseña=mod_pasword();
                aux=0
                }
                else{
                    printf("Contraseña incorrecta\n Introduzca 0 si quiere volver atrás\n");
                    scanf("%i",&aux);
                }
                }while(aux!=0);
                break;

            case 'P'://Modificación del perfil
                u[i].perfil=mod_profile(u[i].perfil);
                break;

            case '0':
                break;
            default:  printf("Caracter incorrecto, vuelva a intentarlo\n");
                        break;
        }
    } while(d != '0');   
    //Llamar a la funcion que escribe en el fichero 
}

char *mod_name(){
    char n_name[21];
    printf("Introducir nuevo nombre, recuerde que solo puede tener 20 caracteres, si incluye más solo se guardadran los 20 primeros\n");
    fgets(n_name,21,stdin);
    fflush;
    return(n_name);
}

char *mod_nickname(){
    char n_nickname[6];
    printf("Introducir nuevo nombre de usuario, recuerde que solo puede tener 5 caracteres, si incluye más solo se guardarán los 5 primeros\n");
    fgets(n_nickname,6,stdin);
    fflush;
    return(n_nickname);
}

char *mod_pasword(){
    char n_pasword[9];
    printf("Introducir nuevo nombre de usuario, recuerde que solo puede tener 8 caracteres, si incluye más solo se guardarán los 8 primeros\n");
    fgets(n_pasword,9,stdin);
    fflush;
    printf("Su nueva contraseña es %c\n",n_pasword);
    return(n_pasword);
}

int mod_profile(int p){
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

//f_borrar?

//Funcion de prueba de  las funciones

void prueba_flogin(){
    int numUs, auxp;
    Usuario *u,*uaux;
    numUs = CargarUsuarios(&u);
    auxp = CargarUsuarios(&uaux);
    for(auxp=0;auxp!=numUs;auxp++){
        autologin(auxp);
    }
}

    //Prueba automatica flogin
    void autologin(int aux){ 
        int browser;
        Usuario *u;
        int numUs = CargarUsuarios(&u);

        do{
            for(browser=0;(strcmp(u[aux].nombreUsusario,u[browser].nombreUsuario))!=0 && browser<numUs ;browser++){ //obtención posición 
                if(browser==numUs) //volver a intoduzca nombre de usuario
                    printf("Fallo en la función\n");    
            }
        }while(browser==numUs); //inicio usuario

        do{
        if(strcmp(u[aux].contraseña,u[browser].contraseña)!=0)
            printf("\nFallo de la función\n");
        fflush(stdin);
        }while(strcmp(u[aux].contraseña,u[browser].contraseña)==0); //comprobación contraseña
        printf("Usuario realizado correctamente");
    }

