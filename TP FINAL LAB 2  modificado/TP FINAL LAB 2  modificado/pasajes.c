#include "pasajes.h"

/******************************************
 * \brief PASAR DE UN ARCHIVO A UN ARREGLO
 * \param ARCHIVO DE CLIENTES
 * \param DIMENSION DEL ARCHIVO
 * \return VALIDOS.
 ******************************************/

int arch2Arreglo(stCliente c[], int dimension){
    stCliente cl;
    int i=0;
    FILE *pArchClientes = fopen(AR_CLIENTES, "rb");
    if(pArchClientes){
        while(fread(&cl, sizeof(stCliente), 1, pArchClientes) > 0){
            if(cl.baja==0){
                c[i] = cl;
                i++;
            }
        }
        fclose(pArchClientes);
    }
    return i;
}

/**********************************************************
 * \brief PASAR DE UN ARCHIVO A UN ARREGLO LOS INACTIVOS
 * \param ARCHIVO DE CLIENTES
 * \param DIMENSION DEL ARCHIVO
 * \return VALIDOS.
 **********************************************************/

int archInactivos2Arreglo(stCliente c[], int dimension)
{
    stCliente cl;
    int i=0;
    FILE *pArchClientes = fopen(AR_CLIENTES, "rb");
    if(pArchClientes){
        while(fread(&cl, sizeof(stCliente), 1, pArchClientes) > 0){
            if(cl.baja==1){
                c[i] = cl;
                i++;
            }
        }
        fclose(pArchClientes);
    }
    return i;
}


/***********************************************************
 * \brief PASA DEL ARCHIVO AL ARREGLO DE CONSUMOS ACTIVOS
 * \param ARREGLO DE CONSUMOS
 * \param DIMENSION
 * \return VALIDOS.
 **********************************************************/

int arch2ArregloConsumos(stConsumos c[], int dimension)
{
    stConsumos cl;
    int i=0;
    FILE *pArchConsumos = fopen(AR_CONSUMO, "rb");
    if(pArchConsumos){
        while(fread(&cl, sizeof(stConsumos), 1, pArchConsumos) > 0){
            if(cl.baja==0){
                c[i] = cl;
                i++;
            }
        }
        fclose(pArchConsumos);
    }
    return i;
}

/***********************************************************
 * \brief PASA DEL ARCHIVO AL ARREGLO DE CONSUMOS SEGUN ID
 * \param ARREGLO DE CONSUMOS
 * \param DIMENSION DEL ARREGLO
 * \param NRO DE CLIENTE
 * \return VALIDOS
 **********************************************************/

int arch2ArregloConsumosSegunID(stConsumos c[], int dimension, int nroCl)
{
    stConsumos cl;
    int i=0;
    FILE *pArchConsumos = fopen(AR_CONSUMO, "rb");
    if(pArchConsumos){
        while(fread(&cl, sizeof(stConsumos), 1, pArchConsumos) > 0){
            if(cl.idCliente==nroCl){
                c[i] = cl;
                i++;
            }
        }
        fclose(pArchConsumos);
    }
    return i;
}

/***********************************************************
 * \brief PASA DEL ARCHIVO AL ARREGLO DE CONSUMOS INACTIVOS
 * \param ARREGLO DE CONSUMOS
 * \param DIMENSION DEL ARREGLO
 * \return VALIDOS
 **********************************************************/

int arch2ArregloConsumosBaja(stConsumos c[], int dimension)
{
    stConsumos cl;
    int i=0;
    FILE *pArchConsumos = fopen(AR_CONSUMO, "rb");
    if(pArchConsumos){
        while(fread(&cl, sizeof(stConsumos), 1, pArchConsumos) > 0){
            if(cl.baja==1){
                c[i] = cl;
                i++;
            }
        }
        fclose(pArchConsumos);
    }
    return i;
}

/*************************************************
 * \brief PASAR DE UN REGISTRO A OTRO.
 * \return VOID.
 *************************************************/

 void registroToRegistro ()
 {
    stCliente c;
    FILE *pArchClientes = fopen(AR_CLIENTES, "rb");
    FILE *pArchCliActivos = fopen(AR_ACTIVOS, "wb");
    FILE *pArchCliBaja = fopen(AR_INACTIVOS, "wb");
    if(pArchClientes && pArchCliActivos && pArchCliBaja){
        while(fread(&c, sizeof(stCliente), 1, pArchClientes) > 0){
            if(c.baja == 1){
                fwrite(&c, sizeof(stCliente), 1, pArchCliBaja);
            }
            else{
                fwrite(&c, sizeof(stCliente), 1, pArchCliActivos);
            }
        }
        fclose(pArchClientes);
        fclose(pArchCliActivos);
        fclose(pArchCliBaja);
    }
 }
