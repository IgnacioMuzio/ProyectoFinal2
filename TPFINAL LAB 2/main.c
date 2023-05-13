#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include "TDAcanciones.h"
#include "TDAListasDeListas.h"

/*#define archivoCanciones "archivoCanciones.dat"
#define nombreDeMiArchivoUsuario "archivoDeUsuarios.dat"*/

const char archivoCanciones[30]="archivoCanciones.dat";
const char archivoUsuarios[40]="archivoDeUsuarios.dat";
const char archivoAdmin[40]="archivoDeAdmin.dat";



/*typedef struct
{
    int id;
    char nombre[50];
    int anio;
    char genero[50];
    char cantantes[3][50];
    int estado;
} cancion;*/

typedef struct {
 stCancion dato;
 struct nodoC*sig;
}nodoC;


typedef struct     ///usuario
{
    int id;
    char apellidoYnombres [50];
    char mail [50];
    char celular[30] ;
    char contrasenia[30];
    int estado;
} stAdmin;

nodoC* agregarEnOrdenPorNombreNodoC (nodoC * lista,nodoC*nuevoNodo);
nodoC* deArbolAListaOrdXNombre (nodoArbolCanc*arbol,nodoC*lista);
nodoC* agregarEnOrdenPorLanzamientoNodoC (nodoC * lista,nodoC*nuevoNodo);
nodoC* deArbolAListaOrdXLanzamiento (nodoArbolCanc*arbol,nodoC*lista);
nodoC* crearNodoC (stCancion c);



nodoC*iniclistaNodoC()
{
    return NULL;
}



nodoC * deArbolAListaCiertoGenero (nodoArbolCanc*arbol,nodoC*lista,char genero[])
{
  if(arbol!=NULL)
    {
        if(strcmpi(arbol->c.genero,genero) == 0 && arbol->c.estado == 1)
        {
            nodoC * nuevoNodo;
            nuevoNodo=crearNodoC(arbol->c);
            lista=agregarEnOrdenPorNombreNodoC(lista,nuevoNodo);
        }



        lista=deArbolAListaCiertoGenero(arbol->der,lista,genero);

        lista=deArbolAListaCiertoGenero(arbol->izq,lista,genero);
    }
    return lista;
}
nodoC* deArbolAListaOrdXNombre (nodoArbolCanc*arbol,nodoC*lista)
{

    if(arbol!=NULL)
    {
        nodoC * nuevoNodo;
        nuevoNodo=crearNodoC(arbol->c);


        lista=deArbolAListaOrdXNombre(arbol->der,lista);

        if(arbol->c.estado == 1)
        {
            lista=agregarEnOrdenPorNombreNodoC(lista,nuevoNodo);
        }

        lista=deArbolAListaOrdXNombre(arbol->izq,lista);
    }

return lista;
}
nodoC* deArbolAListaOrdXLanzamiento (nodoArbolCanc*arbol,nodoC*lista)
{

    if(arbol!=NULL)
    {
        nodoC * nuevoNodo;
        nuevoNodo=crearNodoC(arbol->c);


        lista=deArbolAListaOrdXLanzamiento(arbol->der,lista);

        if (arbol->c.estado == 1)
        {
            lista=agregarEnOrdenPorLanzamientoNodoC(lista,nuevoNodo);
        }

        lista=deArbolAListaOrdXLanzamiento(arbol->izq,lista);
    }

return lista;
}

void mostrarUsuarios(char nombre_archivo[])
{
    stUsuario a;
    FILE*archi;
    archi=fopen(nombre_archivo,"rb");
    if(archi!=NULL)
    {
        while(fread(&a,sizeof(stUsuario),1,archi)>0)
        {
            mostrarUsuario(a);
        }
        fclose(archi);
    }
}
nodoC* crearNodoC (stCancion c)
{
    nodoC*nuevoNodo;
    nuevoNodo=(nodoC*)malloc(sizeof(nodoC));
    nuevoNodo->dato=c;

    return nuevoNodo;
}
nodoC* agregarEnOrdenPorNombreNodoC (nodoC * lista,nodoC*nuevoNodo)
{


    if(lista==NULL || strcmpi(nuevoNodo->dato.nombre,lista->dato.nombre)<0)
    {
        nuevoNodo->sig=lista;
        lista=nuevoNodo;
    }
    else
    {
        nodoC*ante=NULL;
        nodoC*seg=lista;
        while(seg!=NULL && strcmpi(nuevoNodo->dato.nombre,seg->dato.nombre)>=0)
        {
            ante=seg;
            seg=seg->sig;
        }
        ante->sig=nuevoNodo;
        nuevoNodo->sig=seg;
    }
    return lista;
}
nodoC* agregarEnOrdenPorLanzamientoNodoC (nodoC * lista,nodoC*nuevoNodo)
{


    if(lista==NULL || nuevoNodo->dato.anio < lista->dato.anio)
    {
        nuevoNodo->sig=lista;
        lista=nuevoNodo;
    }
    else
    {
        nodoC*ante=NULL;
        nodoC*seg=lista;
        while(seg!=NULL && nuevoNodo->dato.anio > lista->dato.anio )
        {
            ante=seg;
            seg=seg->sig;
        }
        ante->sig=nuevoNodo;
        nuevoNodo->sig=seg;
    }
    return lista;
}
void agregarEnOrdenPorNombre (nodoListaUsers ** lista,nodoListaUsers * nuevoNodo)
{

    if(*lista==NULL || strcmpi(nuevoNodo->user.apellidoYnombres,(*lista)->user.apellidoYnombres)<0)
    {
        nuevoNodo->sig=*lista;
        (*lista)=nuevoNodo;
    }
    else
    {
        nodoListaUsers*ante=NULL;
        nodoListaUsers*seg=*lista;
        while(seg!=NULL && strcmpi(nuevoNodo->user.apellidoYnombres,seg->user.apellidoYnombres)>=0)
        {
            ante=seg;
            seg=seg->sig;
        }
        ante->sig=nuevoNodo;
        nuevoNodo->sig=seg;
    }
}
void crearNodoParaListado (stUsuario aux,nodoListaUsers**nuevoNodo)
{
    (*nuevoNodo)=(nodoListaUsers*)malloc(sizeof(nodoListaUsers));
    (*nuevoNodo)->user=aux;
    (*nuevoNodo)->sig=NULL;
}
void listadoAdmin(char nombre_archivo[])
{
    FILE* archi;
    stUsuario aux;
    nodoListaUsers*listado=inicListaU();
    nodoListaUsers*auxi;
    archi=fopen(nombre_archivo,"rb");
    if(archi!=NULL)
    {
        while(fread(&aux,sizeof(stUsuario),1,archi)>0)
        {
            crearNodoParaListado(aux,&auxi);
            agregarEnOrdenPorNombre(&listado,auxi);

        }

        nodoListaUsers*seg=listado;

        while(seg!=NULL)
        {
            mostrarUsuario(seg->user);
            seg=seg->sig;
        }
        fclose(archi);
    }
}

void altaDeUsuario (char nombre_archivo[], char nombreABuscar[])
{
    int flag=0;
    int choice=0;
    stUsuario a;
    FILE*archi;
    char usuarioADarDeAlta[30];
    archi=fopen(nombre_archivo,"r+b");
    if(archi!=NULL)
    {

        printf("Que usuario desea dar de ALTA?\n");
        fflush(stdin);
        gets(usuarioADarDeAlta);

        while ((flag == 0) && (fread(&a,sizeof(stUsuario), 1, archi) > 0))
        {
            if (strcmpi(a.apellidoYnombres,usuarioADarDeAlta) == 0)
            {
                flag = 1;     // corta lectura, se encontró el nombre
            }
        }
        mostrarUsuario(a);
        printf("   1-Dar de ALTA \n");
        printf("   2-Continuar en el estado actual \n");
        scanf("%d",&choice);
        if(choice==1)
        {
            a.estado=1;
            printf(" El ususrio fue dado de ALTA!!!\n");
        }
        else
        {
            printf(" No se modifico el estado del usuario...\n");
        }

        fseek(archi,sizeof(stUsuario)*(-1), SEEK_CUR); // muevo ind de pos 1 bloque de datos para atrás (evito escribir el sig al buscado)
        fwrite(&a, sizeof(stUsuario), 1, archi);

        fclose(archi);
    }
    mostrarUsuario(a);

}
void bajaDelUsuario (char nombre_archivo[], char nombreABuscar[])
{
    FILE * archi;
    stUsuario a;
    int flag = 0;
    int choice = 0;


    archi = fopen(nombre_archivo, "r+b");
    if (archi != NULL)
    {
        while ((flag == 0) && (fread(&a,sizeof(stUsuario), 1, archi) > 0))
        {
            if (strcmpi(a.apellidoYnombres,nombreABuscar) == 0)
            {
                flag = 1;     // corta lectura, se encontró el nombre
            }
        }
        mostrarUsuario(a);
        printf("   1-dar de baja \n");
        printf("   2-continuar en el estado actual \n");
        scanf("%d",&choice);
        if(choice==1)
        {
            a.estado=0;
            printf(" el ususrio fue dado de baja!!!\n");
        }
        else
        {
            printf(" no se modifico el estado del usuario...\n");
        }

        fseek(archi,sizeof(stUsuario)*(-1), SEEK_CUR); /// muevo ind de pos 1 bloque de datos para atrás (evito escribir el sig al buscado)
        fwrite(&a, sizeof(stUsuario), 1, archi); /// se escriben las modificaciones ingresadas en el bloque que corresponde

        fclose(archi);
    }
    mostrarUsuario(a);
    return a;
}
void menuPrincipal()
{
    char control='s';
    char caso='s';
}

void menuAdministrador()
{
    int casos=0;
    int control='n';
    char nombreAbuscar[30];


    do
    {
        printf("[1]AGREGAR CANCIONES PARA LOS USUARIOS\n");
        printf("[2]ALTA DE USUARIOS\n");
        printf("[3]BAJA DE USUARIOS\n");
        printf("[4]MOSTRAR USUARIOS\n");
        printf("{5}MOSTRAR CANCIONES\n");
        fflush(stdin);
        scanf("%d",&casos);
        switch(casos)
        {
        case 1:
            cargarCancionesEnArchivo(archivoCanciones);
            break;
        case 2:
            printf("\t ALTA del sistema\n");
            mostrarUsuarios(archivoUsuarios);
            printf("Que usuario desea dar de ALTA???...\n");
            fflush(stdin);
            gets(nombreAbuscar);

            altaDeUsuario(archivoUsuarios,nombreAbuscar);

            /// mostrarUsuario(a);
            break;
        case 3:
            printf("\t baja del sistema\n");
            mostrarUsuarios(archivoUsuarios);
            printf("Que usuario desea dar de baja???...\n");
            fflush(stdin);
            gets(nombreAbuscar);

            bajaDelUsuario (archivoUsuarios,nombreAbuscar);

            ///mostrarUsuario(a)
            break;
        case 4:
            mostrarUsuarios(archivoUsuarios);
            break;
        case 5:
            mostrarArchivoCancion(archivoCanciones);
            break;


        }
        printf("Quiere volver al menu de ADMINISTRADOR?...s/n\n");
        fflush(stdin);
        scanf("%c",&control);
        system("cls");
    }
    while(control=='s');
}


int contarElementosEnArchivoCancion(FILE*archi)
{
    long int cantidad=0;
    if(archi!=NULL)
    {
        fseek(archi,0,SEEK_END);
        cantidad=ftell(archi)/sizeof(stCancion);

    }
    return cantidad;
}
int contarElementosEnArchivoUsuario(FILE*archi)
{
    int cantidad=0;
    if(archi!=NULL)
    {
        fseek(archi,0,SEEK_END);
        cantidad=ftell(archi)/sizeof(stUsuario);

    }
    return cantidad;
}
int contarElementosEnArchivoAdmin(FILE*archi)
{
    int cantidad=0;
    if(archi!=NULL)
    {
        fseek(archi,0,SEEK_END);
        cantidad=ftell(archi)/sizeof(stAdmin);

    }
    return cantidad;
}
nodoArbolCanc* cargarArbolDesdeArchivo (nodoArbolCanc*arbol,char nombre_archivo[30])
{
    stCancion dato;
    FILE*archi;
    archi=fopen(nombre_archivo,"rb");
    int cantCancionArch=contarElementosEnArchivoCancion(archi);
    if(archi!=NULL)
    {

        fseek(archi,sizeof(stCancion)*(cantCancionArch/2),SEEK_SET);

        while (fread(&dato,sizeof(stCancion),1,archi) >0 )
        {
            arbol=insertarNodoArbol(arbol,dato);
        }
        fseek(archi,0,SEEK_SET);
        int i=0;
        while(i<cantCancionArch/2 )
        {
            fread(&dato,sizeof(stCancion),1,archi);
            arbol=insertarNodoArbol(arbol,dato);
            i++;
        }

        fclose(archi);

    }
    return arbol;
}
stCancion cargarCancion()
{
    char control='s';
    int f=0;
    stCancion a;

    printf("NOMBRE cancion\n");
    fflush(stdin);
    gets(&a.nombre);
    printf("ANIO CANCION\n");
    scanf("%d",&a.anio);
    printf("GENERO\n");
    fflush(stdin);
    gets(&a.genero);
    printf("CANTANTE\n");
    while(control=='s' && f<3)
    {
        fflush(stdin);
        gets(&a.cantantes[f]);
        printf("tiene mas cantantes???? s/n\n");
        fflush(stdin);
        scanf("%c",&control);
        f++;
    }

    return a;
}
void cargarCancionesEnArchivo (char nombre_archivo[30])
{
    stCancion aux;
    char control='s';
    FILE*archi;
    archi=fopen(nombre_archivo,"ab");
    if(archi!=NULL)
    {
        do
        {
            aux=cargarCancion();
            aux.id=1+contarElementosEnArchivoCancion(archi);

            fwrite(&aux,sizeof(stCancion),1,archi);

            printf("Desea seguir cargando el archivo ? s/n\n ");
            fflush(stdin);
            scanf("%c",&control);
        }
        while(control=='s');


        fclose(archi);
    }
}

void mostrarArchivoCancion (char nombre_archivo[30])
{
    stCancion dato;
    FILE*archi;
    archi=fopen(nombre_archivo,"rb");
    if(archi!=NULL)
    {


        while (fread(&dato,sizeof(stCancion),1,archi) >0 )
        {
            mostrarCancion(dato);
        }

        fclose(archi);

    }
}
void mostrarUsuario(stUsuario aux)
{

    printf(" DATOS DEL USUARIO : \n ");
    printf("NOMBRE--------------: %s\n ",aux.apellidoYnombres);
    printf("ID-----------------: %d\n ",aux.id);
    printf("EMAIL--------------: %s\n ",aux.mail);
    printf("CELULAR-------------: %s\n ",aux.celular);
    printf("CONTRASENIA----------: %s\n ",aux.contrasenia);
    printf("ESTADO--------------: %d\n ",aux.estado);
    printf("ARREGLO DE IDS:");
    int i=0;
    while(i<contarEnArrIds(aux.arrId))
    {
        printf(" %d-",aux.arrId[i]);
        i++;
    }

    printf(" \n---------------------------------------------------\n ");

}
void mostrarAdmin(stAdmin aux)
{

    printf(" DATOS DEL USUARIO : \n ");
    printf("NOMBRE--------------: %s\n ",aux.apellidoYnombres);
    printf("ID-----------------: %d\n ",aux.id);
    printf("EMAIL--------------: %s\n ",aux.mail);
    printf("CELULAR-------------: %s\n ",aux.celular);
    printf("CONTRASENIA----------: %s\n ",aux.contrasenia);
    printf("ESTADO--------------: %d\n ",aux.estado);
    printf(" ---------------------------------------------------\n ");

}
void mostrarArchivoUsuario (char nombre_archivo[30])
{
    stUsuario dato;
    FILE*archi;
    archi=fopen(nombre_archivo,"rb");
    if(archi!=NULL)
    {


        while (fread(&dato,sizeof(stUsuario),1,archi) >0 )
        {
            mostrarUsuario(dato);
        }

        fclose(archi);

    }
}
void mostrarArchivoAdmin (char nombre_archivo[30])
{

    stAdmin dato;
    FILE*archi;
    archi=fopen(nombre_archivo,"rb");
    if(archi!=NULL)
    {


        while (fread(&dato,sizeof(stAdmin),1,archi) >0 )
        {
            mostrarAdmin(dato);
        }

        fclose(archi);

    }
}
void cargarUnUsuario(char nombre_archivo[30])
{
    FILE*archi;
    stUsuario a;
    char control='s';
    char control2='s';
    int i=0;
    char mail[30];
    int flagMail=0;

    archi=fopen(nombre_archivo,"ab");
    if(archi!=NULL)
    {
        do
        {
            i=0;
            inicArregloIds(a.arrId);


            printf("NOMBRE Y APELLIDO\n");
            fflush(stdin);
            gets(a.apellidoYnombres);
            do
            {
                printf("EMAIL\n");
                scanf("%s",&mail);
                flagMail=verificarMailUsuario(nombre_archivo,mail);
                if(flagMail==0)
                {
                    strcpy(a.mail,mail);
                }
                else
                {
                    printf("El mail ya existe,vuelva a intentarlo...\n");
                }
            }
            while(flagMail==1);
            printf("CELULAR\n");
            fflush(stdin);
            gets(a.celular);
            printf("CONTRASENIA\n");
            fflush(stdin);
            gets(a.contrasenia);

            a.estado=1;

            do
            {
                printf("Ingrese id\n");
                scanf("%d",&a.arrId[i]);
                i++;
                printf("Queres cargar otro id?s/n\n");
                fflush(stdin);
                scanf("%c",&control2);
            }while(control2=='s');

            printf("Quiere cargar mas usuarios??? s/n\n");
            fflush(stdin);
            scanf("%c",&control);

            a.id=1+contarElementosEnArchivoUsuario(archi);
            fwrite(&a,sizeof(stUsuario),1,archi);
            ///Se autoincrementa saliendo y volviendo a entrar en el bucle
        }
        while(control=='s');
        fclose(archi);
    }
}

int contarEnArrIds (int arreId[])
{
    int j=0;
    for(int i=0;i<30;i++)
    {
        if(arreId[i]>0)
        {
            j++;
        }
    }
    return j;
}
void inicArregloIds (int a[])
{
    int i;

    for(i=0;i<30;i++)
    {
        a[i]=-1;
    }

}
void cargarUnAdmin(char nombre_archivo[30])
{
    FILE*archi;
    stAdmin a;
    char control='s';
    char mail[30];
    int flagMail=0;

    archi=fopen(nombre_archivo,"ab");
    if(archi!=NULL)
    {
        do
        {

            printf("NOMBRE Y APELLIDO\n");
            fflush(stdin);
            gets(a.apellidoYnombres);
            do
            {
                printf("EMAIL\n");
                scanf("%s",&mail);
                flagMail=verificarMailAdmin(nombre_archivo,mail);
                if(flagMail==0)
                {
                    strcpy(a.mail,mail);
                }
                else
                {
                    printf("El mail ya existe,vuelva a intentarlo...\n");
                }
            }
            while(flagMail==1);
            printf("CELULAR\n");
            fflush(stdin);
            gets(a.celular);
            printf("CONTRASENIA\n");
            fflush(stdin);
            gets(a.contrasenia);

            a.estado=1;


            printf("Quiere cargar mas usuarios??? s/n\n");
            fflush(stdin);
            scanf("%c",&control);

            a.id=1+contarElementosEnArchivoAdmin(archi);
            fwrite(&a,sizeof(stAdmin),1,archi);
            ///Se autoincrementa saliendo y volviendo a entrar en el bucle
        }
        while(control=='s');
        fclose(archi);
    }
}

int verificarMailUsuario(char nombre_archivo[30],char mail[30])
{
    int flag=0;
    stUsuario a;
    FILE*archi;
    archi=fopen(nombre_archivo,"rb");
    if(archi!=NULL)
    {
        while(fread(&a,sizeof(stUsuario),1,archi)>0)
        {
            if(strcmpi(a.mail,mail)==0)
            {
                flag=1;
            }
        }
        fclose(archi);
    }
    return flag;
}
int verificarMailAdmin(char nombre_archivo[30],char mail[30])
{
    int flag=0;
    stAdmin a;
    FILE*archi;
    archi=fopen(nombre_archivo,"rb");
    if(archi!=NULL)
    {
        while(fread(&a,sizeof(stAdmin),1,archi)>0)
        {
            if(strcmpi(a.mail,mail)==0)
            {
                flag=1;
            }
        }
        fclose(archi);
    }
    return flag;
}
/*nodoListaUsers* pasarArchivoAListaUsuarios(char nombre_archivo[30],nodoListaUsers*lista)
{
    stUsuario aux;
    FILE*archi;
    archi=fopen(nombre_archivo,"rb");
    if(archi!=NULL)
    {
        while(fread(&aux,sizeof(stUsuario),1,archi)>0)
        {
            nodoListaUsers*nuevoNodo;
            nuevoNodo=crearNodo(aux);
            lista=agregarPrimero(lista,nuevoNodo);
        }
        fclose(archi);
    }
    return lista;
}
*/
/*
int cargarCancionArrDeId(char nombre_archivo[30],stUsuario a, int val, int id, int validoslista)
{
    FILE *Fi;
    Fi=fopen(nombre_archivo,"r+b");
    int i=contarCancionesMiLista(nombre_archivo,id);
    int flag=0;

    char aux[30];
    char control='s';
    if (Fi!=NULL)
    {
        do
        {
            printf("Ingrese un nombre de una cancion para agregar a la lista: ");
            fflush(stdin);
            gets(aux);
            stCancion can=buscarcan(c,val,aux);
            fseek(Fi,0,SEEK_SET);
            while (flag == 0 &&fread(&a, sizeof(stUsuario), 1, Fi) > 0)
            {
                if (a.id==id)
                {
                    a.miLista[i]=can;
                    a.miLista[i].estado=1;
                    flag=1;
                    i++;


                }
            }
            fseek(Fi,sizeof(stUsuario)*(-1), SEEK_CUR);
            fwrite (&a,sizeof(stUsuario),1,Fi);
            flag=0;
            printf("SE A GUARDADO %s en Mi Lista!!!\n",can.nombre);
            printf ("Desea cargar otra cancion? s/n :");
            fflush(stdin);
            scanf("%c",&control);
            fseek(Fi,sizeof(stUsuario)*(-1), SEEK_CUR);
        }
        while (control == 's'&& i<50);
        fclose(Fi);
    }
    return i;
}*/

void mostrarListaNodoC (nodoC*lista)
{
    nodoC*seg=lista;

    while(seg!=NULL)
    {
        mostrarCancion(seg->dato);
        seg=seg->sig;
    }
}
int main()
{
   nodoArbolCanc*arbol=inicArbol();
   nodoC*lista=iniclistaNodoC();
   arbol=cargarArbolDesdeArchivo(arbol,archivoCanciones);

   char genero[30];
   printf("INGRESE EL GENERO QUE DESEA BUSCAR\n");
   fflush(stdin);
   gets(genero);
   lista=deArbolAListaCiertoGenero(arbol,lista,genero);
   mostrarListaNodoC(lista);




    return 0;
}
