#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"
#include "ArrayList.h"


int agregarPelicula(EMovie movie)
{
    char auxTitulo[20];
    char auxGenero[20];
    int auxDuracion;
    char auxDescripcion[50];
    int auxPuntaje;
    char auxLinkImagen[50];
    int retorno = -1;

    FILE* fp = fopen("peliculas.dat", "ab");
    if(fp == NULL)
        return retorno;

    if(!getStringAlfanumerico(auxTitulo,20,"\nIngrese titulo: \n","\nTitulo invalido\n",2))
    {
        if(!getStringAlfanumerico(auxGenero,20,"\nIngrese genero: \n","\nGenero invalido\n",2))
        {
            if(!getValidInt("\nIngrese duracion en minutos: \n", "\nDuracion invalida\n", &auxDuracion,0,500,2))
            {
                if(!getStringAlfanumerico(auxDescripcion,50,"\nIngrese descripcion: \n","\nDescripcion invalida\n",2))
                {
                    if(!getValidInt("\nIngrese puntaje: \n", "\nPuntaje invalida\n", &auxPuntaje,0,10,2))
                    {
                        if(!getStringAlfanumerico(auxLinkImagen,50,"\nIngrese link de la imagen: \n","\nLink invalido\n",2))
                        {

                            strcpy(movie.titulo,auxTitulo);
                            strcpy(movie.genero,auxGenero);
                            movie.duracion = auxDuracion;
                            strcpy(movie.descripcion,auxDescripcion);
                            movie.puntaje = auxPuntaje;
                            movie.isEmpty = 0;
                            strcpy(movie.linkImagen,auxLinkImagen);

                            fwrite(&movie, sizeof(EMovie), 1, fp);
                            retorno = 0;
                        }
                    }
                }
            }
        }
    }
    fclose(fp);

    return retorno;
}

int borrarPelicula(EMovie movie)
{
    int retorno = -1;
    char tituloIngresado[20];

    FILE* fp = fopen("peliculas.dat", "r+b");
    if(fp == NULL)
        return retorno;

    getStringAlfanumerico(tituloIngresado,20,"\nIngrese el titulo de la pelicula a eliminar\n","\nTitulo invalido\n",2);

    fread(&movie, sizeof(EMovie), 1, fp);
    while(!feof(fp))
    {
        if(!strcmp(movie.titulo, tituloIngresado))
        {
            movie.isEmpty = 1;
            int pos = ftell(fp) - sizeof(EMovie);
            fseek(fp, pos, SEEK_SET);
            fwrite(&movie, sizeof(EMovie), 1, fp);
            retorno = 0;
            break;
        }
        fread(&movie, sizeof(EMovie), 1, fp);
    }
    fclose(fp);

    return retorno;
}

int modificarPelicula(EMovie movie)
{
    int retorno = -1;
    char tituloIngresado[20];
    char auxTitulo[20];
    char auxGenero[20];
    int auxDuracion;
    char auxDescripcion[50];
    int auxPuntaje;
    char auxLinkImagen[50];

    FILE* fp = fopen("peliculas.dat", "r+b");
    if(fp == NULL)
        return retorno;

    getStringAlfanumerico(tituloIngresado,20,"\nIngrese el titulo de la pelicula a modificar\n","\nTitulo invalido\n",2);

    fread(&movie, sizeof(EMovie), 1, fp);
    while(!feof(fp))
    {
        if(!strcmp(movie.titulo, tituloIngresado))
        {
            if(!getStringAlfanumerico(auxTitulo,20,"\nIngrese nuevo titulo: \n","\nTitulo invalido\n",2))
            {
                if(!getStringAlfanumerico(auxGenero,20,"\nIngrese nuevo genero: \n","\nGenero invalido\n",2))
                {
                    if(!getValidInt("\nIngrese nueva duracion en minutos: \n", "\nDuracion invalida\n", &auxDuracion,0,500,2))
                    {
                        if(!getStringAlfanumerico(auxDescripcion,50,"\nIngrese nueva descripcion: \n","\nDescripcion invalida\n",2))
                        {
                            if(!getValidInt("\nIngrese nuevo puntaje: \n", "\nPuntaje invalida\n", &auxPuntaje,0,10,2))
                            {
                                if(!getStringAlfanumerico(auxLinkImagen,50,"\nIngrese nuevo link de la imagen: \n","\nLink invalido\n",2))
                                {
                                    strcpy(movie.titulo,auxTitulo);
                                    strcpy(movie.genero,auxGenero);
                                    movie.duracion = auxDuracion;
                                    strcpy(movie.descripcion,auxDescripcion);
                                    movie.puntaje = auxPuntaje;
                                    strcpy(movie.linkImagen,auxLinkImagen);

                                    int pos = ftell(fp) - sizeof(EMovie);
                                    fseek(fp, pos, SEEK_SET);
                                    fwrite(&movie, sizeof(EMovie), 1, fp);
                                    retorno = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        else
            break;
    }

    fclose(fp);

    return retorno;
}


void generarPagina(EMovie* lista, int limite, char* nombre)
{
    int i;
    FILE* pFile = fopen(nombre,"w");

    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];

    EMovie movie;

    if(lista != NULL && limite > 0)
    {
        fprintf(pFile,"<!DOCTYPE html>\n<!-- Template by Quackit.com -->\n<html lang='en'>\n<head>\n    <meta charset='utf-8'>\n    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n    <meta name='viewport' content='width=device-width, initial-scale=1'>\n    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n    <title>Lista peliculas</title>\n    <!-- Bootstrap Core CSS -->\n    <link href='css/bootstrap.min.css' rel='stylesheet'>\n    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n    <link href='css/custom.css' rel='stylesheet'>\n    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n    <!--[if lt IE 9]>\n        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'>\n        </script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n    <![endif]-->\n</head>\n<body>\n    <div class='container'>\n        <div class='row'>\n\n");
        for(i = 0; i < 100; i++)
        {
            movie = lista[i];
            strcpy(titulo, movie.titulo);
            strcpy(genero, movie.genero);
            strcpy(descripcion, movie.descripcion);
            strcpy(linkImagen, movie.linkImagen);
            puntaje = movie.puntaje;
            duracion = movie.duracion;
            fprintf(pFile,"            <article class='col-md-4 article-intro'>\n                <a href='#'>\n                    <img class='img-responsive img-rounded' src= %s alt=''>\n                </a>\n                <h3>\n                    <a href='#'>%s</a>\n                </h3>\n                <ul>\n                    <li>Genero:%s</li>\n                    <li>Puntaje:%d</li>\n                    <li>Duracion:%d</li>\n                </ul>\n                <p>%s.</p>\n            </article>\n\n",linkImagen,titulo,genero,puntaje,duracion,descripcion);
        }
        fprintf(pFile,"\n</div>\n<!-- /.row -->\n</div>\n<!-- /.container -->\n<!-- jQuery -->\n<script src='js/jquery-1.11.3.min.js'></script>\n<!-- Bootstrap Core JavaScript -->\n<script src='js/bootstrap.min.js'></script>\n<!-- IE10 viewport bug workaround -->\n<script src='js/ie10-viewport-bug-workaround.js'></script>\n<!-- Placeholder Images -->\n<script src='js/holder.min.js'></script>\n</body>\n</html>");
    }
    fclose(pFile);
}


