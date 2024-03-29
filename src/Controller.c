#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "UTN.h"
#include "parser.h"
#include "Movie.h"
#define FALSE -1
#define TRUE 0


int controller_cargarArchivo(char* pNombreArchivo, LinkedList* pListado)
{
	int retorno = FALSE;
    FILE* archivo = NULL;

    if(pListado != NULL)
    {
        archivo = fopen(pNombreArchivo, "r");


        if(parser_FromText(archivo, pListado) == TRUE)
        {

            retorno = TRUE;

        }
        fclose(archivo);
    }

    return retorno;
}

int controller_cargarArchivoBinario(char* pNombreArchivo, LinkedList* pListado)
{
	int retorno = FALSE;
    FILE* archivo = NULL;

    if(pListado != NULL)
    {
        archivo = fopen(pNombreArchivo, "rb");

        if(parser_FromText(archivo, pListado) == TRUE)
        {
            retorno = TRUE;
        }
        fclose(archivo);
    }

    return retorno;
}



int controller_guardarArchivo(char* pNombreArchivo,LinkedList* pListado)
{
    FILE* archivo = NULL;
    int retorno = FALSE;


    if(pListado != NULL && pNombreArchivo != NULL)
    {
        	archivo = fopen(pNombreArchivo,"w");

        	if(Movie_guardarArchivo(archivo,pListado) == TRUE)
        	{
        		printf("El archivo se guardo correctamente\n");
        		retorno = TRUE;
        	}
        	else
        	{
        		printf("No se pudo guardar el archivo\n");
        	}
        	fclose(archivo);

    }

    return retorno;
}

int controller_guardarArchivoBinario(char* pNombreArchivo,LinkedList* pListado)
{
    FILE* archivo = NULL;
    int retorno = FALSE;


    if(pListado != NULL && pNombreArchivo != NULL)
    {
        	archivo = fopen(pNombreArchivo,"wb");

        	if(Movie_guardarArchivo(archivo,pListado) == TRUE)
        	{
        		printf("El archivo se guardo correctamente\n");
        		retorno = TRUE;
        	}
        	else
        	{
        		printf("No se pudo guardar el archivo\n");
        	}
        	fclose(archivo);

    }

    return retorno;
}

int controller_listarElementos(LinkedList* pListado)
{
    int retorno=FALSE;


    if(pListado!=NULL)
    {
    	if(Movie_listarTodo(pListado)==TRUE)
    	{
    		retorno = TRUE;
    	}
    }
    return retorno;
}

int controller_mapCargarDuracion(LinkedList* pListado)
{
	int retorno = FALSE;

	if(pListado!=NULL && ll_len(pListado)>0)
	{
		pListado = ll_map(pListado,cargarDuracion);
		retorno  = TRUE;
	}

	return retorno;
	}
int controller_filtrarGenero(LinkedList* pListado)
{
	int retorno = FALSE;

	if(pListado!=NULL && ll_len(pListado)>0)
	{
		pListado = ll_filter(pListado,Movie_filtrarTipo);
		retorno  = TRUE;
	}

		return retorno;
}
