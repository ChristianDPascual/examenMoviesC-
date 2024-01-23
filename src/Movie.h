#ifndef MOVIE_H_
#define MOVIE_H_


typedef struct
{
	int id_peli;
	char titulo[50];
	char genero[50];
    int duracion;

}eMovie;



eMovie* Movie_nuevo();
eMovie* Movie_cargarParametros(char* id,char* titulo, char* genero, char* duracion);

/* GETERS Y SETERS*/

/*GET*/
int get_titulo(eMovie* pElement, char* nombre);
int get_duracion(eMovie* pElement, int* numero);
int get_genero(eMovie* pElement, char* nombre);
int get_id(eMovie* pElement, int* numero);


/*SET*/
int set_titulo(eMovie* pElement, char* nombre);
int set_duracion(eMovie* pElement, int* numero);
int set_genero(eMovie* pElement, char* nombre);
int set_id(eMovie* pElement, int* numero);



int Movie_listarUnElemento(eMovie* pElement);
int Movie_listarTodo(LinkedList* lista);
int Movie_filtrarTipo(void* pElement);


int Movie_guardarArchivo(FILE* pNombreArchivo, LinkedList* pListado);
int Movie_modificarStruct(LinkedList* lista);
int Movie_eliminarStruct(LinkedList* lista);
int cargarDuracion(void* pElement);


#endif /* MOVIE_H_ */
