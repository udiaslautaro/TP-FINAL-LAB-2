#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "unConsumo.h"

typedef struct{
    stConsumos dato;
    struct nodo* sig;
} nodo;

nodo* inicLista();
nodo* crearNodo(stConsumos dato);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo);
void muestraNodo(nodo *nodo);
void muestraLista(nodo* lista);
nodo* buscarUltimo(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
stConsumos verPrimero(nodo* lista);
int cuentaLista(nodo* lista);
int sumaConsumos(nodo* lista);

#endif // LISTA_H_INCLUDED
