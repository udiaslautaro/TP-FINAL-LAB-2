#ifndef UNCONSUMO_H_INCLUDED
#define UNCONSUMO_H_INCLUDED
#include "unCliente.h"
#include "variasClientes.h"
#include "utilidades.h"

#define AR_CONSUMO "Consumo.dat"

typedef struct {

   int id;  /// campo único y autoincremental
   int idCliente;
   int anio; /// 2020
   int mes; /// 1 a 6
   int dia; /// 1 a … dependiendo del mes
   int datosConsumidos;  /// expresados en mb
   int baja;  /// 0 Activo - 1 Eliminado

} stConsumos;

stConsumos cargaUnConsumo(int id);
void cargaConsumoClienteRandom();
void cargaArchConsumoRandom(stCliente cl, int cant);
void guardaUnConsumo(stConsumos C);
void muestraUnConsumo(stConsumos C);
void muestraArchConsumo ();


#endif // UNCONSUMO_H_INCLUDED
