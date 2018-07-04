#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"
#include "ArrayList.h"

#define LIMITE 100

void leerArchivo(EMovie* peliculas, char* fileName);

int main()
{
    char seguir='s';
    int opcion=0;

    EMovie peliculas[100];
    EMovie pelicula;

    while(seguir=='s')
    {
        printf("\n1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                if(!agregarPelicula(pelicula))
                    printf("\nPelicula agregada\n");
                else
                    printf("\nNo se pudo agregar la pelicula\n");
                break;
            case 2:
                if(!borrarPelicula(pelicula))
                    printf("\nPelicula borrada\n");
                else
                    printf("\nNo se pudo borrar la pelicula\n");
                break;
            case 3:
                leerArchivo(peliculas, "peliculas.dat");
                generarPagina(peliculas, LIMITE, "archivoPeliculas.bin");
                printf("\nArchivo generado\n");
               break;
            case 4:
                seguir = 'n';
                break;
            case 5:
                if(!modificarPelicula(pelicula))
                    printf("\nPelicula modificada\n");
                else
                    printf("\nNo se pudo modificar la pelicula\n");
                break;
        }
    }

    return 0;
}

void leerArchivo(EMovie* peliculas, char* fileName)
{
    int i = 0;
    EMovie pelicula;

    FILE* fp = fopen(fileName, "rb");
    if (fp == NULL)
        return NULL;

    fread(&pelicula, sizeof(EMovie),1,fp);
    while(!feof(fp))
    {
        peliculas[i] = pelicula;
        fread(&pelicula, sizeof(EMovie),1,fp);
        i++;
    }
    fclose(fp);
}
