#include "Controller.h"
#include "Movie.h"
#include "Model.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int controller_alta(char titulo[], char genero[], int duracion, char descripcion[],  float puntaje, char* linkImagen)
{
    int retorno  = -1;
    EMovie movie_aux;
    int indexVacio = model_buscarPosicionLibre();
    if(indexVacio >= 0)
    {
        int idNuevo = model_generarProximoId();
        strncpy(movie_aux.titulo,titulo,20);
        strncpy(movie_aux.genero,genero,20);
        movie_aux.duracion = duracion;
        strcpy(movie_aux.descripcion,descripcion);
        movie_aux.puntaje = puntaje;
        strcpy(movie_aux.linkImagen,linkImagen);
        movie_aux.idPelicula = idNuevo;
        movie_aux.flagOcupado = 1;
        retorno = 0;

    }

    model_cargarMovie(movie_aux, indexVacio);

    printf("\nPelicula dada de alta");
    return retorno;
}

void controller_modificar(char titulo[], char genero[], int duracion, char descripcion[],  float puntaje, char* linkImagen, int id, int index)
{
    EMovie movie_aux;

    strncpy(movie_aux.titulo,titulo,20);
    strncpy(movie_aux.genero,genero,20);
    movie_aux.duracion = duracion;
    strcpy(movie_aux.descripcion,descripcion);
    movie_aux.puntaje = puntaje;
    strcpy(movie_aux.linkImagen,linkImagen);
    movie_aux.idPelicula = id;
    movie_aux.flagOcupado = 1;

    model_cargarMovie(movie_aux, index);
}

