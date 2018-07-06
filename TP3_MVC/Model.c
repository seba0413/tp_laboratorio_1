#include "Model.h"

#define CANTIDAD_PELICULAS 100

static EMovie arrayPeliculas[CANTIDAD_PELICULAS];

EMovie* model_getMovies(void)
{

    return arrayPeliculas;
}

int model_getMoviesLen(void)
{
    return CANTIDAD_PELICULAS;
}

int model_buscarPosicionLibre()
{
    int i;
    int retorno = -1;

        for(i=0;i<CANTIDAD_PELICULAS;i++)
        {
            if(arrayPeliculas[i].flagOcupado == 0)
            {
                retorno =  i;
                break;
            }
        }

    return retorno;
}

int model_generarProximoId()
{
    int i, maxId=-2;

    for(i=0;i<CANTIDAD_PELICULAS;i++)
    {
        if((arrayPeliculas[i].flagOcupado) == 1 || (arrayPeliculas[i].flagOcupado) == 0)
        {
            if((arrayPeliculas[i].idPelicula) > maxId || maxId == -2)
                maxId = arrayPeliculas[i].idPelicula;
        }
    }
    return maxId+1;
}



void model_cargarMovie(EMovie movie, int index) {

    arrayPeliculas[index] = movie;
}

int model_buscarIndicePorId(int id)
{
    int i;
    int retorno = -1;
    {
        for(i=0;i<CANTIDAD_PELICULAS;i++)
            {

                if(arrayPeliculas[i].idPelicula == id)        //(strcmp(array[i].a, array[i].dni) == 0)
                {
                    retorno = i;
                    break;
                }

            }
    }
    return retorno;
}
