#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "LinkedList.h"
#include "Movie.h"
#include "Controller.h"
#include "UTN.h"
#include "parser.h"
#define FALSE -1
#define TRUE 0
#define T 50

int main(void) {

	setbuf(stdout,NULL);
	int cargado = FALSE;
	int opcion;
	char archivo[T] = "movies.csv";//nombre del archivo
	char nuevoArchivo[T] = "MoviesModificado.csv";

	LinkedList* lista = ll_newLinkedList();//creo la linkelist
	LinkedList* listaFiltrada = ll_newLinkedList();//creo una linkedlist para filtrar

	if(lista != NULL)
	{
		do{
			opcion = Menu();
			switch(opcion)
			{
			case 1:
				if(controller_cargarArchivo(archivo,lista)==TRUE)/*carga el archivo a link archivo+linked*/
				{
					printf("Se cargo exitosamente\n");
					cargado = TRUE;
				}
				else
				{
					printf("No se pudo cargar el archivo\n");
				}
			    break;
			case 2:
				if(cargado == TRUE)
				{
					if(controller_listarElementos(lista)==FALSE)//lista el archivo con el puntero de linkedlist
					{
						printf("Ocurrio un error inesperado\n");
					}
				}
				else
				{
					printf("Primero carge el archivo\n");
				}
				break;
			case 3:
				if(cargado == TRUE)
				{
					if(controller_mapCargarDuracion(lista)==FALSE)//modifica un pokemon
					{
						printf("Ocurrio un error inesperado\n");
					}

				}
				else
				{
					printf("Primero carge el archivo\n");
				}
				break;
			case 4:
				if(cargado == TRUE)
				{
					listaFiltrada = ll_filter(lista,Movie_filtrarTipo);
					if(controller_listarElementos(listaFiltrada)==FALSE)//lista el archivo con el puntero de linkedlist
					{
						printf("Ocurrio un error inesperado\n");
					}


				}
				else
				{
					printf("Primero carge el archivo\n");
				}
				break;
			case 5:
				if(cargado == TRUE)
				{

					if(controller_filtrarGenero(listaFiltrada)==FALSE)//lista el archivo con el puntero de linkedlist
					{
						printf("Ocurrio un error inesperado\n");
					}


				}
				else
				{
					printf("Primero carge el archivo\n");
				}
				break;
			case 6:
				if(cargado == TRUE)
				{
					if(controller_guardarArchivo(nuevoArchivo,lista)==TRUE)
					{
						printf("Se guardo exitosamente\n");
						cargado = TRUE;
					}
					else
					{
						printf("No se guardar cargar el archivo\n");
					}

				}
				else
				{
					printf("Primero carge el archivo\n");
				}
			    break;
		    case 7:
					printf("gracias por usar el programa\n");
			    break;
			}

		}while(opcion!=7);
	}
	else
	{
		printf("No hay espacio en la memoria del sistema");
		system("pause");
		exit(1);
	}


	return EXIT_SUCCESS;
}
