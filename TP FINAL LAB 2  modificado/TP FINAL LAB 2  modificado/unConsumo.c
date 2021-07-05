#include "unConsumo.h"
#include "variasConsumos.h"
#include "variasClientes.h"

/********************************
 * \brief CARGA UN SOLO CONSUMO
 * \param ID DEL CLIENTE
 * \return CONSUMO
 ********************************/

stConsumos cargaUnConsumo(int id)
{
    stConsumos C;
    C.idCliente = id;
    do {
    C.anio = randomRango(2020, 2021);
    C.mes = randomRango(1, 12);
    C.dia = randomRango(1, 31);
    } while (!validacFecha(C.anio, C.mes, C.dia));
    C.datosConsumidos = randomRango(100, 500);
    C.baja = 0;

    return C;
}

/*****************************************
 * \brief CARGAR CONSUMOS RANDOM
 * \return VOID.
 *****************************************/

void cargaConsumoClienteRandom(){
    stCliente aux;
    char apellido[20];
    int cant;
    do{
        printf("\n\tIngrese el cliente paraa cargar el consumo: ");
        fflush(stdin);
        gets(apellido);
        aux = buscaUnClienteApellidoArchivo(apellido);
        if (aux.id >= 0){
            printf("\n\tIngrese cantidad de consumo a cargar: ");
            scanf("%d", &cant);
            cargaArchConsumoRandom(aux, cant);
        } else {
            printf("\n\tEl cliente no se encuentra en el archivo");
        }
    } while (aux.id == -1);
}

/*****************************************
 * \brief CARGAR CONSUMOS EN EL ARCHIVO
 * \return VOID.
 *****************************************/

void cargaArchConsumoRandom(stCliente cl, int cant){
    stConsumos C;
    for (int i = 0; i < cant; i++){
        C = cargaUnConsumo(cl.nroCliente);
        C.id = buscaUltimoIdConsumo() + 1;
        guardaUnConsumo(C);
    }
    system("cls");
}

/*****************************************
 * \brief GUARDA UN CONSUMO EN EL ARCHIVO.
 * \param CONSUMO.
 * \return VOID
 *****************************************/

void guardaUnConsumo(stConsumos C)
{
    FILE *pArchConsumo = fopen(AR_CONSUMO,"ab");
    if(pArchConsumo != NULL)
    {
        fwrite(&C,sizeof(stConsumos),1,pArchConsumo);
        fclose(pArchConsumo);
    }
}

/*************************
 * \brief MUESTRO CONSUMOS.
 * \param CONSUMO.
 * \return VOID
 *************************/

void muestraUnConsumo(stConsumos C)
{
    lineaMostrarHMedio();
    printf("\t    ID N%c %2d         ",167, C.id);
    lineaMostrarHMedio();
    printf("  ID de Cliente............: %d", C.idCliente);
    lineaMostrarHSep();
    printf("\n  Anio.....................: %d", C.anio);
    lineaMostrarHSep();
    printf("\n  Mes......................: %d", C.mes);
    lineaMostrarHSep();
    printf("\n  Dia......................: %d", C.dia);
    lineaMostrarHSep();
    printf("\n  Datos Consumidos.........: %d mb", C.datosConsumidos);
    lineaMostrarHSep();
    printf("\n  Baja.....................: %s", (C.baja)?"SI":"NO");
    lineaMostrarHMedio();
}

/*****************************************
 * \brief MUESTRA EL ARCHIVO DE CONSUMOS.
 * \return VOID.
 *****************************************/

void muestraArchConsumo () {

    stConsumos C;
    FILE *pArchConsumo = fopen(AR_CONSUMO,"rb");

    if (pArchConsumo) {
        while (fread(&C, sizeof(stConsumos), 1, pArchConsumo) > 0) {
            muestraUnConsumo(C);
        }
       fclose(pArchConsumo);
    }
    printf("\n");
}


