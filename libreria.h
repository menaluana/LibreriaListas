#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct{
    char nombre[30];
    int edad;
}stPersona;


typedef struct
{
    stPersona dato;
    struct nodo * siguiente;
} nodo;

nodo * iniclista ();
nodo * crearNodo (char nombre[30], int edad);
nodo * agregarAlPpio (nodo*lista, nodo*nuevo);
nodo * cargarNodoAlPpio (nodo * lista);
void imprimir (nodo *seguidora);
void mostrarLista (nodo*lista);
void buscarDato (nodo *lista, int edadAbuscar);
nodo *agregarENorden(nodo *lista, nodo *nuevo);
nodo *borrarnodo (nodo *lista , int datoedad);
nodo *buscarUltimo (nodo *lista);
nodo * agregarAlFianl (nodo *lista, nodo *nuevo);
#endif // LIB_H_INCLUDED
