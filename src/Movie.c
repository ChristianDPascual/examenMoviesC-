#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Movie.h"
#include "Controller.h"
#include "UTN.h"
#include "parser.h"
#define FALSE -1
#define TRUE 0
#define T 50


/*----------Constructores------------------------*/
eMovie* Movie_nuevo()
{
	eMovie* aux = (eMovie*)malloc(sizeof(eMovie));
	if(aux != NULL)
	{
		strcpy(aux->genero," ");
		strcpy(aux->titulo," ");
		aux->duracion = 0;
		aux->id_peli = 0;
	}

	return aux;

}
//id,titulo,genero,duracion
eMovie* Movie_cargarParametros(char* id, char* titulo, char* genero,char* duracion)
{
	eMovie* aux;

	strcpy(aux->titulo,titulo);
	strcpy(aux->genero,genero);
	aux->id_peli = atoi(id);
	aux->duracion = atoi(duracion);


	return aux;
}

/*----------------GET Y SET------------------ */

int get_titulo(eMovie* pElement, char* nombre)
{
	int retorno = FALSE;

	if(pElement != NULL && nombre != NULL)
	{
		strcpy(nombre,pElement->titulo);
		retorno = TRUE;
	}

    return retorno;
}

int get_genero(eMovie* pElement, char* nombre)
{
	int retorno = FALSE;

	if(pElement != NULL && nombre != NULL)
	{
		strcpy(nombre,pElement->genero);
		retorno = TRUE;
	}

    return retorno;
}



int get_id(eMovie* pElement, int* numero)
{
	int retorno = FALSE;

	if(pElement != NULL && numero != NULL)
	{
		*numero = pElement->id_peli;
		retorno = TRUE;
	}

    return retorno;
}
int get_duracion(eMovie* pElement, int* numero)
{
	int retorno = FALSE;

	if(pElement != NULL && numero != NULL)
	{
		*numero = pElement->duracion;
		retorno = TRUE;
	}

    return retorno;
}


int set_genero(eMovie* pElement, char* nombre)
{
	int retorno = FALSE;

	if(pElement != NULL && nombre != NULL)
	{
		strcpy(pElement->genero,nombre);
		retorno = TRUE;
	}

    return retorno;
}

int set_titulo(eMovie* pElement, char* nombre)
{
	int retorno = FALSE;

	if(pElement != NULL && nombre != NULL)
	{
		strcpy(pElement->titulo,nombre);
		retorno = TRUE;
	}

    return retorno;
}


int set_id(eMovie* pElement, int* numero)
{
	int retorno = FALSE;

	if(pElement != NULL && numero != NULL)
	{
		pElement->id_peli = *numero;
		retorno = TRUE;
	}

    return retorno;
}

int set_duracion(eMovie* pElement, int* numero)
{
	int retorno = FALSE;

	if(pElement != NULL && numero != NULL)
	{
		pElement->duracion = *numero;
		retorno = TRUE;
	}

    return retorno;
}
int Movie_listarUnElemento(eMovie* pElement)
{
	char genero[T];
	char titulo[T];
	int duracion;
	int id;
	int retorno = FALSE;

	if(pElement != NULL && get_id(pElement,&id)==TRUE &&
	get_duracion(pElement,&duracion)==TRUE && get_titulo(pElement,titulo) ==TRUE && get_genero(pElement,genero) ==TRUE)
	{//printf("%5d\t %15s\t %10s\t %5s\t\t  %15s \t  %5d \t    %10d\n\n",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVarioColor);
		printf("%5d\t %15s\t %10s \t%5d\n\n",id,titulo,genero,duracion);
		retorno = TRUE;
	}

	return retorno;
}

int Movie_listarTodo(LinkedList* lista)
{
	eMovie* aux;
    int retorno = FALSE;
	int tamanio;
	int contador = 0;
	int i= 0;
	char cabecera[4][25] = {("id"),("genero"),("titulo"),("duracion")};

	if(lista != NULL)
	{
		tamanio = ll_len(lista);
		//%5d\t %15s\t %10s\t %5s\t\t  %15s \t  %5d \t    %10d\n\n
		printf("%5s\t %15s\t %10s \t%5s\n\n",cabecera[0],cabecera[1],cabecera[2],cabecera[3]);
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
		for(i=0;i<tamanio;i++)
		{
			aux = (eMovie*)ll_get(lista,i);
			if(aux != NULL)
			{
				if(Movie_listarUnElemento(aux)==TRUE)
				{
					contador ++;
				}
			}
		}

		if(contador == i)
		{
			retorno = TRUE;
		}

	}

	return retorno;
}

int Movie_guardarArchivo(FILE* pNombreArchivo,LinkedList* pListado)
{
    int retorno = FALSE;
    char cabecera[4][25] = {("id"),("genero"),("titulo"),("duracion")};
    int tamanio;
    int i;
    eMovie* aux;

    if(pListado != NULL && pNombreArchivo != NULL)
    {
        tamanio = ll_len(pListado);

        if(tamanio>0 && fprintf(pNombreArchivo,"%s,%s,%s,%s\n",cabecera[0],cabecera[1],cabecera[2],cabecera[3])!= FALSE)
        {
            	/*si tiene cabecera agrego en el if para sumarle la cabecera
        	    && fprintf(nombre de archivo, "los items de la cabcera ej nombre,id,tipo,etc\n") != -1*/
        		for(i=0;i<tamanio;i++)
        		{
        			aux =(eMovie*)ll_get(pListado,i);
        			//creo un puntero auxiliar del tipo ePokedex == parseo el resultado que me devueleve un void*
        			//                                              para convertirlo en un puntero del tipo ePokedex
        			//                                              me va a devolver el puntero al elemento q contiene ese nodo

        			/*if(aux == NULL || fprintf(pNombreArchivo,"%d,%s,%s,%s,%s,%d,%d\n",aux->numero,aux->nombre,aux->tipo,
        					                 aux->tamanio,aux->ataqueCargado,aux->valorAtaque,aux->esVarioColor) == FALSE)*/
        			if(aux == NULL || fprintf(pNombreArchivo,"%d,%s,%s,%d\n",aux->id_peli,aux->titulo,aux->genero,aux->duracion) == FALSE)
        			{
        				//si el puntero es nulo es decir q termino de recorrer la lista, o no se puede las variables
        				//en el archivo guardar el archivo, se detiene el programa
        				break;
        			}
        		}

            	if(i > 0 && i == tamanio)
            	{
            	   retorno = TRUE;
                }

        }
    }

    return retorno;
}


int cargarDuracion(void* pElement)
{
	int retorno = FALSE;
	eMovie* aux;
	int numero;


	if(pElement!= NULL)
	{
		aux = (eMovie*)pElement;
		numero = (rand() % 140) + 100;
		if(set_duracion(aux,&numero) == TRUE)
		{
			retorno = TRUE;
		}
	}

	return retorno;
}
int Movie_filtrarTipo(void* pElement)
{
	eMovie* aux;
    int retorno = FALSE;

		if(pElement != NULL)
		{
			aux = (eMovie*)pElement;

			if(strcmp(aux->genero,"Horror") == TRUE)
			{
					retorno = TRUE;

			}


		}

		return retorno;
	}




