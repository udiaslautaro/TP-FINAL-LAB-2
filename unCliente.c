#include "unCliente.h"
#include "variasClientes.h"

/***************************************
 * \brief CARGA UN SOLO CLIENTE RANDOM
 * \return VOID
 ***************************************/

stCliente cargaUnCliente()
{
    stCliente c;

    printf("\n Cliente cargado\n");

    c.nroCliente = randomRango(0,100);

    fflush(stdin);
    getNombre(c.nombre);

    fflush(stdin);
    getApellido(c.apellido);

    c.dni = randomRango(30000000, 50000000);

    fflush(stdin);
    strcpy(c.email, c.nombre);
    strcat(c.email, "_");
    strcat(c.email, c.apellido);
    strcat(c.email, "@gmail.com");

    fflush(stdin);
    getCalle(c.domicilio);
    strcat(c.domicilio, " ");
    char nro[4];
    strcat(c.domicilio, itoa(getCalleNro(), nro, 10));

    c.movil = randomRango(150000000, 159999999);

    c.baja = 0;

    return c;
}

/************************************
    * \brief CARGA CLIENTES RANDOM
    * \param STCLIENTES.
    * \param VALIDOS
    * \param DIMENSION
    * \return VALIDOS.
************************************/

int cargaClientesArregloRandom(stCliente c[], int v, int dim){
    char continuar = 's';
    int i = 0;
    do{
        printf("\n\tCliente: %d", i);
        i++;
        c[v]=cargaUnCliente();
        v++;
        printf("\n\tDesea continuar? [SI - NO]");
        continuar=getch();
    } while(continuar=='s');
    return v;
}

/**************************************************
    * \brief CARGA EL CLIENTE EN EL ARCHIVO RANDOM.
    * \param CANTIDAD DE ELEMENTOS A CARGAR.
    * \return VOID.
**************************************************/

void cargaArchivoClientesRandom(int cant){
    stCliente c;
    int i;
    for (i = 0; i < cant; i++){
        c = cargaUnCliente();
        c.id = buscaUltimoId() + 1;
        guardaUnCliente(c);
    }
}

/***************************************
 * \brief CARGA UN SOLO CLIENTE MANUAL
 * \return VOID
 ***************************************/

stCliente cargaUnClienteManual()
{
    stCliente c;

    do{
        printf("\n Ingrese el nro de Cliente..........: ");
        scanf("%d", &c.nroCliente);
    }
    while(c.nroCliente<0 || c.nroCliente>9999999);

    printf(" Ingrese el Nombre..................: ");
    fflush(stdin);
    gets(c.nombre);

    printf(" Ingrese el Apellido................: ");
    fflush(stdin);
    gets(c.apellido);

    printf(" Ingrese el DNI.....................: ");
    scanf("%d", &c.dni);

    do{
        printf(" Ingrese el EMail...................: ");
        fflush(stdin);
        gets(c.email);
    }while(!validaEmail(c.email));

    printf(" Ingrese el Domicilio...................: ");
    fflush(stdin);
    gets(c.domicilio);

    printf(" Ingrese el Numero de celular...........: ");
    scanf("%d", &c.movil);

    c.baja=0;

    return c;
}


/***********************************************
 * \brief CARGA EL CLIENTE EN EL ARCHIVO MANUAL.
 * \return VOID.
 ***********************************************/

void cargaArchivoClientesManual()
{
    char continuar = 's';
    stCliente c;
    while(continuar == 's')
    {
        system("cls");
        printf("\n Carga de Clientes \n");

        c = cargaUnClienteManual();

        c.id = buscaUltimoId() + 1;
        guardaUnCliente(c);

        printf("\nDesea continuar con la carga? s = si / n = no\n");
        fflush(stdin);
        scanf("%c", &continuar);
    }
}

/*************************
 * \brief MUESTRO CLIENTE.
 * \return VOID
 *************************/

void muestraUnCliente(stCliente c)
{
    lineaMostrarHMedio();
    printf("\t  ID N%c %d         ",167, c.id);
    lineaMostrarHMedio();
    printf("  Nro de Cliente..........: %d", c.nroCliente);
    lineaMostrarHSep();
    printf("\n  Nombre..................: %s", c.nombre);
    lineaMostrarHSep();
    printf("\n  Apellido................: %s", c.apellido);
    lineaMostrarHSep();
    printf("\n  DNI.....................: %d", c.dni);
    lineaMostrarHSep();
    printf("\n  EMail...................: %s", c.email);
    lineaMostrarHSep();
    printf("\n  Calle...................: %s", c.domicilio);
    lineaMostrarHSep();
    printf("\n  Nro de Celular..........: %d", c.movil);
    lineaMostrarHSep();
    printf("\n  Baja s/n................: %s", (c.baja)?"SI":"NO");
    lineaMostrarHMedio();
}

/*****************************************
 * \brief MUESTRA UN ARREGLO DE CLIENTES
 * \param ARREGLO DE CLIENTES
 * \param VALIDOS
 * \return VOID.
 *****************************************/

void muestraClientes(stCliente c[], int v){
    printf("\n\t\t Listado de Clientes");
    for(int i=0;i<v;i++){
        muestraUnCliente(c[i]);
    }
    printf("\n");
}
