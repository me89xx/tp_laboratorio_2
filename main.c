#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define C 20 //maximo de personas 20

int main()
{

    EPersona personas[C];
    char seguir='s';
    int opcion=0;
    int hasta18=0, de19a35=0, mayorDe35=0;
    inicializar(personas,C);

    while(seguir=='s')
    {
        int dni;
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                    alta(personas,obtenerEspacioLibre(personas,C));
                    if(personas[obtenerEspacioLibre(personas,C)].edad<18)
                        hasta18++;
                    if(personas[obtenerEspacioLibre(personas,C)].edad<=19 && personas[obtenerEspacioLibre(personas,C)].edad>=35)
                        de19a35++;
                    if(personas[obtenerEspacioLibre(personas,C)].edad>35)
                        mayorDe35++;
                break;
            case 2:
                printf("\nIngrese dni a eliminar:");
                scanf("%d",&dni);
                baja(personas,buscarPorDni(personas,dni,C));
                break;
            case 3:imprimirLista(personas,C); //Listado alfabeticamente
                break;
            case 4:Graficar(hasta18, de19a35, mayorDe35);
                break;
            case 5:
                seguir = 'n';
                break;
                default:printf("ingrese opcion valida\n");
        }
    }
    return 0;
}
