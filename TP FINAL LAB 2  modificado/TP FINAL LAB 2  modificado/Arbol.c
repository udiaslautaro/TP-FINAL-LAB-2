#include "Arbol.h"

/******************************
 * \brief INICIALIZAR UN ARBOL
 * \return NODO ARBOL.
 ******************************/

nodoArbol* inicArbol (){
    return NULL;
}

/******************************
 * \brief CREAR NODO ARBOL
 * \param STCLIENTE
 * \return NODO ARBOL.
 ******************************/

nodoArbol* crearNodoArbol (stCliente dato){
    nodoArbol* aux = (nodoArbol*) malloc(sizeof(nodoArbol));

    aux->dato = dato;
    aux->listaDeConsumos = inicLista();
    aux->der = NULL;
    aux->izq = NULL;

    return aux;
}

/**********************************
 * \brief AGREGAR UN NODO AL ARBOL
 * \param ARBOL
 * \param STCLIENTE
 * \return NODO ARBOL.
 **********************************/

nodoArbol* agregarArbol (nodoArbol* arbol, stCliente dato){
    if (arbol == NULL){
        arbol = crearNodoArbol(dato);
    } else{
        if (dato.nroCliente > arbol->dato.nroCliente){
            arbol->der = agregarArbol(arbol->der, dato);
        } else {
            arbol->izq = agregarArbol(arbol->izq, dato);
        }
    }
    return arbol;
}

/***********************
 * \brief MOSTRAR ARBOL
 * \param ARBOL
 * \return VOID.
 ***********************/

void preorder (nodoArbol* arbol){
    if(arbol!=NULL){
        printf("\n--------------------------------------------\n");
        printf("\n\t\t CLIENTE:\n");
        printf("NRO CLIENTE...: %d \n", arbol->dato.nroCliente);
        printf("NOMBRE........: %s \n", arbol->dato.nombre);
        printf("APELLIDO......: %s \n", arbol->dato.apellido);
        printf("DNI...........: %d \n", arbol->dato.dni);
        printf("\n--------------------------------------------\n");
        printf("\n\t\t CONSUMOS DEL CLIENTE:\n");
        muestraLista(arbol->listaDeConsumos);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

/********************************
 * \brief BUSCAR DATO EN EL ARBOL
 * \param ARBOL
 * \param STCLIENTE
 * \return NODO ARBOL.
 *********************************/

nodoArbol* buscarDatoArbol (nodoArbol* arbol, stCliente dato){
    nodoArbol* rta = NULL;
    if (arbol){
        if (dato.id == arbol->dato.id){
            rta = arbol;
        } else if (dato.id > arbol->dato.id){
            rta = buscarDatoArbol(arbol->der, dato);
        } else {
            rta = buscarDatoArbol(arbol->izq, dato);
        }
    }
    return rta;
}

/******************************************
 * \brief ALTA EN EL ARBOL DE LISTA
 * \param ARBOL
 * \param NUEVO CONSUMO
 * \param STCLIENTE
 * \return NODO ARBOL.
 ******************************************/

nodoArbol* alta (nodoArbol* arbol, nodo* nuevoConsumo, stCliente dato){
    nodoArbol* arbolEncontrado = buscarDatoArbol(arbol, dato);

    if (arbolEncontrado==NULL){
        arbol = agregarArbol(arbol, dato);
        arbol->listaDeConsumos= agregarAlFinal(arbol->listaDeConsumos, nuevoConsumo);
    } else {
        if (dato.id == arbol->dato.id){
            arbolEncontrado->listaDeConsumos = agregarAlFinal(arbolEncontrado->listaDeConsumos, nuevoConsumo);
        } else if (dato.id > arbol->dato.id) {
            arbol->der = alta(arbol->der, nuevoConsumo, dato);
        } else {
            arbol->izq = alta(arbol->izq, nuevoConsumo, dato);
        }
    }
    return arbol;
}

/****************************
 * \brief CUENTA NODOS
 * \param ARBOL
 * \return CANTIDAD DE NODOS.
 *****************************/

int cuentaNodos (nodoArbol* arbol){
    int cont=0;
    if (arbol){
        cont = 1 + cuentaNodos(arbol->der) + cuentaNodos(arbol->izq);
    }
    return cont;
}

/*******************
 * \brief NODO HOJA
 * \param ARBOL
 * \return BANDERA.
 *******************/

int nodoHoja (nodoArbol* arbol){
    int flag = 0;
    if (!arbol->der && !arbol->izq){
        flag = 1;
    }
    return flag;
}

/******************************************
 * \brief CANTIDAD DE NODOS TERMINALES
 * \param ARBOL
 * \return CANTIDAD.
 ******************************************/

int cuentaNodosTerminales (nodoArbol* arbol)
{
    int cont = 0;
    if (arbol){
        if (nodoHoja(arbol)){
            cont=1;
        } else {
            cont = cuentaNodosTerminales(arbol->der) + cuentaNodosTerminales(arbol->izq);
        }

    }
    return cont;
}

/************************
 * \brief RAMA MAYOR
 * \param NODO IZQUIERDO
 * \param NODO DERECHO
 * \return CANTIDAD.
 ***********************/

int ramaMayor (int izquierda, int derecha)
{
    int rta=0;
    if (izquierda>derecha){
        rta = izquierda;
    } else {
        rta = derecha;
    }
    return rta;
}

/****************************
 * \brief ALTURA DEL ARBOL
 * \param ARBOL
 * \return ALTURA.
 ***************************/

int alturaArbol (nodoArbol* arbol)
{
    int resp = 0;
    if (arbol){
        if (nodoHoja(arbol)){
            resp = 1;
        } else {
            resp = 1 + ramaMayor(alturaArbol(arbol->izq), alturaArbol(arbol->der));
        }
    }
    return resp;
}

/***************************
 * \brief NODO MAS DERECHO
 * \param ARBOL
 * \return NODO ARBOL.
 ***************************/

nodoArbol* nodoMasDerecha(nodoArbol *arbol){
   nodoArbol *aux;
   if(arbol->der==NULL){
      aux=arbol;
   }else{
      aux=nodoMasDerecha(arbol->der);
   }
   return aux;
}

/***************************
 * \brief NODO MAS IZQUIERDO
 * \param ARBOL
 * \return NODO ARBOL.
 ***************************/

nodoArbol* nodoMasIzquierda(nodoArbol *arbol){
   nodoArbol *aux;
   if(arbol->izq==NULL){
      aux=arbol;
   }else{
      aux=nodoMasIzquierda(arbol->izq);
   }
   return aux;
}

/***************************
 * \brief BORRAR NODO ARBOL
 * \param ARBOL
 * \param STCLIENTE
 * \return NODO ARBOL.
 ***************************/

nodoArbol* borrarNodoArbol(nodoArbol *arbol, stCliente dato)
{
   if(arbol!=NULL){
      if(dato.nroCliente > arbol->dato.nroCliente){
         arbol->der=borrarNodoArbol(arbol->der,dato);
      }else if(dato.nroCliente < arbol->dato.nroCliente){
         arbol->izq=borrarNodoArbol(arbol->izq,dato);
      }else{
         if(arbol->izq!=NULL){
            arbol->dato=(nodoMasDerecha(arbol->izq)->dato);
            arbol->izq=borrarNodoArbol(arbol->izq,arbol->dato);
         }else if(arbol->der!=NULL){
            arbol->dato=(nodoMasIzquierda(arbol->der)->dato);
            arbol->der=borrarNodoArbol(arbol->der,arbol->dato);
         }else{
            free(arbol);
            arbol=NULL;
         }
      }
   }
   return arbol;
}

/***************************
 * \brief MOSTRAR NODO ARBOL
 * \param ARBOL
 * \return VOID.
 ***************************/

void mostrarNodoArbol (nodoArbol* arbol){
    if(arbol!=NULL){
        printf("\n--------------------------------------------\n");
        printf("\n\t\t CLIENTE:\n");
        printf("NRO CLIENTE...: %d \n", arbol->dato.nroCliente);
        printf("NOMBRE........: %s \n", arbol->dato.nombre);
        printf("APELLIDO......: %s \n", arbol->dato.apellido);
        printf("DNI...........: %d \n", arbol->dato.dni);
        printf("\n--------------------------------------------\n");
        printf("\n\t\t CONSUMOS DEL CLIENTE:\n");
        muestraLista(arbol->listaDeConsumos);
        }
    }
