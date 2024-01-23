#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "UTN.h"

#include "Movie.h"
#include "parser.h"
#define FALSE -1
#define TRUE 0
#define T 50

int Menu()
{
	char respuesta[2];
    int opcion = -1;

    printf("1. Cargar archivo\n");
    printf("2. Mostrar lista\n");
    printf("3. Asignar tiempos\n");
    printf("4. Filtrar por tipo\n");
    printf("5. Mostrar duraciones\n");
    printf("6. Guardar Peliculas\n");
    printf("7. Salir\n");
	fflush(stdin);
	scanf("%[^\n]",respuesta);
	opcion=atoi(respuesta);

	while((validarNumeroEntero(respuesta))==FALSE || (opcion<1 || opcion>8))
	{
		printf("Error, Elija una opcion valida (1-8)\n");
		fflush(stdin);
		scanf("%[^\n]",respuesta);
		opcion=atoi(respuesta);
	}

    return opcion;
}


int buscarPorIDLaPosicion(LinkedList* lista, int ID)
{
	eMovie* aux = NULL;
	int posicion = -1;
	int tamanio;

	if(lista != NULL && ID>0)
	{
		tamanio = ll_len(lista);
		if(tamanio>0)
		{
			for(int i=0;i<tamanio;i++)
			{
				aux = ll_get(lista,i);
				if(aux->id_peli == ID)
				{
					posicion = i;
					break;
				}
			}
		}
	}

	return posicion;
}




int validarNumeroEntero(char numero[])
{
	int i;
	int largo;
	int control;
	int validacion=TRUE;

	largo=strlen(numero);

	for(i=0;i<largo;i++)
	{
	   control=isdigit(numero[i]);
	   if(control==0)
	   {
		   validacion=FALSE;
		   break;
	   }
	}

	return validacion;
}

int validarPalabra(char nombre[])
{
	int validacion=TRUE;
	int largo;
	int i;
	int control;

	largo=strlen(nombre);
	for(i=0;i<largo;i++)
	{
		control=isalpha(nombre[i]);
		if(control==0)
		{
			validacion=FALSE;
			break;
		}
	}

	return validacion;
}

int validarNumeroFlotante(char numero[])
{
	    int validacion=TRUE;
		int i;
		int comas=0;
		int valor=0;
		int control;

		for(i=0;i<strlen(numero);i++)
		{
		   control=isdigit(numero[i]);
		   if(control==0 && valor==0)
		   {
			   valor=-1;
			   if(numero[i]=='.' && i>1 && comas==0)
			   {
				valor=0;
				comas++;
			   }
			   else
			   {
				   validacion=FALSE;
				   break;
			   }

		   }
		}

	return validacion;
}

int compararEntreNumeros(int numero, int compararA,int compararB)
{
    int retorno = FALSE;

    if(numero>compararA && numero<compararB)
    {
         retorno = TRUE;
    }

    return retorno;
}

int parsearEntero(char cadena[],int* numero)
{
	int retorno = FALSE;

	if(cadena != NULL && numero !=NULL && validarNumeroEntero(cadena) == TRUE)
	{
		*numero = atoi(cadena);
		retorno = TRUE;
	}

	return retorno;
}

int parsearFlotante(char cadena[],float* numero)
{
	int retorno = FALSE;

	if(cadena != NULL && numero !=NULL && validarNumeroFlotante(cadena) == TRUE)
	{
		*numero = atoi(cadena);
		retorno = TRUE;
	}

	return retorno;
}
