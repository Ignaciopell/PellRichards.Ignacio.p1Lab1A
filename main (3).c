#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "moto.h"
#include "pell.h"
#include "tipos.h"
#include "color.h"
#include "servicios.h"



#define TAM_TIP 4
#define TAM_COL 5
#define TAM_SERV 4
#define TAM_MOTO 100

int main ()
{
  eTipo tipos[TAM_TIP] = {
    {1000, "Enduro"},
    {1001, "Chopera"},
    {1002, "Scooter"},
    {1003, "Vintage"}
  };
  eColor colores[TAM_COL] = {
    {5000, "Gris"},
    {5001, "Negro"},
    {5002, "Azul"},
    {5003, "Blanco"},
    {5004, "Rojo"}
  };
  eServicio servicios[TAM_SERV] = {
    {20000, "Limpieza", 450},
    {20001, "Ajuste", 300},
    {20002, "Balanceo", 150},
    {20003, "Cadena", 390}
  };

  char seguir = 's';

  eMoto listaMotos[100];
  inicializarMotos (listaMotos, TAM_MOTO);
  int nextID = 1;



  do
    {
      switch (menu ())
	{
	case 1:
	  altaMoto (listaMotos, TAM_MOTO, &nextID, tipos, TAM_TIP, colores,TAM_COL);
	  break;
	case 2:
	  if (checkMotoCargada (listaMotos, TAM_MOTO))
	    {
	      editarMoto (listaMotos, TAM_MOTO,
			  buscarMotoId (listaMotos, TAM_MOTO), tipos, TAM_TIP, colores, TAM_COL);
	    }
	  else
	    {
	      printf ("Cargue primero una moto.\n");
	      system ("pause");
	    }
	  break;
	case 3:
	  if (checkMotoCargada (listaMotos, TAM_MOTO))
	    {
	      removerMoto (listaMotos, TAM_MOTO,
			   buscarMotoId (listaMotos, TAM_MOTO), tipos, TAM_TIP,
			   colores, TAM_COL);
	    }
	  else
	    {
	      printf ("Cargue primero una moto.\n");
	      system ("pause");
	    }
	  break;
	case 4:
	  if (checkMotoCargada (listaMotos, TAM_MOTO))
	    {
	      mostrarMotos (listaMotos, TAM_MOTO, tipos, TAM_TIP, colores,
			    TAM_COL);
	      system ("pause");
	    }
	  else
	    {
	      printf ("Cargue primero una moto.\n");
	      system ("pause");
	    }
	  break;
	case 5:
	  listarTipos (tipos, TAM_TIP);
	  system ("pause");
	  break;
	case 6:
	  listarColores (colores, TAM_COL);
	  system ("pause");
	  break;
	case 7:
	  listarServicios (servicios, TAM_SERV);
	  system ("pause");
	  break;

	case 8:
	 printf("alta trabajo\n");
	  system ("pause");
	  break;

	case 9:
	  printf("listar trabajo\n");
	  system ("pause");
	  break;
	case 10:
	  printf ("desea cancelar la salida? s/n: ");
	  __fpurge (stdin);
	  scanf (" %c", &seguir);

	  if (seguir == 'n')
	    {
	      printf ("gracias por hoy");
	      seguir = 'n';
	    }


	  break;

	  break;

	default:
	  printf ("Invalido. Ingrese otra opcion.");
	  system ("pause");
	  break;
	}
    }
  while (seguir == 's');




  return 0;
}
