#ifndef PASAJES_H_INCLUDED
#define PASAJES_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include "unCliente.h"
#include "unConsumo.h"
#include "Arbol.h"

int arch2Arreglo(stCliente c[], int dimension);
int archInactivos2Arreglo(stCliente c[], int dimension);
int arch2ArregloConsumos(stConsumos c[], int dimension);
int arch2ArregloConsumosSegunID(stConsumos c[], int dimension, int nroCl);
int arch2ArregloConsumosBaja(stConsumos c[], int dimension);
void registroToRegistro();
nodoArbol* pasarArchToArbol (char archivo[], nodoArbol* arbol);

#endif // PASAJES_H_INCLUDED
