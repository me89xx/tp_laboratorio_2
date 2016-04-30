#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    int estado;
    int dni;
}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona miLista[], int largo);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */

int buscarPorDni(EPersona miLista[], int dni,int largo);
void inicializar(EPersona miLista[], int largo);

/**
*Recibe un flag de estado
*@param En caso de que se encuentre un espacio disponible pide los datos que luego son guardados la estructura
*@param El estado del espacio cambia a lleno y se guarda
*
*/

void alta(EPersona miLista[],int libre);

/**
*Recibe el dato guardado en la estructura
*@param vacia el espacio que antes se encontraba lleno
*@param
*
*/

void baja(EPersona miLista[],int indice);

/**
*Recibe los datos guardados en la estructura y el estado.
*@param Determina mediante el metodo de burbujeo el orden a partir del nombre ingresado.
*@param Ordena el conjunto de personas ingresados.
*@return Muestra una lista de con los datos de las personas ingresadas en orden alfabetico.
*/

void imprimirLista(EPersona miLista[],int largo);

/**Busca los datos(edades) ingresados por el usuario en la estructura.
*@param Analiza las edades ingresadas en la estructura.
*@param
*@return Muestra mediante un grafico las edades ordenadas en 3 grupos.
*
*/

void Graficar(int hasta18 ,int de19a35,int mayorDe35);
#endif // FUNCIONES_H_INCLUDED
