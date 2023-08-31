#include "lib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

nodo*iniclista()
{
    return NULL;
}

nodo * crearNodo (char nombre[30], int edad)
{
    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux ->dato.edad = edad;
    strcpy(aux->dato.nombre, nombre);
    aux -> siguiente = NULL;
    return aux;
}

nodo * agregarAlPpio (nodo*lista, nodo*nuevo)
{
    if (lista ==NULL)
    {
        lista = nuevo;
    } else{
        nuevo ->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}

nodo * cargarNodoAlPpio (nodo * lista)
{
    nodo * nuevo;
    char continuar = 's';
    int edad;
    char nombre[30];

    while (continuar == 's')
    {
        printf("Ingrese el nombre:\n");
        fflush (stdin);
        gets (nombre);

        printf("Ingrese la edad: \n");
        fflush (stdin);
        scanf ("%i", &edad);

        nuevo = crearNodo(nombre,edad);

        lista = agregarAlPpio (lista,nuevo);

        printf("Ingrese s si desea continuar:\n");
        fflush (stdin);
        scanf("%c", &continuar);
    }
    return lista;
}

void imprimir (nodo *seguidora)
{
    printf("NOMBRE: %s\n", seguidora ->dato.nombre);
    printf("EDAD: %i\n", seguidora ->dato.edad);
}

void mostrarLista (nodo*lista)
{
    nodo *seguidora = lista;
    while (seguidora != NULL)
    {
        imprimir(seguidora);
        seguidora = seguidora ->siguiente;
    }
}

void buscarDato (nodo *lista, int edadAbuscar)

{
    nodo *anterior;
    nodo *seguidora = lista;
        while (seguidora->siguiente != NULL && (edadAbuscar != seguidora->dato.edad))
        {
            seguidora = seguidora ->siguiente;
        }
        imprimir(seguidora);
}

nodo *agregarENorden(nodo *lista, nodo *nuevo)
{

    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
        {
        if(nuevo->dato.edad < lista->dato.edad)

            lista = agregarAlPpio(lista,nuevo);
        else
        {
            nodo *anterior = lista;
            nodo *seguidora = lista;
            while(seguidora != NULL && nuevo->dato.edad > seguidora->dato.edad)
            {
                anterior = seguidora;
                seguidora = seguidora->siguiente;
            }
            anterior ->siguiente = nuevo;
            nuevo ->siguiente = seguidora;
        }
    }
    return lista;
}

nodo *borrarnodo (nodo *lista , int datoedad)
{
    if(lista!=NULL){
        if(lista->dato.edad == datoedad){
            nodo *aux = lista;
            lista = lista->siguiente;
            free(aux);
        }else{
            nodo *seguidora = lista ->siguiente;
            nodo *anterior = lista;
            while(seguidora != NULL && seguidora->dato.edad !=datoedad)
            {
                anterior = seguidora;
                seguidora = seguidora->siguiente;
            }
            anterior ->siguiente = seguidora ->siguiente;
            free(seguidora);
        }

    }
        return lista;
}

nodo *buscarUltimo (nodo *lista)
{
    nodo *seguidora = lista;
    if (lista != NULL)
    {
        while (seguidora->siguiente != NULL)
        {
            seguidora = seguidora->siguiente;
        }
    }
    return seguidora;
}
nodo * agregarAlFianl (nodo *lista, nodo *nuevo)
{
    if (lista == NULL)
    {
        lista = nuevo;

    } else
    {
        nodo *ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
    }
    return lista;
}
