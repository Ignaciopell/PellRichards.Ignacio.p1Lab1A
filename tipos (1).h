#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
    {
     int idTip;
     char descTip[20];
    }eTipo;




#endif // TIPOS_H_INCLUDED
int listarTipos(eTipo* lista, int tam);
int cargarTipo(int id, eTipo* lista, int tam,char destino[]);