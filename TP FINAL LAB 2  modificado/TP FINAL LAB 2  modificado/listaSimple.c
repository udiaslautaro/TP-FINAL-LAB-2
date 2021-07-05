#include "listaSimple.h"

/***************************
 * \brief INICILIAZAR LISTA
 * \return NODO.
 ***************************/

nodo* inicLista(){
    return NULL;
}

/***************************
 * \brief CREAR NODO LISTA
 * \param STCONSUMOS
 * \return NODO.
 ***************************/

nodo* crearNodo(stConsumos dato){
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    return nuevo;
}

/*******************************************
 * \brief AGREGAR AL PRINCIPIO DE LA LISTA
 * \param LISTA
 * \param NUEVO NODO
 * \return NODO.
 ******************************************/

nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo){
    if(lista==NULL){
        lista = nuevoNodo;
    }else{
        nuevoNodo->sig = lista;
        lista = nuevoNodo;
    }
    return lista;
}

/***************************
 * \brief MUESTRA NODO
 * \param NODO
 * \return VOID
 ***************************/

void muestraNodo(nodo *nodo){
    printf("\n nodo: %p - nodo->siguiente: %p\n",  nodo, nodo->sig);
    muestraUnConsumo(nodo->dato);
}

/***************************
 * \brief MUESTRA LISTA
 * \param LISTA
 * \return VOID
 ***************************/

void muestraLista(nodo* lista){
    nodo* seg = lista;
    while(seg){
        muestraNodo(seg);
        seg = seg->sig;
    }
}

/***************************
 * \brief BUSCAR ULTIMO NODO
 * \param LISTA
 * \return NODO.
 ***************************/

nodo* buscarUltimo(nodo* lista){
    nodo* seg = lista;
    while(seg->sig!=NULL){
        seg = seg->sig;
    }
    return seg;
}

/***************************
 * \brief AGREGAR AL FINAL
 * \param LISTA
 * \param NUEVO NODO
 * \return NODO.
 ***************************/

nodo* agregarAlFinal(nodo* lista, nodo* nuevo){
    if(lista==NULL){
        lista = nuevo;
    }else{
        nodo* ultimo = buscarUltimo(lista);
        ultimo->sig = nuevo;
    }
    return lista;
}

/***************************
 * \brief VER PRIMER NODO
 * \param LISTA
 * \return STCONSUMOS
 ***************************/

stConsumos verPrimero(nodo* lista){
    return lista->dato;
}

