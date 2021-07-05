#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "gotoxy.h"
#include "unCliente.h"
#include "variasClientes.h"
#include "pasajes.h"
#include "utilidades.h"
#include "unConsumo.h"
#include "variasConsumos.h"
#include "menu.h"
#include "Arbol.h"

#define ESC 27

#define DIM 1500

nodoArbol* pasarArchToArbol (char archivo[], nodoArbol* arbol);

int main()
{
    srand(time(NULL));
    int cantidad=0, vConsumo = 0, auxCons;
    char continuar = 's';
    char opcion;
    char apellido[20];
    stCliente cliente[DIM];
    stConsumos consumo[DIM];
    stCliente aux, modif;
    stConsumos auxMax, auxMin, auxBuscar;
    nodoArbol* arbolClientes = inicArbol();

    color(240);

    do
    {
        system("cls");

        menu();

        opcion = getch();
        system("cls");

        switch (opcion)
        {
        case '1': /// CLIENTES.

            do
            {
                system("cls");
                menuClientes();
                opcion = getch();
                system("cls");

                switch (opcion)
                {
                case '1': /// ALTA.

                    do
                    {
                        menuAltaCliente();
                        opcion = getch();
                        system("cls");

                        switch (opcion){
                        case '1': /// CARGAR UN CLIENTE MANUAL EN EL ARCHIVO
                            cargaArchivoClientesManual();
                            break;
                        case '2': /// CARGAR EN EL ARCHIVO UN CLIENTE RANDOM
                            printf("\n\tCantidad de clientes a cargar: ");
                            scanf("%d", &cantidad);
                            cargaArchivoClientesRandom(cantidad);
                            break;
                        case '3': /// MUESTRA ARCHIVO DE CLIENTES.
                            muestraArchCliente();
                            break;
                        }
                        system("pause");
                        printf("\nDesea seguir con ALTA DE CLIENTE? s/n\n");
                        fflush(stdin);
                        scanf("%c", &continuar);

                    } while (continuar == 's');
                    break;

                case '2': /// BAJA.

                    do
                    {
                        system("cls");

                        bajaCliente();

                        system("pause");
                        printf("\nDesea continuar con la BAJA DE CLIENTE? s/n\n");
                        fflush(stdin);
                        scanf("%c", &continuar);


                    } while (continuar == 's');

                    break;

                case '3': /// MODIFICACION DE CLIENTES.

                    do
                    {
                        system("cls");

                        printf("\n\tIngrese el apellido a buscar\n");
                        fflush(stdin);
                        gets(apellido);
                        aux = buscaUnClienteApellidoArchivo(apellido);


                        modif = clienteModificado(aux);
                        modificaRegistro(modif);

                        system("pause");

                        printf("\nDesea continuar con MODIFICACION DE CLIENTES? s/n\n");
                        fflush(stdin);
                        scanf("%c", &continuar);

                    } while (continuar == 's');

                    break;

                case '4': /// LISTAR CLIENTES ACTIVOS.

                    do
                    {
                        system("cls");

                        menuOrden();

                        opcion = getch();
                        system("cls");

                        switch (opcion)
                        {
                        case '1': /// MOSTRAR CLIENTES ORDENADOS POR DNI.
                            cantidad = arch2Arreglo(cliente, DIM);
                            ordPorSelDni(cliente, cantidad);
                            muestraClientes(cliente, cantidad);
                            break;

                        case '2': /// MOSTRAR CLIENTES ORDENADOS POR APELLIDO.
                            cantidad = arch2Arreglo(cliente, DIM);
                            ordPorSelApellido(cliente, cantidad);
                            muestraClientes(cliente, cantidad);
                            break;

                        case '3': /// BUSCAR CLIENTE Y MOSTRARLO.
                            printf("\n\tIngrese el apellido a buscar\n");
                            fflush(stdin);
                            gets(apellido);
                            aux = buscaUnClienteApellidoArchivo(apellido);
                            if (aux.id != -1){
                                muestraUnCliente(aux);
                            } else {
                                printf("\nEl cliente no existe en el archivo\n");
                            }
                            break;

                        }
                        system("pause");
                        printf("\nDesea continuar con LISTAR CLIENTES ACTIVOS? s/n\n");
                        fflush(stdin);
                        scanf("%c", &continuar);

                    } while (continuar == 's');

                    break;

                case '5': /// LISTAR CLIENTES INACTIVOS.

                    gotoxy(5, 5);
                    printf("\n\tSe muestra los clientes inactivos ordenados por email\n");

                    cantidad = archInactivos2Arreglo(cliente, DIM);
                    ordPorSelEmail(cliente, cantidad);
                    muestraClientes(cliente, cantidad);

                    break;

                }
                system("pause");
                printf("\nDesea continuar con MENU DE CLIENTES? s/n\n");
                fflush(stdin);
                scanf("%c", &continuar);

            } while (continuar == 's');

            break;

        case '2': /// CONSUMOS.

            do
            {
                system("cls");

                menuConsumo();

                opcion = getch();
                system("cls");

                switch (opcion)
                {
                case '1': /// CARGA MUESTRA DE CONSUMO

                    do
                    {
                        menuCargaConsumo();
                        opcion = getch();
                        system("cls");

                        switch(opcion)
                        {
                        case '1': /// CARGA ARCHIVO DE CONSUMO

                            cargaConsumoClienteRandom();

                            break;

                        case '2': /// MUESTRA ARCHIVO DE CONSUMO

                            muestraArchConsumo();

                            break;
                        }
                        system("pause");
                        printf("\nDesea continuar con la operacion de CARGA DE CONSUMO? s = si / n = no\n");
                        fflush(stdin);
                        scanf("%c", &continuar);

                    } while (continuar == 's');

                    break;

                case '2': /// BAJA DE CONSUMO.

                    bajaConsumo();

                    break;

                case '3': /// MODIFICACION DE CONSUMO.

                    do
                    {
                        system("cls");

                        modificacionConsumo();

                        system("pause");

                        printf("\nDesea continuar con MODIFICACION DE CONSUMOS? s/n\n");
                        fflush(stdin);
                        scanf("%c", &continuar);

                    } while (continuar == 's');

                    break;

                case '4': /// LISTAR CONSUMOS

                    do{
                        menuListarConsumos();
                        opcion=getch();
                        system("cls");

                        switch (opcion){

                            case '1': /// MUESTRA CONSUMOS ORDENADOS POR FECHA

                                vConsumo = arch2ArregloConsumos(consumo, DIM);
                                ordPorSelFecha(consumo, vConsumo);
                                muestraConsumos(consumo, vConsumo);
                                break;

                            case '2': /// MUESTRA CONSUMOS DE UN CLIENTE

                                do{
                                printf("\nIngrese el apellido del cliente: \n");
                                gets(apellido);
                                aux = buscaUnClienteApellidoArchivo(apellido);
                                vConsumo = arch2ArregloConsumosSegunID(consumo, DIM, aux.nroCliente);

                                if (aux.id != -1)
                                {

                                    muestraConsumos(consumo, vConsumo);
                                }
                                else
                                {
                                    printf("\nEl cliente no existe en el archivo\n");
                                }
                                printf("\nDesea buscar otro cliente? s/n \n");
                                opcion = getch();
                                } while (opcion == 's');
                                break;

                            case '3': /// MUESTRA CONSUMOS DADOS DE BAJA
                                vConsumo = arch2ArregloConsumosBaja(consumo, DIM);
                                printf("\nLos consumos dados de baja son: \n");
                                muestraConsumos(consumo, vConsumo);
                                break;

                           case '4': /// MUESTRA EL PERIODO CON MAYOR CONSUMO DE UN CLIENTE

                                    do{
                                    printf("\nIngrese el apellido del cliente: \n");
                                    gets(apellido);
                                    aux = buscaUnClienteApellidoArchivo(apellido);
                                    if (aux.id != -1)
                                    {
                                        vConsumo = arch2ArregloConsumosSegunID(consumo, DIM, aux.nroCliente);
                                        auxMax = buscarMaximo(consumo, vConsumo);
                                        auxMin = buscarMinimo(consumo, vConsumo);
                                        system("cls");
                                        printf("\nEl mayor consumo del cliente es: \n");
                                        muestraUnConsumo(auxMax);
                                        printf("\nEl menor consumo del cliente es: \n");
                                        muestraUnConsumo(auxMin);
                                    } else {
                                        printf("\nEl cliente no existe. Ingrese nuevamente\n");
                                    }
                                    printf("\nDesea buscar otro cliente? s/n \n");
                                    opcion = getch();
                                    system("cls");
                                    } while (opcion == 's');
                                break;

                           case '5': /// PROBANDO FUNCION DE ARBOL DE CLIENTES
                                    do{
                                        stCliente auxCli;
                                        nodoArbol* adl=inicArbol();
                                        nodoArbol* adlAux= inicArbol();
                                        adl=pasarArchToArbol(AR_CONSUMO, adl);
                                        printf("\nIngrese el ID del cliente que desea buscar: \n");
                                        scanf("%d", &auxCli.id);
                                        if (auxCli.id>=0){
                                            adlAux=adl;
                                            adlAux=buscarDatoArbol(adl, auxCli);
                                            mostrarNodoArbol(adl);
                                        } else {
                                            printf("\nEl ID del consumo ingresado no existe\n");
                                        }
                                        printf("\nDesea buscar otro cliente? s/n \n");
                                        opcion = getch();
                                    } while (opcion == 's');
                                    break;
                        }
                        system("pause");

                        printf("\nDesea continuar con LISTAR CONSUMOS? s/n\n");
                        fflush(stdin);
                        scanf("%c", &continuar);

                    } while (continuar == 's');
                    break;
                }
                system("pause");
                printf("\nDesea continuar con la operacion de Consumo??\n");
                fflush(stdin);
                scanf("%c", &continuar);
                system("cls");
            } while (continuar == 's');
            break;
        }
        system("pause");
        printf("\nDesea volver al MENU PRINCIPAL? s = si / n = no\n");
        fflush(stdin);
        scanf("%c", &continuar);

    } while (continuar == 's');

    return 0;

}


nodoArbol* pasarArchToArbol (char archivo[], nodoArbol* arbol){
    FILE *pArchConsumos = fopen(archivo, "rb");

    if (pArchConsumos){
        stConsumos aux;
        stCliente clienteAux;
        while (fread(&aux, sizeof(stConsumos), 1, pArchConsumos)>0){
            clienteAux = buscaUnClientePorID(aux.idCliente);
            nodo* cons = crearNodo(aux);
            arbol = alta(arbol, cons , clienteAux);
        }
        fclose(pArchConsumos);
    }
    return arbol;
}
