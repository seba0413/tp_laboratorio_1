#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "getsValids.h"

int importarPeliculas(EMovie* movie,int lenPeliculas)
{
    int retorno = -1, cantidadLeida;
    FILE* pArchivo;
    pArchivo = fopen("movies.dat","rb");
    if(pArchivo!=NULL)
    {
        cantidadLeida = fread(movie,sizeof(EMovie),lenPeliculas,pArchivo);
        printf("Cantidad leida:%d\n",cantidadLeida);
        if(cantidadLeida > 0)
            retorno = 0;
        fclose(pArchivo);
    }

    return retorno;
}


int autoSavePeliculas(EMovie* movie,int lenPeliculas)

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

void generarPagina(EMovie *movie,char *nombre, int lenPeliculas)
{
    int i;
    FILE *pArchivo;
    pArchivo=fopen(nombre, "w");

    if(pArchivo == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        fprintf(pArchivo,"<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>");

        for(i=0; i<lenPeliculas; i++)
        {
            if(movie[i].flagOcupado == 1)
            {
                fprintf(pArchivo,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero: %s</li><li>Puntaje: %.1f</li><li>Duracion:%d</li></ul><p>%s</p></article>", movie[i].linkImagen, movie[i].titulo, movie[i].genero, movie[i].puntaje, movie[i].duracion, movie[i].descripcion);
            }
        }
        fprintf(pArchivo,"</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");
    }
    fclose(pArchivo);
    printf("Pagina guardada con exito\n"); //////
}



int pelicula_init(EMovie *movie, int len)
{
    int i;
    int retorno = -1;
    if (movie != NULL && len >0)
    {
        for(i=0;i<len;i++)
        {
            movie[i].flagOcupado = 0;
            movie[i].idPelicula = -1;
        }
        retorno = 0;
    }
    return retorno;
}









int pelicula_baja(EMovie *movie,int len)
{
    int retorno = -1;
    int bufferId;
    char bConfirm[50];

    pelicula_print(movie,len,1);
    get_validInt("\nIngrese ID a dar de baja\n","\nIngrese solo numeros\n",&bufferId,0,9999,2);
    int indexPan = model_buscarIndicePorId(bufferId);


    if (movie != NULL && len > 0)
    {
        if (indexPan != -1)
        {
            if (!get_validLetras("\nConfirma borrar la pelicula? S/N?\n","\nValor invalido\n","\nSolo S o N\n",bConfirm,2,3));
            {
                if (bConfirm[0] == 'S' || bConfirm[0]=='s')
                {
                    movie[indexPan].flagOcupado = 0;
                    retorno = 0;
                    printf("\nSe ha realizado la baja\n\n");
                }
                else
                {
                    printf("\nNo se han realizado bajas\n\n");
                }
            }
        }
        else
        {
            printf("\nEl ID elegido no existe\n");
        }
    }
    return retorno;
}

void pelicula_print(EMovie *movie, int len, int estado)
{
    int i;
    printf("Id\t%20s\t%20s\t%s\t%s\t%25s\n","Titulo","Genero","Duracion","Puntaje","Descripcion");
    printf("---------------------------------------------------------------------------------------------------------\n");
    for(i=0; i<len; i++)
    {
        if ((movie[i].flagOcupado) == estado)
        {
            printf("%d\t%20s\t%20s\t%8d\t%7.1f\t%22.20s...\n", movie[i].idPelicula, movie[i].titulo, movie[i].genero, movie[i].duracion, movie[i].puntaje,movie[i].descripcion);
        }
    }
}
