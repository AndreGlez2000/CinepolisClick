#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

typedef struct usuario
{
    char *username;
    char *nombre;
    char *apellido;
    char *edad;
    char *password;
}usuario;

typedef struct arreglo_users
{
    usuario *users;
    int numero_usuarios;

}arreglo_users;

int main(void)
{
    int i,j;
    //***************************************************************************

    //SIMULACION DE DATOS OBTENIDOS DE UN ARCHIVO
    char *arreglo_datos[ARRAY_SIZE] = {"siralbert","Alberto","Betancourt","27","12345","siredgar","Edgar","Juarez","27","678910"};
    for(i=0;i<ARRAY_SIZE;i++)
    {
        printf("\n\r %s",arreglo_datos[i]);
    }

    //***************************************************************************

    //CREAR ARREGLO DE ESTRUCTURA USUARIO
    arreglo_users arr_users;
    arr_users.users=NULL;
    arr_users.numero_usuarios=0;
    usuario *aux=NULL; //PARA EL REALLOC
    int n=0;
    for(i=0;i<ARRAY_SIZE;i++)
    {
        if(arr_users.users==NULL && i%5==0)
        {
            //CREAR EL ESPACIO EN MEMORIA PARA EL PRIMER USUARIO
            n++;
            arr_users.users=malloc(sizeof(usuario)*n);
            arr_users.users[n-1].username     =arreglo_datos[i];
            (arr_users.users+n-1)->username   =arreglo_datos[i];  //OTRA MANERA DE ASIGNAR
        }
        else if(i%5==0)
        {
            //AGREGAR MAS USUARIOS
            n++;
            aux=NULL;
            while(aux==NULL)
            {
                aux=realloc(arr_users.users,sizeof(usuario)*n);
            }
            arr_users.users[n-1].username     =arreglo_datos[i];
            (arr_users.users+n-1)->username   =arreglo_datos[i]; //OTRA MANERA DE ASIGNAR
        }
        else if(i%5==1)
        {
            //Nombre
            arr_users.users[n-1].nombre     =arreglo_datos[i];
            (arr_users.users+n-1)->nombre   =arreglo_datos[i]; //OTRA MANERA DE ASIGNAR
        }
        else if(i%5==2)
        {
            //Apellido
            arr_users.users[n-1].apellido     =arreglo_datos[i];
            (arr_users.users+n-1)->apellido   =arreglo_datos[i]; //OTRA MANERA DE ASIGNAR

        }
        else if(i%5==3)
        {
            //Edad
            arr_users.users[n-1].edad     =arreglo_datos[i];
            (arr_users.users+n-1)->edad   =arreglo_datos[i]; //OTRA MANERA DE ASIGNAR
        }
        else if(i%5==4)
        {
            //Password
            arr_users.users[n-1].password     =arreglo_datos[i];
            (arr_users.users+n-1)->password   =arreglo_datos[i]; //OTRA MANERA DE ASIGNAR
        }
    }
    arr_users.numero_usuarios = n;

    //***************************************************************************

    printf("\n\n\n\r ");
    //IMPRESION DE LOS DATOS DEL
    for(i=0;i<arr_users.numero_usuarios;i++)
    {
        printf("\n\r USUARIO [%d]",i+1);
        printf("\n\r %s",arr_users.users[i].username);
        printf("\n\r %s",arr_users.users[i].nombre);
        printf("\n\r %s",arr_users.users[i].apellido);
        printf("\n\r %s",arr_users.users[i].edad);
        printf("\n\r %s",arr_users.users[i].password);
    }
    printf("\n\n\n\r ");
    return 0;
}