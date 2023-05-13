#ifndef TDACANCIONES_H_INCLUDED
#define TDACANCIONES_H_INCLUDED
#include "arbol.h"

typedef struct
{
 int dato;
 struct nodoI * sig;
} nodoI;

typedef struct
{
    int id;
    char apellidoYnombres [50];
    char mail [50];
    char celular[30] ;
    char contrasenia[30];
    int arrId[30];
    int estado;
} stUsuario;

void inicLista (nodoI ** lista);
void crearNodo (nodoI ** aux, stUsuario usuario, int i);
void agregarFinal(nodoI ** lista, nodoI * nuevoNodo);
nodoI * buscarUltimo(nodoI * lista);
///void agregarEnOrdenPorNombre (nodoListaUsers ** lista,nodoListaUsers * nuevoNodo);


#endif // TDACANCIONES_H_INCLUDED
