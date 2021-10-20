#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
  int idColor;
  char nombreColor[20];
} eColor;



#endif // COLOR_H_INCLUDED

int listarColores (eColor * lista, int tam);
int cargarColor (int id, eColor * lista, int tam, char destino[]);