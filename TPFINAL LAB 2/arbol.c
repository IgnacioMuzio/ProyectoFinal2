#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include "string.h"



nodoArbolCanc * inicArbol()
{
    return NULL;
}



nodoArbolCanc * crearNodoArbol (stCancion dato)
{
    nodoArbolCanc * aux = (nodoArbolCanc*)malloc(sizeof(nodoArbolCanc));

    aux->c = dato;
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}



nodoArbolCanc * insertarNodoArbol (nodoArbolCanc * arbol, stCancion dato)
{
    if(arbol == NULL)
    {
        arbol = crearNodoArbol(dato);
    }
    else
    {
        if(dato.id > arbol->c.id)
        {
            arbol->der = insertarNodoArbol(arbol->der, dato);
        }
        else
        {
            arbol->izq = insertarNodoArbol(arbol->izq, dato);
        }
    }

    return arbol;
}



void preOrden (nodoArbolCanc * arbol)
{
    if(arbol)
    {
        mostrarCancion(arbol->c);
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}



void inOrder (nodoArbolCanc * arbol)
{
    if(arbol != NULL)
    {
        inOrder(arbol->izq);
        mostrarCancion(arbol->c);
        inOrder(arbol->der);
    }
}



void postOrden (nodoArbolCanc * arbol)
{
    if(arbol != NULL)
    {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        mostrarCancion(arbol->c);
    }
}



void mostrarCancion (stCancion dato)
{
    printf("ID:%d\n",dato.id);
    printf("NOMBRE DE CANCION: %s\n",dato.nombre);
    printf("ANIO:%d\n",dato.anio);
    printf("GENERO:%s\n",dato.genero);
    printf("CANTANTES/BANDA:%s\n",dato.cantantes);
    printf("ESTADO:%d\n",dato.estado);
    printf("--------------------------------------------------------\n");
}



nodoArbolCanc* borrarUnNodoArbolPorId(nodoArbolCanc* arbol, int ID)
{
    if(arbol!=NULL)
    {
        if(ID > arbol->c.id)
        {
            arbol->der = borrarUnNodoArbolPorId(arbol->der, ID);
        }
        else if (ID < arbol->c.id)
        {
            arbol->izq = borrarUnNodoArbolPorId(arbol->izq, ID);
        }
        else if (ID == arbol->c.id)
        {
            if(esHoja(arbol))
            {
                free(arbol);
                arbol = NULL;
            }
            else if(esGrado1(arbol))
            {
                nodoArbolCanc* aux;
                if (arbol->der)
                {
                    aux = arbol;
                    arbol = arbol->der;
                    free(aux);
                }
                else
                {
                    aux = arbol;
                    arbol = arbol->izq;
                    free(aux);
                }
            }
            else
            {
                nodoArbolCanc* masDer = nodoMasDerecha(arbol->izq);
                arbol->c = masDer->c;
                arbol->izq = borrarUnNodoArbolPorId(arbol->izq, arbol->c.id);
            }
        }
    }

    return arbol;
}



nodoArbolCanc * nodoMasIzquierda(nodoArbolCanc * arbol)
{
    if(arbol)
    {
        if(arbol->izq != NULL)
        {
            arbol = nodoMasIzquierda(arbol->izq);
        }
    }
    return arbol;
}



nodoArbolCanc * nodoMasDerecha(nodoArbolCanc* arbol)
{
    if(arbol)
    {
        if(arbol->der != NULL)
        {
            arbol = nodoMasDerecha(arbol->der);
        }
    }
    return arbol;
}



int esHoja(nodoArbolCanc * arbol)
{
    int rta=0;

    if(arbol)
    {
        if(arbol->izq ==NULL && arbol->der == NULL)
        {
            rta=1;
        }
    }
    return rta;
}



int esGrado1(nodoArbolCanc * arbol)
{
    int rta=0;

    if(arbol)
    {
        if( (arbol->izq == NULL && arbol->der != NULL) || (arbol->izq != NULL && arbol->der == NULL) )
        {
            rta=1;
        }
    }
    return rta;
}



nodoArbolCanc * buscarCancionPorId (nodoArbolCanc * arbol, int ID)
{
    nodoArbolCanc * rta = NULL;

    if(arbol != NULL)
    {
        if(ID == arbol->c.id)
        {
            rta = arbol;
        }
        else
        {
            if(ID > arbol->c.id)
            {
                rta = buscarCancionPorId(arbol->der, ID);
            }
            else
            {
                rta = buscarCancionPorId(arbol->izq, ID);
            }
        }
    }

    return rta;
}



nodoArbolCanc * buscarCancionPorNombre (nodoArbolCanc * arbol, char nombre[50])
{
    nodoArbolCanc * rta = NULL;

    if (arbol != NULL)
    {
        if (strcmpi (nombre,arbol->c.nombre) == 0)
        {
            rta = arbol;
        }
        else
        {
            rta = buscarCancionPorNombre(arbol->izq, nombre);

            if (rta == 0)
            {
                rta = buscarCancionPorNombre(arbol->der, nombre);
            }
        }
    }

    return rta;
}
