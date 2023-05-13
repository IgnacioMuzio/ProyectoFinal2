#ifndef TDALISTASDELISTAS_H_INCLUDED
#define TDALISTASDELISTAS_H_INCLUDED
#include "arbol.h"
#include "TDAcanciones.h"

typedef struct
{
 stUsuario user;
 nodoI * playlist;
 struct nodoListaUsers * sig;
} nodoListaUsers;

nodoListaUsers * inicListaU ();
nodoListaUsers * pasarDeArchivoToLDL (nodoListaUsers * lista);
nodoListaUsers * alta (nodoListaUsers * lista, stUsuario usuario);
nodoI * ArregloALista (nodoI * lista, stUsuario usuario);
nodoListaUsers * buscarUsuario (nodoListaUsers * lista, stUsuario usuario);
nodoListaUsers * crearNodoUsuario (stUsuario usuario);
nodoListaUsers * agregarAlPrincipio (nodoListaUsers * lista, nodoListaUsers * nuevoNodo);
void mostrarLDL (nodoListaUsers * lista, nodoArbolCanc * arbol);
void recorrerYmostrar (nodoI * lista, nodoArbolCanc * arbol);
void mostrarUnNodo (nodoArbolCanc * aux);



#endif // TDALISTASDELISTAS_H_INCLUDED
