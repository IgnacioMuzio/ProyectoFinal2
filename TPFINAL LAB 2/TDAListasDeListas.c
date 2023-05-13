#include <stdio.h>
#include <stdlib.h>
#include "TDAListasDeListas.h"
#include "string.h"
#define ArchUs "archivoDeUsuarios.dat"

nodoListaUsers * inicListaU ()
{
    return NULL;
}


nodoListaUsers * pasarDeArchivoToLDL (nodoListaUsers * lista)
{
    stUsuario usuario;

    FILE * archivo = fopen(ArchUs,"rb");
    if(archivo != NULL)
    {
        while(fread(&usuario,sizeof(stUsuario), 1, archivo) > 0)
        {
            lista = alta(lista, usuario);
        }

        fclose(archivo);
    }

    return lista;
}


nodoListaUsers * alta (nodoListaUsers * lista, stUsuario usuario)
{
    nodoListaUsers * usuarioEncontrado = buscarUsuario(lista, usuario);

    if(usuarioEncontrado == NULL)
    {
        nodoListaUsers * nuevoUsuario = crearNodoUsuario(usuario);
        lista = agregarAlPrincipio(lista, nuevoUsuario);
        usuarioEncontrado = lista;
    }

    usuarioEncontrado->playlist = ArregloALista(usuarioEncontrado->playlist, usuario);

    return lista;
}

nodoListaUsers * agregarAlPrincipio(nodoListaUsers *lista,nodoListaUsers * nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nuevoNodo->sig=lista;
        lista=nuevoNodo;
    }

    return lista;
}


nodoI * ArregloALista (nodoI * lista, stUsuario usuario)
{
    int i=0;
    nodoI * aux;

    while(usuario.arrId[i] != -1)
    {
        crearNodo(&aux, usuario, i);
        agregarFinal(&lista,aux);
        i++;
    }

    return lista;
}


nodoListaUsers * buscarUsuario (nodoListaUsers * lista, stUsuario usuario)
{
    nodoListaUsers * seg = lista;
    nodoListaUsers * usuarioEncontado = NULL;
    int flag = 0;

        while(seg!= NULL && flag == 0)
        {
            if(seg->user.id == usuario.id)
            {
                usuarioEncontado = seg;
                flag=1;
            }
            seg = seg->sig;
        }

    return usuarioEncontado;
}


nodoListaUsers * crearNodoUsuario (stUsuario usuario)
{
    nodoListaUsers * aux = (nodoListaUsers*)malloc(sizeof(nodoListaUsers));

    strcpy(aux->user.apellidoYnombres,usuario.apellidoYnombres);
    strcpy(aux->user.celular, usuario.celular);
    strcpy(aux->user.contrasenia, usuario.contrasenia);
    aux->user.estado = usuario.estado;
    aux->user.id = usuario.id;
    strcpy(aux->user.mail, usuario.mail);
    inicLista(&(aux->playlist)); ///PREGUNTAR
    aux->sig = NULL;

    return aux;
}


void mostrarLDL (nodoListaUsers * lista, nodoArbolCanc * arbol)
{
    nodoListaUsers * seg = lista;

    while (seg != NULL)
    {
        printf("Id: %i \n", seg->user.id);
        printf("Apellido y nombre: %s \n", seg->user.apellidoYnombres);
        printf("Mail: %s \n", seg->user.mail);
        printf("Celular: %s \n", seg->user.celular);
        printf("Contrasenia: %s \n", seg->user.contrasenia);
        printf("Estado: %i \n", seg->user.estado);
        printf("\n");

        recorrerYmostrar(seg->playlist, arbol);

        seg = seg->sig;
    }
}


void recorrerYmostrar (nodoI * lista, nodoArbolCanc * arbol)
{
    nodoI * aux = lista;

    while(aux != NULL)
    {
        nodoArbolCanc * arbolAux = buscarCancionPorId(arbol,aux->dato);
        mostrarUnNodo(arbolAux);
        aux = aux->sig;
    }
}


void mostrarUnNodo (nodoArbolCanc * aux)
{
    puts("-------------------------");
    printf("Id: %i \n", aux->c.id);
    printf("Nombre: %s \n", aux->c.nombre);
    printf("Anio: %i \n", aux->c.anio);
    printf("Genero: %s \n", aux->c.genero);
    printf("Cantante: %s \n", aux->c.cantantes[0]); ///PREGUNTAR
    printf("Estado: %i \n", aux->c.estado);
    puts("-------------------------\n");
}

