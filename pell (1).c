#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pell.h"

int menu()
{
    int opcion;
    system("cls");
    printf("-------- MENU MOTOS --------\n\n");
    printf("1. ALTA MOTO\n");
    printf("2. MODIFICAR MOTO\n");
    printf("3. BAJA MOTO\n");
    printf("4. LISTAR MOTOS\n");
    printf("5. LISTAR TIPOS\n");
    printf("6. LISTAR COLORES\n");
    printf("7. LISTAR SERVICIOS\n");
    printf("8. ALTA TRABAJO\n");
    printf("9. LISTAR TRABAJOS\n");
    printf("10. Salir del programa.\n\n");

    ingresarEntero("opcion",&opcion,0,0);




    return opcion;
}
int ingresarEntero(char texto[],int* campo,int minimo,int limite)
{
    int ret=0;
    int auxInt;
    if(limite==0)
    {
        limite=2147483647;
    }
    if(texto!=NULL&&campo!=NULL&&limite >(-1))
    {
        printf("Ingrese %s: \n",texto);
        __fpurge(stdin);
        scanf("%d",&auxInt);
        while(auxInt<minimo||auxInt>limite)
        {
            printf("Invalido. Reingresar con id %s.\n",texto);
           __fpurge(stdin);
            scanf("%d",&auxInt);
        }
        *campo=auxInt;
        ret=1;
    }
    return ret;
}
int ingresarCadena(char texto[],char* campo,int tam)
{
    int ret=0;
    char auxCad[100];
    if(texto!= NULL && campo != NULL && tam>0)
    {
        printf("Ingrese %s :\n",texto);
        __fpurge(stdin);
        gets(auxCad);
        while(strlen(auxCad)==0 || strlen(auxCad)>tam)
        {
            printf("Invalido. Reingresar con id %s:\n",texto);
            __fpurge(stdin);
            gets(auxCad);
        }
        strcpy(campo, auxCad);
        ret=1;
    }
    return ret;
}
