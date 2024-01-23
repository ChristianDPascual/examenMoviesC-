#include "LinkedList.h"
#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */

/*Funciones especificas*/
int Menu();
int buscarPorIDLaPosicion(LinkedList* pokedex, int index);


/*Funciones genericas*/
int validarNumeroEntero(char cadena[]);
int validarPalabra(char cadena[]);
int validarNumeroFlotante(char cadena[]);
int compararEntreNumeros(int numero, int compararA,int compararB);
int parsearEntero(char cadena[],int* numero);
int parsearFlotante(char cadena[],float* numero);
