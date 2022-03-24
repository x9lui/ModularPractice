#include <stdio.h>
#include <stdlib.h>


//Lee un elemento del archivo y lo guarda en la cadena de caracteres
//La cadena de caracteres tiene que tener espacio suficiente para alojar el elemento del archivo + 1 (para el caracter nulo '\0')
void LecturaElemento(FILE *f,char *string)
{
    char ch = fgetc(f);
    int i = 0;
    do{
        string[i] = ch;
        i++;
        ch=fgetc(f);
    }while(ch != '-' && ch != '\n' && ch != EOF);
    string[i] = '\0';
}

//Saltar un elemento del archivo
void LecturaSalto(FILE *f){
    char ch;
    do{
        ch = fgetc(f);
    }while(ch != '-' && ch != '\n' && ch != EOF);
}

//EJEMPLO DE USO EN BUCLE
/*
while((ch = fgetc(f)) != EOF){          *NECESARIO*
        fseek(f,-1L,SEEK_CUR);          *NECESARIO*
        LecturaElemento(f,dato);        
        LecturaSalto(f);
        LecturaSalto(f);
        LecturaElemento(f,dato1);
        LecturaSalto(f);
        printf("%s%s",dato,dato1);
    }
*/