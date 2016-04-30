#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void inicializar(EPersona miLista[], int largo)
{
    int i;
    for(i=0; i<largo; i++)
    {
        miLista[i].estado=1;
    }
}

int obtenerEspacioLibre(EPersona miLista[], int largo)
{
    int i;
    int flag=-1;
    for(i=0; i<largo; i++)
    {
        if(miLista[i].estado==1)
        {
           flag=i;
           break;
        }
    }
    if(i==largo)//LLego al final del array y no encontro espacio
            {
                printf("Capacidad agotada!!!\n");
            }
    return flag;
}
void alta(EPersona miLista[],int libre)
{
    if(libre!= -1) // Se ingresan datos en el espacio disponible
    {
        printf("\nIngrese dni: ");
        scanf("%d",&miLista[libre].dni);
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(miLista[libre].nombre);
        printf("\nIngrese edad: ");
        scanf("%d",&miLista[libre].edad);
        miLista[libre].estado=0;
    }
}


 int buscarPorDni(EPersona miLista[], int dni,int largo)
{
    int indice=-1;
    int i;
    for(i=0; i<largo; i++)
    {
        if(miLista[i].estado==0 && miLista[i].dni==dni)
        {
            indice=i;
            break;
        }

    }
    if(i==largo)
    {
       printf("No existe el dni buscado\n");
    }
    return indice;

}
void baja(EPersona miLista[],int indice)
{
    miLista[indice].estado=1;
}
void imprimirLista(EPersona miLista[],int largo)
{
    EPersona aux;
    int i,j;
    for(i=0; i<largo-1; i++)
    {
        for(j=i+1; j<largo; j++)
        {

            if(strcmp(miLista[i].nombre, miLista[j].nombre)>0)
            {
                aux=miLista[i];
                miLista[i]=miLista[j];
                miLista[j]=aux;
            }
        }
    }
    for(i=0;i<largo;i++)
    {
        if(miLista[i].estado!= 1)
        {
            printf("%d -- %s -- %d\n", miLista[i].dni, miLista[i].nombre, miLista[i].edad);
        }
    }
}

void Graficar(int hasta18 ,int de19a35,int mayorDe35)
{
int i, flag=0, mayor;
if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
    {
        mayor = hasta18;
    }else
    {
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else
        {
        mayor = mayorDe35;
        }
    }

    for(i=mayor; i>0; i--)
    {
        if(i<10){
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= hasta18)
        {
            printf("*");
        }
        if(i<= de19a35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d\n", hasta18, de19a35, mayorDe35);
}
