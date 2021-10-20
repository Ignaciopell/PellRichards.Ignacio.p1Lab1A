


#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED
#include"pell.h"
#include "tipos.h"
#include "color.h"

typedef struct
    {
     int idMoto;
     char marca[20];
     int idTipo;
     int idColor;
     int cilindrado;
     int puntaje;
     int isEmpty;
    }eMoto;

#endif // MOTO_H_INCLUDED
int inicializarMotos(eMoto* lista, int tam);
int buscarLibre(eMoto* lista, int tam);
int altaMoto(eMoto* lista, int tam, int* nextId,eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor);
int ingresarCilindrado(int* campo);
int ingresarPuntaje(int* campo);
void mostrarMoto(eMoto moto,eTipo* lista, int tam, eColor* listaC, int tamC);
int mostrarMotos(eMoto* lista, int tam, eTipo* listaT,int tamT, eColor* listaC, int tamC);
int checkMotoCargada(eMoto* lista,int tam);
int buscarMotoId(eMoto* lista, int tam);
int editarMoto(eMoto* lista, int tam, int index, eTipo* tipos,int tamT,eColor* colores,int tamC);
int removerMoto(eMoto* lista,int tam, int index,eTipo* tipos,int tamT,eColor* colores, int tamC);
