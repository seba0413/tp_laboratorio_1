#include <stdio.h>
#include <stdlib.h>
#include "MovieDAO.h"
#include "Movie.h"

int movieDAO_guardarPeliculas(EMovie* movie,int lenPeliculas)

{
    int retorno = -1;
    int cantidadEscrita;
    FILE* pArchivo;

    pArchivo = fopen("movies.dat","wb");
    if(pArchivo==NULL)
    {
        printf("\nEl archivo no puede ser abierto");
    }
    else
    {
        printf("Escribo archivo. cantidad %d\n",lenPeliculas);
        cantidadEscrita = fwrite(movie,sizeof(EMovie),lenPeliculas,pArchivo);
        printf("Escribio %d\n",cantidadEscrita);
        if(cantidadEscrita > 0)
            retorno = 0;
        fclose(pArchivo);
    }
    return retorno;
}
