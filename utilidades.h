#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED
#include "unCliente.h"
#include "variasClientes.h"

int randomRango(int min, int max);
int validacFecha(int dia, int mes, int anio);
void getNombre(char n[]);
void getApellido(char a[]);
void getCalle(char c[]);
int getCalleNro();

#endif // UTILIDADES_H_INCLUDED
