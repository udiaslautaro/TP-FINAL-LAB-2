#include "menu.h"


/************************************
 * \brief MENU DE CLIENTE - CONSUMO
 * \return VOID
 ************************************/

void menu() {

    gotoxy(5,5);
    lineaHSup();
    printf("\t%c\tMENU PRINCIPAL                                       %c",186,186);
    lineaHMedio();
    printf("\t%c\t[ 1 ] - CLIENTES.                                    %c",186,186);
    lineaHSep();
    printf("\n\t%c\t[ 2 ] - CONSUMO.                                     %c",186,186);
    lineaHInf();
}

/************************
 * \brief MENU DE CLIENTE
 * \return VOID
 ************************/

void menuClientes() {

    gotoxy(5,5);
    lineaHSup();
    printf("\t%c\tMENU DE CLIENTES                                     %c",186,186);
    lineaHMedio();
    printf("\t%c\t[ 1 ] - Alta.                                        %c",186,186);
    lineaHSep();
    printf("\n\t%c\t[ 2 ] - Baja.                                        %c",186,186);
    lineaHSep();
    printf("\n\t%c\t[ 3 ] - Modificacion.                                %c",186,186);
    lineaHSep();
    printf("\n\t%c\t[ 4 ] - Lista de clientes activos.                   %c",186,186);
    lineaHSep();
    printf("\n\t%c\t[ 5 ] - Listas de clientes inactivos.                %c",186,186);
    lineaHInf();
}

/************************
 * \brief MENU ALTA DE CLIENTE
 * \return VOID
 ************************/

void menuAltaCliente(){
    system("cls");
    gotoxy(5, 5);
    lineaHSup();
    printf("\t%c\t[ 1 ] - Carga un cliente manual                      %c",186,186);
    lineaHMedio();
    printf("\t%c\t[ 2 ] - Carga clientes random                        %c",186,186);
    lineaHMedio();
    printf("\t%c\t[ 3 ] - Muestra archivo de clientes                  %c",186,186);
    lineaHInf();
}

/************************
 * \brief MENU ORDEN DE CLIENTES
 * \return VOID
 ************************/

void menuOrden() {

    gotoxy(5,5);
    lineaHSup();
    printf("\t%c\tMENU DE ORDENAMIENTO ACTIVOS                         %c",186,186);
    lineaHMedio();
    printf("\t%c\t[ 1 ] - Ordenar por DNI.                             %c",186,186);
    lineaHSep();
    printf("\n\t%c\t[ 2 ] - Ordenar por Apellido.                        %c",186,186);
    lineaHSep();
    printf("\n\t%c\t[ 3 ] - Buscar cliente en particular y mostrarlo.    %c",186,186);
    lineaHInf();
}

/*************************
 * \brief MENU DE CONSUMO
 * \return VOID
 *************************/

void menuConsumo() {

    gotoxy(5,5);
    lineaHSup();
    printf("\t%c\tMENU DE CONSUMO                                      %c",186,186);
    lineaHMedio();
    printf("\t%c\t[ 1 ] - Alta de consumo.                             %c",186,186);
    lineaHSep();
    printf("\n\t%c\t[ 2 ] - Baja de consumo.                             %c",186,186);
    lineaHSep();
    printf("\n\t%c\t[ 3 ] - Modificacion de consumo.                     %c",186,186);
    lineaHSep();
    printf("\n\t%c\t[ 4 ] - Lista de consumo.                            %c",186,186);
    lineaHInf();
}

/******************************
 * \brief MENU CARGA DE CONSUMOS
 * \return VOID
 ******************************/

void menuCargaConsumo ()
{
    system("cls");
    gotoxy(5, 5);
    lineaHSup();
    printf("\t%c\t[ 1 ] - Carga un Consumo                             %c",186,186);
    lineaHSep();
    printf("\n\t%c\t[ 2 ] - Muestra archivo de Consumo                   %c",186,186);
    lineaHInf();
}

/******************************
 * \brief MENU DE LISTAS CONSUMOS
 * \return VOID
 ******************************/

void menuListarConsumos ()
{
    lineaHSup();
    printf("\t%c\t\t1) Listar consumos por fecha                 %c",186,186);
    lineaHMedio();
    printf("\t%c\t\t2) Listar consumos por Cliente               %c",186,186);
    lineaHMedio();
    printf("\t%c\t\t3) Listar consumos dados de baja             %c",186,186);
    lineaHMedio();
    printf("\t%c\t\t4) Buscar el mayor consumo                   %c",186,186);
    lineaHMedio();
    printf("\t%c\t\t5) Listar consumos por arbol                 %c",186,186);
    lineaHInf();
}

/**********************************************************
 * \brief MENU DE MODIFICACION DE CAMPOS DEL CLIENTE
 * \return VOID.
 **********************************************************/

void menuClienteAModificar ()
{
   lineaHSup();
   printf("\t%c\t\tSeleccione el campo que desea modificar:     %c",186,186);
   lineaHMedio();
   printf("\t%c\t\t[ 1 ] - Numero de cliente                    %c",186,186);
   lineaHSep();
   printf("\n\t%c\t\t[ 2 ] - Nombre                               %c",186,186);
   lineaHSep();
   printf("\n\t%c\t\t[ 3 ] - Apellido                             %c",186,186);
   lineaHSep();
   printf("\n\t%c\t\t[ 4 ] - DNI                                  %c",186,186);
   lineaHSep();
   printf("\n\t%c\t\t[ 5 ] - Email                                %c",186,186);
   lineaHSep();
   printf("\n\t%c\t\t[ 6 ] - Domicilio                            %c",186,186);
   lineaHSep();
   printf("\n\t%c\t\t[ 7 ] - Movil                                %c",186,186);
   lineaHInf();
   printf("\n");
}

/**********************************************************
 * \brief MENU DE MODIFICACION DE CAMPOS DE CONSUMOS
 * \return VOID.
 **********************************************************/

void menuConsumosAModificar ()
{
   lineaHSup();
   printf("\t%c\t\tSeleccione el campo que desea modificar:     %c",186,186);
   lineaHMedio();
   printf("\t%c\t\t[ 1 ] - Anio                                 %c",186,186);
   lineaHSep();
   printf("\n\t%c\t\t[ 2 ] - Mes                                  %c",186,186);
   lineaHSep();
   printf("\n\t%c\t\t[ 3 ] - Dia                                  %c",186,186);
   lineaHSep();
   printf("\n\t%c\t\t[ 4 ] - Datos Consumidos                     %c",186,186);
   lineaHInf();
   printf("\n");
}

/*************************
 * \brief LINEA SUPERIOR
 * \return VOID
 *************************/

void lineaHSup ()
{
    int i;

    printf("\n\t%c", 201);
    for (i = 15; i < 75; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n",187);
}

/*************************
 * \brief LINEA MEDIO
 * \return VOID
 *************************/

void lineaHMedio ()
{
    int i;

    printf("\n\t%c", 186);
    for (i = 15; i < 75; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n",186);
}

/*************************
 * \brief LINEA INFERIOR
 * \return VOID
 *************************/

void lineaHInf ()
{
    int i;

    printf("\n\t%c", 200);
    for (i = 15; i < 75; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n",188);
}

/*************************
 * \brief LINEA SEPARADORA
 * \return VOID
 *************************/

void lineaHSep ()
{
    int i;

    printf("\n\t%c",186);
    for (i = 16; i < 76; i++)
    {
        printf("%c", 196);
    }
    printf("%c",186);
}

/********************************
 * \brief LINEA MOSTRAR MEDIO
 * \return VOID
 ********************************/

void lineaMostrarHMedio ()
{
    int i;

    printf("\n");
    for (i = 15; i < 69; i++)
    {
        printf("%c", 205);
    }
    printf("\n");
}

/********************************
 * \brief LINEA MOSTRAR SEPARADORA
 * \return VOID
 ********************************/

void lineaMostrarHSep ()
{
    int i;

    printf("\n");
    for (i = 16; i < 70; i++)
    {
        printf("%c", 196);
    }
}
