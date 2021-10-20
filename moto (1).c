#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "moto.h"


int inicializarMotos(eMoto* lista, int tam)
{
    int ret=0;
    if(lista!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty=1;
        }
        ret=1;
    }
    return ret;
}
int buscarLibre(eMoto* lista, int tam)
{
    int libre=-1;
    if(lista!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==1)
            {
                libre=i;
                break;
            }
        }
    }
    return libre;
}
int altaMoto(eMoto* lista, int tam, int* nextId,eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor)
{
    int ret=0;
    if(lista!=NULL&&tam>0&&nextId!=NULL)
    {
        int actualIndex;
        system("cls");
        actualIndex=buscarLibre(lista,tam);
        printf("\nEl ID de la nueva moto es %d.\n",*nextId);
        lista[actualIndex].idMoto=(*nextId);
        (*nextId)++;
        system("pause");
        system("cls");
        ingresarCadena("marca",lista[actualIndex].marca,20);
        listarTipos(listaTipo,tamTipo);
        printf("\n");
        ingresarEntero("id tipo",&lista[actualIndex].idTipo,1000,1003);
        listarColores(listaColor,tamColor);
        printf("\n");
        ingresarEntero("id color",&lista[actualIndex].idColor,5000,5004);
        ingresarCilindrado(&lista[actualIndex].cilindrado);
         printf("\n");
         ingresarEntero("puntaje",&lista[actualIndex].puntaje,0,10);
       
       
        
        

        lista[actualIndex].isEmpty=0;
        printf("\nMoto cargada exitosamente.\n");
        mostrarMoto(lista[actualIndex],listaTipo,tamTipo,listaColor,tamColor);
        system("pause");
        ret=1;
    }
    return ret;
}
int ingresarCilindrado(int* campo)
{
    int ret=0;
    int auxInt;

    if(campo!=NULL)
    {
        printf("Ingrese cilindrado: \n");
        __fpurge(stdin);
        scanf("%d",&auxInt);
        while(auxInt!=50 && auxInt!=125 && auxInt!=500 && auxInt!=600 && auxInt!= 750)
        {
            printf("cilindrado invalido. Reingresar 50/125/500/600/750.\n");
            __fpurge(stdin);
            scanf("%d",&auxInt);
        }
        *campo=auxInt;
        ret=1;
    }
    return ret;
}

int ingresarPuntaje(int* campo)
{
    int ret=0;
    int auxInt;

    if(campo!=NULL)
    {
        printf("Ingrese puntaje: \n");
        __fpurge(stdin);
        scanf("%d",&auxInt);
        
        while(auxInt> 10 ||auxInt<0)
        {
            printf("puntaje invalido. Reingresar del 0 al 10.\n");
            __fpurge(stdin);
            scanf("%d",&auxInt);
        }
        *campo=auxInt;
        ret=1;
    }
    return ret;
}





void mostrarMoto(eMoto moto,eTipo* listaT, int tamT, eColor* listaC, int tamC)
{
    char descTipo[20];
    char descColor[20];
    cargarTipo(moto.idTipo,listaT,tamT,descTipo);
    cargarColor(moto.idColor,listaC,tamC,descColor);
    printf("\n----------------------\n");
    printf("[ID]:        %d \nMARCA:       %s \nTIPO:        %s \nCOLOR:       %s \nCILINDRADO:      %.1d  \nPUNTAJE     %d \n\n",
           moto.idMoto, moto.marca, descTipo,descColor,moto.cilindrado,moto.puntaje);

}
int mostrarMotos(eMoto* lista, int tam, eTipo* listaT,int tamT, eColor* listaC, int tamC)
{
    int ret=0;
    if(lista!=NULL&&tam>0)
    {
        ret=1;
        system("cls");
        printf("---------LISTA DE MOTOS---------\n");
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0)
            {
                mostrarMoto(lista[i],listaT,tamT,listaC,tamC);
                printf("------------------------------------\n");
            }
        }
    }
    return ret;
}
int checkMotoCargada(eMoto* lista,int tam)
{
    int check=0;
    if(lista!= NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0)
            {
                check=1;
                return check;
                break;
            }

        }
    }
    return check;
}
int buscarMotoId(eMoto* lista, int tam)
{
    int posicion=-1;

    if(lista!=NULL&&tam>0)
    {
        int userInput;
        printf("Ingrese ID que desea modificar: ");
        __fpurge(stdin);
        scanf("%d",&userInput);

        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==1)
            {
                continue;
            }
            else if(lista[i].idMoto==userInput)
            {
                posicion=i;
                break;
            }
        }
        if(posicion==(-1))
        {
            printf("No se encontro dicho ID.\t");
            system("pause");
        }
    }
    return posicion;
}
int editarMoto(eMoto* lista, int tam, int index, eTipo* tipos,int tamT,eColor* colores,int tamC)
{
    int ret=0;
    if(lista!=NULL&&tam>0&&index>-1)
    {
        int opcion;
        printf("------------------------------------\n");
        mostrarMoto(lista[index],tipos,tamT,colores,tamC);
        printf("------------------------------------\n");
        printf("Que desea modificar?\n[1]-Marca\n[2]-Tipo\n[3]-Color\n[4]-cilindrado\n");
        __fpurge(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            ingresarCadena("marca",lista[index].marca,20);
            printf("\nMarca cambiada exitosamente. \n");
            system("pause");
            break;
        case 2:
            listarTipos(tipos,tamT);
            ingresarEntero("tipo",&lista[index].idTipo,1000,1003);
            printf("\nTipo cambiado exitosamente. \n");
            system("pause");
            break;
        case 3:
            listarColores(colores,tamC);
            ingresarEntero("color",&lista[index].idColor,5000,5004);
            printf("\nColor cambiado exitosamente. \n");
            system("pause");
            break;
        case 4:
            ingresarCilindrado(&lista[index].cilindrado);
            printf("\nCilindrado cambiado exitosamente. \n");
            system("pause");
            break;
        }
        ret=1;
    }
    return ret;
}
int removerMoto(eMoto* lista,int tam, int index,eTipo* tipos,int tamT,eColor* colores, int tamC)
{
    int ret=0;
    if(lista!=NULL && tam>0 && index>(-1))
    {
        char rta;
        ret=1;
        printf("------------------------------------\n");
        mostrarMoto(lista[index],tipos,tamT,colores,tamC);
        printf("------------------------------------\n");
        printf("\n Desea eliminar permanentemente esta bici? s/n \n");
        __fpurge(stdin);
        scanf("%c",&rta);
        if(rta=='s')
        {
            lista[index].isEmpty=1;

            printf("Moto eliminada exitosamente.\n");
            system("pause");
        }
        else
        {
            printf("No se eliminara esta Moto.\n");
            system("pause");
        }

    }
    return ret;
}
