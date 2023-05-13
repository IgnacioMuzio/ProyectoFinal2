#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    int anio;
    char genero[50];
    char cantantes[3][50];
    int estado;
} stCancion;

typedef struct
{
 stCancion c;
 struct nodoArbolCanc * izq;
 struct nodoArbolCanc * der;
} nodoArbolCanc;

nodoArbolCanc * inicArbol();
nodoArbolCanc * crearNodoArbol (stCancion dato);
nodoArbolCanc * insertarNodoArbol (nodoArbolCanc * arbol, stCancion dato);
void preOrden (nodoArbolCanc * arbol);
void inOrder (nodoArbolCanc * arbol);
void postOrden (nodoArbolCanc * arbol);
void mostrarCancion (stCancion dato);
nodoArbolCanc* borrarUnNodoArbolPorId(nodoArbolCanc* arbol, int ID);
nodoArbolCanc * nodoMasIzquierda(nodoArbolCanc * arbol) ;
nodoArbolCanc * nodoMasDerecha(nodoArbolCanc* arbol);
int esHoja(nodoArbolCanc * arbol);
int esGrado1(nodoArbolCanc * arbol);
nodoArbolCanc * buscarCancionPorId (nodoArbolCanc * arbol, int ID);
nodoArbolCanc * buscarCancionPorNombre (nodoArbolCanc * arbol, char nombre[50]);



#endif // ARBOL_H_INCLUDED
