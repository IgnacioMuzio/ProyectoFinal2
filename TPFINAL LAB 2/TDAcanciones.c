#include <stdio.h>
#include <stdlib.h>
#include "TDAcanciones.h"
#include <string.h>

void inicLista (nodoI ** lista)
{
    *lista=NULL;
}

void crearNodo (nodoI ** aux, stUsuario usuario, int i)
{
    (*aux) = (nodoI*) malloc(sizeof(nodoI));

    (*aux)->dato = usuario.arrId[i];
    (*aux)->sig = NULL;

}

void agregarFinal(nodoI ** lista, nodoI * nuevoNodo)
{
    if(*lista == NULL)
    {
        *lista = nuevoNodo;
    }
    else
    {
        nodoI * ultimo = buscarUltimo(*lista);
        ultimo->sig = nuevoNodo;
    }
}

nodoI * buscarUltimo(nodoI * lista)
{
    nodoI * seg = lista;

    if(seg)
        while(seg->sig != NULL)
        {
            seg = seg->sig;
        }

    return seg;
}





//nodoArbol* buscarPorNombre (nodoArbol * arbol, char nombre[]) ///Inciso 5
//{
//    nodoArbol* rta = NULL;
//
//    if (arbol != NULL)
//    {
//        if (strcmpi (nombre,arbol->dato.nombre) == 0) // si el nombre está en el primer nodo
//        {
//            rta = arbol; // lo guardo en rta para retornarlo
//        }
//        else
//        {
//            rta = buscarPorNombre(arbol->izq, nombre); // si no, sigo buscando por izq
//            if (rta == 0) // si sigue sin aparecer
//            {
//                rta = buscarPorNombre(arbol->der, nombre); // lo busco por derecha
//            }
//        }
//    }
//
//    return rta;
//}

//void cargarListaOrdenada (nodoC ** lista)
//{
//    char control='s';
//    nodoC * nuevoNodo;
//    stCancion aux;
//    do
//    {
//        aux=cargarCancion(aux);
//        crearNodo(aux,&nuevoNodo);
//        agregarEnOrdenPorNombre(lista,nuevoNodo);
//        printf("Desea agregar otro? s/n\n");
//        fflush(stdin);
//        scanf("%c",&control);
//    }
//    while(control=='s');
//}
//
///*void mostrarCancion (stCancion a)
//{
//    printf("ID:%d\n",a.id);
//    printf("NOMBRE DE CANCION: %s\n",a.nombre);
//    printf("ANIO:%d\n",a.anio);
//    printf("GENERO:%s\n",a.genero);
//    printf("CANTANTES/BANDA:%s\n",a.cantantes);
//    printf("ESTADO:%d\n",a.estado);
//    printf("--------------------------------------------------------\n");
//}*/
//
//void mostrarLista (nodoC * lista)
//{
//    nodoC*seg=lista;
//    if(seg==NULL)
//        printf("Lista vacia\n");
//    while(seg!=NULL)
//    {
//        mostrarCancion(seg->c);
//        seg=seg->sig;
//    }
//}
//
//void borrarBuscado (nodoC ** lista, int dato)
//{
//    if ((*lista)!=NULL)
//    {
//        if ((*lista)->c.id==dato)
//        {
//            nodoC *aBorrar=*lista;
//            *lista=(*lista)->sig;
//            free(aBorrar);
//            printf("Se borro correctamente\n");
//        }
//        else
//        {
//        nodoC *ante=NULL;
//        nodoC *seg=(*lista);
//        while(seg!=NULL && seg->c.id!=dato)
//        {
//            ante=seg;
//            seg=seg->sig;
//        }
//        if(seg!=NULL)
//        {
//            if(ante!=NULL)
//            {
//            ante->sig=seg->sig;
//            free(seg);
//            }
//            else
//            {
//                (*lista)=NULL;
//                free(seg);
//            }
//            printf("Se borro correctamente\n");
//        }
//        else
//            printf("No se encontro o la lista esta vacia\n");
//        }
//    }
//}
//
//void borrarBuscadoComp (nodoC ** lista)
//{
//    int dato;
//    printf("Ingrese un numero a borrar\n");
//    scanf("%i",&dato);
//    borrarBuscado(lista, dato);
//    printf("lista con buscado borrado\n");
//    mostrarLista(*lista);
//}
//
//int cantCanciones(nodoC *lista,int rta)
//{
//    rta=0;
//    if(lista!=NULL)
//    {
//        rta=cantCanciones(lista->sig, rta)+1;
//    }
//    return rta;
//}
