#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unCliente.h"
#include "unConsumo.h"
#include "listaSimple.h"

typedef struct _nodoArbol{
    stCliente dato;
    nodo* listaDeConsumos;
    struct _nodoArbol* izq;
    struct _nodoArbol* der;
} nodoArbol;

nodoArbol* inicArbol ();
nodoArbol* crearNodoArbol (stCliente dato);
nodoArbol* agregarArbol (nodoArbol* arbol, stCliente dato);
void preorder (nodoArbol* arbol);
nodoArbol* buscarDatoArbol (nodoArbol* arbol, stCliente dato);
nodoArbol* alta (nodoArbol* arbol, nodo* nuevoConsumo, stCliente dato);
int cuentaNodosTerminales (nodoArbol* arbol);
int nodoHoja (nodoArbol* arbol);
int cuentaNodos (nodoArbol* arbol);
int ramaMayor (int izquierda, int derecha);
int alturaArbol (nodoArbol* arbol);
nodoArbol* nodoMasDerecha(nodoArbol *arbol);
nodoArbol* nodoMasIzquierda(nodoArbol *arbol);
nodoArbol* borrarNodoArbol(nodoArbol *arbol, stCliente dato);
void mostrarNodoArbol(nodoArbol* arbol);
#endif // ARBOL_H_INCLUDED
