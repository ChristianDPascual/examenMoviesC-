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

int parser_FromText(FILE* pArchivo, LinkedList* lista)
{
	int retorno=FALSE;
	eMovie* aux;
	char id[T];
	char titulo[T];
	char genero[T];
	char duracion[T];

	if(pArchivo!=NULL && lista!=NULL)
	{
	  //si tiene cabecera hacer lectura en falso
	  fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,genero,duracion);
	  while(!feof(pArchivo))
	  {
		  fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,genero,duracion);
		  aux = Movie_nuevo();//creo una direccion de tipo pokemon y abajo le cargo las variables
		  aux= Movie_cargarParametros(id,titulo,genero,duracion);//cargo los aprametros
		  ll_add(lista,aux);//uso el linkelist para agregar la lista a memoria
	   }
	  retorno=TRUE;
	}

	return retorno;
}

