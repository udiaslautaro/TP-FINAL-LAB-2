#ifndef UNCLIENTE_H_INCLUDED
#define UNCLIENTE_H_INCLUDED
#include <string.h>
#include <stdio.h>

#define AR_CLIENTES "Cliente.dat"
#define AR_ACTIVOS "Activos.dat"
#define AR_INACTIVOS "Inactivos.dat"

typedef struct {

   int id; /// campo único y autoincremental
   int nroCliente;
   char nombre[30];
   char apellido[30];
   int dni;
   char email[30];
   char domicilio[45];
   int movil;
   int baja;

} stCliente;

stCliente cargaUnCliente();
stCliente cargaUnClienteManual();
int cargaClientesArregloRandom(stCliente c[], int v, int dim);
void cargaArchivoClientesRandom(int cant);
void cargaArchivoClientesManual();
void muestraUnCliente(stCliente c);
void muestraClientes(stCliente c[], int v);


#endif // UNCLIENTE_H_INCLUDED
