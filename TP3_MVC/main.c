#include <stdio.h>
#include <stdlib.h>
#include "Model.h"
#include "View.h"
#include "funciones.h"
#include "HTMLBuilder.h"
#include "MovieDAO.h"

int main()
{
    char seguir='s';
    int opcion=0;


    while(seguir=='s')
    {
        printf("\n1- Agregar pelicula\n");
        printf("2- Modificar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                 view_pedirDatosAltaMovie();
                 movieDAO_guardarPeliculas(model_getMovies(),model_getMoviesLen());
                break;
            case 2:
                  view_modificar();
                  movieDAO_guardarPeliculas(model_getMovies(),model_getMoviesLen());
               break;
            case 3:
                 htmlBuilder_generarPagina(model_getMovies(),"template/index.html",model_getMoviesLen());
                break;
            case 4:
                movieDAO_guardarPeliculas(model_getMovies(),model_getMoviesLen());
                seguir = 'n';

                break;
        }
    }

    return 0;
}
