#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "unConsumo.h"

typedef struct _nodoLista{
    stConsumos dato;
    struct _nodoLista* sig;
} nodo;

nodo* inicLista();
nodo* crearNodo(stConsumos dato);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo);
void muestraNodo(nodo *nodo);
void muestraLista(nodo* lista);
nodo* buscarUltimo(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
stConsumos verPrimero(nodo* lista);

#endif // LISTA_H_INCLUDED
