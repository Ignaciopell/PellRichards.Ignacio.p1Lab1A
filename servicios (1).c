#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "servicios.h"

int listarServicios(eServicio* lista, int tam)
{
    int ret=0;
    if(lista!=NULL&&tam>0)
    {
        ret=1;
            printf("\n--LISTA DE SERVICIOS--\n");
        for(int i=0; i<tam; i++)
        {
            printf("ID: %d \nSERVICIO: %s \nPRECIO: $%d", lista[i].idServ, lista[i].descrServ,lista[i].precio);
            printf("\n----------------------\n");
        }
    }
    return ret;
}
