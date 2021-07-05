#include "variasConsumos.h"

/*************************************
 * \brief BUSCA ULTIMO ID CONSUMO.
 * \return ID.
 *************************************/

int buscaUltimoIdConsumo()
{
    stConsumos C;
    int id = -1;

    FILE *pArchConsumo = fopen(AR_CONSUMO,"rb");

    if(pArchConsumo)
    {
        fseek(pArchConsumo, sizeof (stConsumos)*(-1), SEEK_END);

        if(fread(&C,sizeof(stConsumos),1,pArchConsumo) > 0)
        {
            id = C.id;
        }
        fclose(pArchConsumo);
    }
    return id;
}

/*************************************
 * \brief BUSCA CONSUMO POR FECHA.
 * \param AÑO.
 * \param MES.
 * \param DIA.
 * \return CONSUMO.
 *************************************/

stConsumos buscaUnConsumoFechaArchivo(int year, int mounth, int day)
{
    stConsumos C;
    int flag=0;

    FILE *pArchConsumo = fopen(AR_CONSUMO,"rb");

    if(pArchConsumo){
        while( flag == 0 && fread(&C, sizeof(stConsumos), 1, pArchConsumo) > 0){
            if(C.anio == year && C.mes == mounth && C.dia == day){
                flag=1;
            }
        }
        fclose(pArchConsumo);
    }

    if(flag==0){
        C.id = -1;
    }

    return C;
}

/*************************************
 * \brief DAR DE BAJA CONSUMO.
 * \return VOID.
 *************************************/

void bajaConsumo ()
{
    stConsumos  aux;

    int year;
    int mounth;
    int day;

    char continuar;

    printf("\n\tIngrese el anio de consumo\n");
    scanf("%d", &year);

    printf("\n\tIngrese el mes de consumo\n");
    scanf("%d", &mounth);

    printf("\n\tIngrese el dia de consumo\n");
    scanf("%d", &day);

    aux = buscaUnConsumoFechaArchivo(year, mounth, day);

    if (aux.id != -1){
        printf("\nEl Consumo existe en el archivo\n");
        muestraUnConsumo(aux);
        printf("\nDesea dar de baja al Consumo? s/n \n");
        fflush(stdin);
        scanf("%c", &continuar);
    } else{
        printf("\nEl Consumo no existe en el archivo\n");
    }

    if (continuar == 's'){
        aux.baja = 1;
        muestraUnConsumo(aux);
        modificaRegistroCosumo(aux);
    }
}

/**********************************************************
 * \brief MODIFICAR UN CAMPO DEL CONSUMO
 * \param CONSUMO A MODIFICAR
 * \return CONSUMO MODIFICADO.
 **********************************************************/

stConsumos consumoModificado (stConsumos C)
{
    int opcion;
    char continuar;
    stConsumos d;
    menuConsumosAModificar();
    scanf("%d", &opcion);

    do {
        switch (opcion){
        case 1:
            printf("\nIngrese el Anio a modificar: ");
            scanf("%d", &d.anio);
            C.anio = d.anio;
            break;
        case 2:
            printf("\nIngrese el mes a modificar: ");
            scanf("%d", &d.mes);
            C.mes = d.mes;
            break;
        case 3:
            printf("\nIngrese el dia a modificar: ");
            scanf("%d", &d.dia);
            C.dia = d.dia;
            break;
        case 4:
            printf("\nIngrese el dato a consumir: ");
            scanf("%d", &d.datosConsumidos);
            C.datosConsumidos = d.datosConsumidos;
            break;
        }

    system("pause");
    printf("\nDesea continuar? s = si / n = no\n");
    fflush(stdin);
    scanf("%c", &continuar);

    } while (continuar == 's');

    return C;
}

/*************************************************
 * \brief BUSCAR POSICION DEL CONSUMO A MODIFICAR.
 * \param ID
 * \return POS.
 *************************************************/

int buscaPosConsumo(int id)
{
    int pos = -1;
    stConsumos C;
    FILE *pArchCconsumo = fopen(AR_CLIENTES, "rb");
    if(pArchCconsumo){
        while(pos==-1 && fread(&C, sizeof(stConsumos), 1, pArchCconsumo) > 0){
            if(C.id == id){
                pos = ftell(pArchCconsumo)/sizeof(stConsumos)-1;
            }
        }
        fclose(pArchCconsumo);
    }

    return pos;
}

/*************************************************
 * \brief MODIFICACION DEL CONSUMO.
 * \return VOID.
 *************************************************/

void modificacionConsumo ()
{
    int year, mounth, day;
    stConsumos auxC, modifC;

    printf("\n\tIngrese el anio de consumo\n");
    scanf("%d", &year);

    printf("\n\tIngrese el mes de consumo\n");
    scanf("%d", &mounth);

    printf("\n\tIngrese el dia de consumo\n");
    scanf("%d", &day);

    auxC = buscaUnConsumoFechaArchivo(year, mounth, day);

    if (auxC.id >= 0){
        modifC = consumoModificado(auxC);
        modificaRegistroCosumo(modifC);
        } else {
            printf("\nLa fecha es incorrecta. Ingrese nuevamente\n");
        }
}

/***********************************************
 * \brief MODIFICAR EL REGISTRO DE CONSUMOS
 * \param CONSUMO MODIFICADO
 * \return VOID
 **********************************************/

void modificaRegistroCosumo(stConsumos C)
{
    int pos = 0;

    pos = buscaPosConsumo(C.id);

    FILE *pArchConsumo = fopen(AR_CONSUMO, "r+b");
    if(pArchConsumo){
        fseek(pArchConsumo, sizeof(stConsumos)*pos, SEEK_SET);
        fwrite(&C, sizeof(stConsumos), 1, pArchConsumo);
        fclose(pArchConsumo);
    }
}

/*********************************
 * \brief MUESTRO CONSUMOS.
 * \param ARREGLO DE CONSUMOS
 * \param VALIDOS
 * \return VOID
 ********************************/

void muestraConsumos (stConsumos c[], int v)
{
    printf("\n\tListado de Consumos: \n");

    for (int i = 0; i < v; i++)
    {
        muestraUnConsumo(c[i]);
    }
    printf("\n");
}

/*****************************************
 * \brief BUSCA POSICION DEL MENOR SEGUN FECHA
 * \param ARREGLO DE CONSUMOS
 * \param VALIDOS
 * \param INICIO DEL ARREGLO
 * \return POSMENOR.
 *****************************************/

int buscaPosMenorFecha(stConsumos c[], int v, int inicio){
    int posMenor = inicio;
    int i = inicio + 1;
    while(i<v){
        if (c[i].anio < c[posMenor].anio){
                posMenor=i;
        }else {
            if (c[i].anio == c[posMenor].anio){
                if (c[i].mes< c[posMenor].mes){
                    posMenor=i;
                } else{
                    if(c[i].mes == c[posMenor].mes){
                        if (c[i].dia <= c[posMenor].dia){
                            posMenor=i;
                        }
                    }
                }
            }
        }

        i++;
    }
    return posMenor;
}

/*****************************************
 * \brief INTERCAMBIA CONSUMOS
 * \param CONSUMO
 * \param CONSUMO
 * \return VOID.
 *****************************************/

void intercambiaConsumos(stConsumos *a, stConsumos *b){
    stConsumos aux;
    aux=*a;
    *a=*b;
    *b=aux;
}

/******************************************
 * \brief ORDENAR POR SELECCION EL ARREGLO
 * \param ARREGLO CONSUMOS
 * \param VALIDOS
 * \return VOID.
 ******************************************/

void ordPorSelFecha (stConsumos c[], int v){
    int posMenor;
    int i=0;

    while(i<v-1){
        posMenor=buscaPosMenorFecha(c,v,i);
        intercambiaConsumos(&c[i],&c[posMenor]);
        i++;
    }
}

/*************************************
 * \brief BUSCAR MAXIMO DE UN ARREGLO.
 * \param ARREGLO CONSUMOS
 * \param VALIDOS
 * \return CONSUMO MAXIMO.
 ************************************/

stConsumos buscarMaximo (stConsumos A[], int validos)
{
    int i=0;
    stConsumos maximo;
    maximo = A[i];

    for (i=1; i<validos; i++) {
        if (maximo.datosConsumidos <= A[i].datosConsumidos) {
            maximo = A[i];
        }
    }
    return maximo;
}

/*************************************
 * \brief BUSCAR MINIMO DE UN ARREGLO.
 * \param ARREGLO CONSUMOS
 * \param VALIDOS
 * \return CONSUMO MINIMO
 ************************************/

stConsumos buscarMinimo (stConsumos A[], int validos)
{
    int i=0;
    stConsumos minimo;
    minimo = A[i];

    for (i=1; i<validos; i++) {
        if (minimo.datosConsumidos >= A[i].datosConsumidos) {
            minimo = A[i];
        }
    }
    return minimo;
}

/*******************************
 * \brief BUSCAR CONSUMO POR ID
 * \param ID CONSUMO
 * \return STCONSUMOS
 ******************************/

stConsumos buscaConsumoPorID(int idConsumo)
{
    stConsumos c;
    int flag=0;

    FILE *pArchConsumo = fopen(AR_CONSUMO,"rb");

    if(pArchConsumo){
        while( flag == 0 && fread(&c, sizeof(stConsumos), 1, pArchConsumo) > 0){
            if(c.id == idConsumo){
                flag=1;
            }
        }
        fclose(pArchConsumo);
    }
    if(flag==0){
        c.id = -1;
    }
    return c;
}
