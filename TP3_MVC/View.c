#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "Movie.h"
#include "View.h"
#include "getsValids.h"
#include "Model.h"
#include "funciones.h"

int view_pedirDatosAltaMovie()
{
    int retorno = -1;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    float puntaje;
    char linkImagen[50];

        if (!get_validAlfaNumerico("\nIngrese Titulo\n", "\nTitulo invalido\n", "\n20 Caracteres Maximo\n",titulo, 20,3))
        {
            if (!get_validLetras("\nIngrese genero\n","\nGenero invalido\n","\n20 Caracteres Maximo\n",genero,20,3))
            {
                if(!get_validInt("\nIngrese duracion en minutos\n","\nError:\n",&duracion,0,999,2))
                {
                    if (!get_validAlfaNumerico("\nIngrese descripcion\n","Error", "\nMaximo 1000 caracteres\n",descripcion,50,3))
                    {
                        if(!get_validFloat("\nIngrese puntaje\n","\nIngrese puntaje entre 1 y 10:\n",&puntaje,1,10,2))
                        {
                            if (!get_validStringSinEspacios("\nIngrese link de imagen\n", "\nlink invalido\n", "\nMaximo 1000 caracteres\n" ,linkImagen,50,3))
                            {
                                controller_alta(titulo,genero,duracion,descripcion,puntaje,linkImagen);
                            }

                        }
                    }
                }
            }
        }
    else
    {
        printf("\nNo se pudo realizar el alta\n");
    }
    return retorno;
}

int view_modificar()
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    float puntaje;
    char linkImagen[50];
    int id;

    int retorno = -1;
    int bufferId;

    get_validInt("\nIngrese ID de pelicula a modificar\n","\nERROR\n",&bufferId,0,9999,2);
    int index = model_buscarIndicePorId(bufferId);
    EMovie* arrayAux = model_getMovies();

    char seguir='s';

        if (index != -1)
        {
            strcpy(titulo,arrayAux[index].titulo);
            strcpy(genero,arrayAux[index].genero);
            duracion = arrayAux[index].duracion;
            strcpy(descripcion,arrayAux[index].descripcion);
            puntaje = arrayAux[index].puntaje;
            strcpy(linkImagen,arrayAux[index].linkImagen);
            id = arrayAux[index].idPelicula;

            while(seguir=='s')
            {
                if (!get_validInt("\nIngrese campo a modificar:\n  Titulo\t[0]\n  Genero\t[1]\n  Duracion\t[2]\n  Puntaje\t[3]\n  Descripcion\t[4]\n  Link Poster\t[5]\n  Terminar\t[6]\n","\nIngrese solo numeros\n",&bufferId,0,6,2));
                {
                    switch(bufferId)
                    {
                    case 0:
                        if (!get_validAlfaNumerico("\nIngrese Titulo\n", "\nTitulo invalido\n", "\n20 Caracteres Maximo\n",titulo,20,3))
                            //strncpy(movie.titulo,titulo,20);
                        break;
                    case 1:
                        if (!get_validLetras("\nIngrese genero\n", "\nGenero invalido\n","\n20 Caracteres Maximo\n",genero,20,3))
                            //strncpy(movie.genero,genero,20);
                        break;
                    case 2:
                        if (!get_validInt("\nIngrese duracion en minutos\n","\nError:\n",&duracion,0,999,2))
                            //movie.duracion = duracion;
                        break;
                    case 3:
                        if (!get_validFloat("\nIngrese puntaje\n","\nIngrese puntaje entre 1 y 10:\n",&puntaje,0,10,2))
                            //movie.puntaje = puntaje;
                        break;
                    case 4:
                        if (!get_validAlfaNumerico("\nIngrese descripcion\n","ERROR", "\nMaximo 1000 caracteres\n",descripcion,3,500))
                            //strncpy(movie.descripcion,descripcion,500);
                        break;
                    case 5:
                        if (!get_validAlfaNumerico(linkImagen, "\nIngrese link de imagen\n","ERROR", "\nlink invalido\n",500,3))
                            //strncpy(movie.linkImagen,linkImagen,500);
                        break;
                    case 6:
                        seguir = 'n';
                        break;
                    }
                }
            }
            controller_modificar(titulo, genero, duracion, descripcion, puntaje,linkImagen,id,index);
            retorno = 0;
        }
        else
        {
            printf("El ID elegido no existe\n");
            system("pause");
        }

    return retorno;
}

