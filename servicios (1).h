#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
    {
     int idServ;
     char descrServ[25];
     int precio;
     
    }eServicio;

int listarServicios(eServicio* lista, int tam);


#endif // SERVICIOS_H_INCLUDED