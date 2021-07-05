#ifndef VARIASCLIENTES_H_INCLUDED
#define VARIASCLIENTES_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include "unCliente.h"
#include "menu.h"

int validaEmail(char email[]);
int existenciaCliente (stCliente c[], int v, int nro);
int existenciaDNI (int dni);
int existenciaNroCl (int nro);
void guardaUnCliente(stCliente c);
void cargaArchivoClientes();
void muestraArchCliente ();
int buscaUltimoId();
void bajaCliente ();
stCliente buscaUnClienteApellidoArchivo(char apellido[]);
stCliente buscaUnClientePorID(int idCliente);
stCliente buscaMenorDNIarch ();
int buscaPos(int id);
void muestraArchClienteActivos();
void muestraArchClienteInactivos();
int buscaPosMenorDni(stCliente c[], int v, int inicio);
void intercambiaClientes(stCliente *a, stCliente *b);
void ordPorSelDni(stCliente c[], int v);
int buscaPosMenorApellido(stCliente c[], int v, int inicio);
void ordPorSelApellido(stCliente c[], int v);
int buscaPosMenorEmail(stCliente c[], int v, int inicio);
void ordPorSelEmail(stCliente c[], int v);
stCliente clienteModificado (stCliente c);
void modificaRegistro(stCliente c);

#endif // VARIASCLIENTES_H_INCLUDED
