#include "utilidades.h"

/***********************************
 * \brief RANGOS ALEATORIOS.
 * \param ENTERO MIN.
 * \param ENTERO MAX.
 * \return RANDOM.
 ***********************************/

int randomRango(int min, int max)
{
    return rand() %( max - min) + min;
}

/********************************
 * \brief VALIDACION DE FECHA
 * \param Dia
 * \param Mes
 * \param Anio
 * \return FLAG
 ********************************/

int validacFecha(int anio, int mes, int dia)
{
    int flag=0;

    if ( mes >= 1 && mes <= 12 )
    {
        switch ( mes )
        {
        case  1 :
        case  3 :
        case  5 :
        case  7 :
        case  8 :
        case 10 :
        case 12 :

            if ( dia >= 1 && dia <= 31 )
            {
                flag = 1;
            }

            break;

        case  4 :
        case  6 :
        case  9 :
        case 11 :

            if ( dia >= 1 && dia <= 30 )
            {
                flag = 1;
            }
            break;

        case  2 :
            if ( anio % 4 == 0 || anio % 100 != 0 || anio % 400 == 0 )
            {
                if ( dia >= 1 && dia <= 29 )
                {
                    flag = 1;
                }
            }
            else if ( dia >= 1 && dia <= 28 )
            {
                flag = 1;
            }
        }
    }
    return flag;
}

/**************************************
 * \brief MUESTRA NOMBRES DE CLIENTES.
 * \return VOID.
 **************************************/

void getNombre(char n[])
{
    char nombres[][30] = {"Carolina","Daiana","Cynthia","Zeljko","Juan","Roberto","Antonio","Fernando","Anibal","Mariano","Jose",
                          "Carlito","Genga","Mario","Claribel","Adolfo","Pedro","Alfredo","Arnaldo",
                          "Mauro","Benicio","Riquelme","Dai","Anchelo","Miguel","Palermo"
                         };

    strcpy(n,nombres[randomRango(0,sizeof(nombres)/(sizeof(char)*30))]);
}

/**************************************
 * \brief MUESTRA APELLIDO DE CLIENTES.
 * \return VOID.
 **************************************/

void getApellido(char a[])
{
    char apellidos[][30] = {"Bilhere","Gomez","Perez","Rodriguez","Latorre","Fernandez","Torquemada", "Marijuan", "Roca", "Mitre", "Rivadavia",
                            "SanMartin", "Alvarez", "Comizo", "Borges", "Zama", "Recato", "Olvido", "Gil", "Trapero", "Restinga",
                            "DeAntonio", "Ramirez", "Spinetta", "Cortez", "Gonzalez", "Andujar", "Osvaldo", "Bautista", "Anchorena", "Menem",
                            "Gaboto","Vega","Vargas","Lloret","Linares","Suarez","Sierra","Amenabar","Blanco","White","Ortega"
                           };

    strcpy(a,apellidos[randomRango(0,sizeof(apellidos)/(sizeof(char)*30))]);
}

/**************************************
 * \brief MUESTRA DOMICILIOS DE CLIENTES.
 * \return VOID.
 **************************************/

void getCalle(char c[])
{
    char calles[][30] = {"San Juan","Funes","Gaboto","San Martin","Colon","Rivadavia", "Alsina", "Roca", "Mitre", "Belgrano",
                         "Paso", "11 de Septiembre", "3 de Febrero", "Balcarce", "Libertad", "Magallanes", "Irala", "Ayolas", "Moreno", "Brown",
                         "Bolivar", "Alberti", "Gascon", "La Rioja", "Catamarca", "Salta", "Jujuy", "XX de Septiembre", "14 de Julio", "Dorrego",
                         "Hernandarias","Don Orione","Juramento","Lanzilota","Estrada","Tierra del Fuego","Mendoza","Chubut","Rio Negro","Misiones","Edison"
                        };

    strcpy(c,calles[randomRango(0,sizeof(calles)/(sizeof(char)*30))]);
}

/**************************************************
 * \brief MUESTRA NUMERO DE DOMICILIO DE CLIENTES.
 * \return VOID.
 **************************************************/

int getCalleNro()
{
    return randomRango(50,10000);
}
