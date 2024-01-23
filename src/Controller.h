#ifndef CONTROLLER_H_
#define CONTROLLER_H_

//#endif /* CONTROLLER_H_ */

int controller_CargarArchivo(char* pNombreArchivo,LinkedList* pListado);
int controller_cargarArchivoBinario(char* pNombreArchivo, LinkedList* pListado);
int controller_guardarArchivo(char* pNombreArchivo, LinkedList* pListado);
int controller_guardarArchivoBinario(char* pNombreArchivo, LinkedList* pListado);
int controller_listarElementos(LinkedList* pListado);
int controller_modificarElemento(LinkedList* pListado);
int controller_eliminarElemento(LinkedList* pListado);
int controller_mapCargarDuracion(LinkedList* pListado);
int controller_filtrarGenero(LinkedList* pListado);

#endif /* CONTROLLER_H_ */
